
/**
 * @file map.c
 *
 * @copyright This file is a part of the project yarac and is distributed under GNU GPLv3 license
 * that should have been included with the project.
 * If not, see https://www.gnu.org/licenses/gpl-3.0.en.html
 *
 * @author jorisb14
 *
 * @date 2022-12-19
 */

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct Hash64
{
	unsigned long long value;
};

struct Hash64 hash64(
	const unsigned char* const bytes,
	const unsigned long long length)
{
	assert(bytes != NULL);
	assert(length > 0);

	// Setting up hash blocks
	struct Hash64 hash = {0};
	register unsigned long long state = 0;

	#define PRIMARY1 ((const unsigned char)13)
	#define PRIMARY2 ((const unsigned char)31)

	for (unsigned long long i = 0; i < length; ++i)
	{
		const unsigned char value = *(const unsigned char* const)(bytes + i);
		state += ((value + (state ^ PRIMARY2)) % PRIMARY2) & PRIMARY1;
	}

	hash.value = state;
	return hash;
}

struct Core_Containers_Map_Node
{
	const char* key;
	unsigned long long length;
	void* value;
	struct Core_Containers_Map_Node* next;
};

struct Core_Containers_Map
{
	struct Core_Containers_Map_Node** nodes;
	unsigned long long capacity;
	unsigned long long count;
};

signed char W_Core_Containers_Map_create(
	struct Core_Containers_Map** const map,
	const unsigned long long capacity)
{
	*map = (struct Core_Containers_Map*)malloc(sizeof(struct Core_Containers_Map));
	(*map)->nodes = (struct Core_Containers_Map_Node**)malloc(capacity * sizeof(struct Core_Containers_Map_Node*));
	assert((*map)->nodes != NULL);
	(*map)->capacity = capacity;
	(*map)->count = 0;
	return 1;
}

signed char W_Core_Containers_Map_destroy(
	const struct Core_Containers_Map* const * const map)
{
	for (unsigned long long i = 0; i < (*map)->capacity; ++i)
	{
		if ((*map)->nodes[i] == NULL)
		{
			continue;
		}

		for (const struct Core_Containers_Map_Node* node = (*map)->nodes[i]; node->next != NULL;)
		{
			const struct Core_Containers_Map_Node* current = node;
			node = node->next;
			free((void*)current);
		}
	}

	free((void*)((*map)->nodes));
	free((void*)(*map));
	return 1;
}

signed char W_Core_Containers_Map_set(
	struct Core_Containers_Map* const * const map,
	const char* const key,
	const unsigned long long length,
	void* value)
{
	// Generate index using hash64() function
	const struct Hash64 hash = hash64((const unsigned char* const)key, length);
	// fprintf(stdout, "push: index=%llu\n", hash.value);
	// TODO: remove -----------^

	// Check if the index is out of bounds. If so, allocate more memory to the map.
	if (hash.value >= (*map)->capacity)
	{
		const unsigned long long newCapacity = hash.value;
		(*map)->nodes = (struct Core_Containers_Map_Node**)realloc((void*)((*map)->nodes), newCapacity);
		assert((*map)->nodes != NULL); // TODO: should be IF, not assert check!
		(*map)->capacity = newCapacity;
	}

	// Check if there are existing nodes that hold provided key
	if ((*map)->nodes[hash.value] != NULL)
	{
		struct Core_Containers_Map_Node* current = (*map)->nodes[hash.value];

		for (; current != NULL; current = current->next)
		{
			if (length == current->length && strncmp(key, current->key, length) == 0)
			{
				current->value = value;
				return 1;
			}

			if (current->next == NULL)
			{
				break;
			}
		}

		// Create the new node
		struct Core_Containers_Map_Node* node = (struct Core_Containers_Map_Node*)malloc(sizeof(struct Core_Containers_Map_Node));
		assert(node != NULL); // TODO: should be an IF here, not assert!
		*node = (struct Core_Containers_Map_Node) { .key = (const char*)key, .length = length, .value = value, .next = NULL };

		// Insert new node
		current->next = node;
		++((*map)->count);
		return 1;
	}

	// Create the new node
	struct Core_Containers_Map_Node* node = (struct Core_Containers_Map_Node*)malloc(sizeof(struct Core_Containers_Map_Node));
	assert(node != NULL); // TODO: should be an IF here, not assert!
	*node = (struct Core_Containers_Map_Node) { .key = (const char*)key, .length = length, .value = value, .next = NULL };

	// Insert new node
	(*map)->nodes[hash.value] = node;
	++((*map)->count);
	return 1;
}

signed char W_Core_Containers_Map_get(
	struct Core_Containers_Map* const * const map,
	const char* const key,
	const unsigned long long length,
	void** value)
{
	const struct Hash64 hash = hash64((const unsigned char* const)key, length);
	// fprintf(stdout, "get: index=%llu\n", hash.value);
	// TODO: remove -----------^

	if (hash.value >= (*map)->capacity)
	{
		// Failure
		return 0;
	}

	struct Core_Containers_Map_Node* node = (*map)->nodes[hash.value];

	if (node == NULL)
	{
		return 0;
	}

	for (; node != NULL; node = node->next)
	{
		if (length == node->length && strncmp(key, node->key, length) == 0)
		{
			*value = (void*)(node->value);
			return 1;
		}
	}

	*value = NULL;
	return 0;
}

int main(
	void)
{
	struct Core_Containers_Map* map = NULL;

	W_Core_Containers_Map_create(&map, 4);

	static const char* keys[5] = { "ka", "ka", "kc", "kd", "ke" };
	static const char* values[5] = { "va", "vb", "vc", "vd", "ve" };

	for (unsigned int i = 0; i < 5; ++i)
	{
		W_Core_Containers_Map_set(&map, keys[i], 2, (&(values[i])));
		fprintf(stdout, "capacity=%llu\n", map->capacity);
	}

	fprintf(stdout, "1\n");

	for (unsigned int i = 0; i < 5; ++i)
	{
		const char* value = NULL;
		W_Core_Containers_Map_get(&map, keys[i], 2, (void**)(&value));
		fprintf(stdout, "%s\n", value);
	}

	fprintf(stdout, "2\n");

	W_Core_Containers_Map_destroy((const struct Core_Containers_Map* const * const)&map);

	return 1;
}
