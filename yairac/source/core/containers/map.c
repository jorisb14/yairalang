
/**
 * @file map.c
 *
 * @copyright This file is a part of the project yarac and is distributed under GNU GPLv3 license
 * that should have been included with the project.
 * If not, see https://www.gnu.org/licenses/gpl-3.0.en.html
 *
 * @author jorisb14
 *
 * @date 2022-12-18
 */

#include <core/containers/map.h>

#include <core/memory.h> // For memory related functions: malloc, realloc, free, and NULL.

// TODO: include logger!

#include <string.h>

/**
 * @addtogroup containers
 * 
 * @{
 */

// TODO: consider renaming to namespace-standard-like name!
// TODO: document!
struct Hash64
{
	unsigned long long value;
};

// TODO: consider renaming to namespace-standard-like name!
// TODO: document!
static signed char Hash64_hash(
	struct Hash64* const hash,
	const unsigned char* const bytes,
	const unsigned long long length,
	signed char* const succeeded);

// TODO: consider renaming to namespace-standard-like name!
// TODO: add log for the internal crash!
// Previous log: "function Hash64_hash(...) returned with internal failure!"
// TODO: document!
#define W_Hash64_hash(_inmacro_hash, _inmacro_bytes, _inmacro_length, _inmacro_succeeded, _inmacro_internalFailCallback, _inmacro_logicalFailCallback, _inmacro_successCallback) \
	{ \
		if (!Hash64_hash((_inmacro_hash), (_inmacro_bytes), (_inmacro_length), (_inmacro_succeeded))) \
		{ \
			_inmacro_internalFailCallback \
		} \
		else \
		{ \
			if (!(*(_inmacro_succeeded))) \
			{ \
				_inmacro_logicalFailCallback \
			} \
			else \
			{ \
				_inmacro_successCallback \
			} \
		} \
	}

signed char Core_Containers_Map_create(
	struct Core_Containers_Map** const map,
	const unsigned long long capacity,
	signed char* const succeeded)
{
	if (succeeded == NULL)
	{
		// TODO: log invalid `succeeded` parameter error!
		return 0;
	}

	if (map == NULL)
	{
		// TODO: log invalid `map` parameter error!
		*succeeded = 0;
		return 0;
	}

	*succeeded = 0;

	*map = NULL;

	W_Core_Memory_malloc((const void* const * const)map, sizeof(struct Core_Containers_Map), succeeded,
	{
		*succeeded = 0;
		return 0;
	},
	{
		// TODO: log failed map's allocation!
		// *succeeded = 0;
		return 1;
	},
	{});

	(*map)->nodes = NULL;

	W_Core_Memory_malloc((const void* const * const)(&((*map)->nodes)), capacity * sizeof(struct Core_Containers_Map_Node*), succeeded,
	{
		*succeeded = 0;
		return 0;
	},
	{
		// TODO: log failed map's nodes allocation!
		// *succeeded = 0;
		return 1;
	},
	{});

	(*map)->capacity = capacity;
	(*map)->count = 0;

	*succeeded = 1;
	return 1;
}

signed char Core_Containers_Map_destroy(
	const struct Core_Containers_Map* const * const map,
	signed char* const succeeded)
{
	if (succeeded == NULL)
	{
		// TODO: log invalid `succeeded` parameter error!
		return 0;
	}

	if (map == NULL)
	{
		// TODO: log invalid `map` parameter error!
		*succeeded = 0;
		return 0;
	}

	if (*map == NULL)
	{
		// TODO: log invalid `map`'s deref parameter error!
		*succeeded = 0;
		return 0;
	}

	*succeeded = 0;

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

			W_Core_Memory_free((const void* const * const)(&current), succeeded,
			{
				*succeeded = 0;
				return 0;
			},
			{
				// TODO: log failed to deallocate map's node error!
				// *succeeded = 0;
				return 1;
			},
			{});
		}
	}

	W_Core_Memory_free((const void* const * const)(&((*map)->nodes)), succeeded,
	{
		*succeeded = 0;
		return 0;
	},
	{
		// TODO: log failed to deallocate map's nodes error!
		// *succeeded = 0;
		return 1;
	},
	{});

	W_Core_Memory_free((const void* const * const)map, succeeded,
	{
		*succeeded = 0;
		return 0;
	},
	{
		// TODO: log failed to deallocate map error!
		// *succeeded = 0;
		return 1;
	},
	{});

	*succeeded = 1;
	return 1;
}

signed char Core_Containers_Map_get(
	struct Core_Containers_Map* const * const map,
	const char* const key,
	const unsigned long long length,
	const void* const * const value,
	signed char* const succeeded)
{
	if (succeeded == NULL)
	{
		// TODO: log invalid `succeeded` parameter error!
		return 0;
	}

	if (map == NULL)
	{
		// TODO: log invalid `map` parameter error!
		*succeeded = 0;
		return 0;
	}

	if (*map == NULL)
	{
		// TODO: log invalid `map`'s deref parameter error!
		*succeeded = 0;
		return 0;
	}

	if (key == NULL)
	{
		// TODO: log invalid `key` parameter error!
		*succeeded = 0;
		return 0;
	}

	if (value == NULL)
	{
		// TODO: log invalid `value` parameter error!
		*succeeded = 0;
		return 0;
	}

	*succeeded = 0;

	const void** const inner = (const void** const)value;
	*inner = NULL;

	struct Hash64 hash = {0};

	W_Hash64_hash(&hash, (const unsigned char* const)key, length, succeeded,
	{
		*succeeded = 0;
		return 0;
	},
	{
		// TODO: log failed to hash provided key error!
		// *succeeded = 0;
		return 1;
	},
	{});

	if (hash.value >= (*map)->capacity)
	{
		*succeeded = 0;
		return 1;
	}

	struct Core_Containers_Map_Node* node = (*map)->nodes[hash.value];

	if (node == NULL)
	{
		*succeeded = 0;
		return 1;
	}

	for (; node != NULL; node = node->next)
	{
		if (length == node->length && strncmp(key, node->key, length) == 0)
		{
			*inner = (void*)(node->value);
			*succeeded = 1;
			return 1;
		}
	}

	*inner = NULL;
	*succeeded = 0;
	return 1;
}

signed char Core_Containers_Map_set(
	struct Core_Containers_Map* const * const map,
	const char* const key,
	const unsigned long long length,
	const void* const * const value,
	signed char* const succeeded)
{
	if (succeeded == NULL)
	{
		// TODO: log invalid `succeeded` parameter error!
		return 0;
	}

	if (map == NULL)
	{
		// TODO: log invalid `map` parameter error!
		*succeeded = 0;
		return 0;
	}

	if (*map == NULL)
	{
		// TODO: log invalid `map`'s deref parameter error!
		*succeeded = 0;
		return 0;
	}

	if (key == NULL)
	{
		// TODO: log invalid `key` parameter error!
		*succeeded = 0;
		return 0;
	}

	if (value == NULL)
	{
		// TODO: log invalid `value` parameter error!
		*succeeded = 0;
		return 0;
	}

	if (*value == NULL)
	{
		// TODO: log invalid `value`'s deref parameter error!
		*succeeded = 0;
		return 0;
	}

	*succeeded = 0;

	struct Hash64 hash = {0};

	W_Hash64_hash(&hash, (const unsigned char* const)key, length, succeeded,
	{
		*succeeded = 0;
		return 0;
	},
	{
		// TODO: log failed to hash provided key error!
		// *succeeded = 0;
		return 1;
	},
	{});

	if (hash.value >= (*map)->capacity)
	{
		const unsigned long long newCapacity = hash.value;

		W_Core_Memory_realloc((const void** const)(&((*map)->nodes)), newCapacity, succeeded,
		{
			*succeeded = 0;
			return 0;
		},
		{
			// TODO: log failed to reallocate memory for a map!
			// *succeeded = 0;
			return 1;
		},
		{});

		(*map)->capacity = newCapacity;
	}

	if ((*map)->nodes[hash.value] != NULL)
	{
		struct Core_Containers_Map_Node* current = (*map)->nodes[hash.value];

		for (; current != NULL; current = current->next)
		{
			if (length == current->length && strncmp(key, current->key, length) == 0)
			{
				current->value = (void*)value;
				return 1;
			}

			if (current->next == NULL)
			{
				break;
			}
		}

		struct Core_Containers_Map_Node* node = NULL;

		W_Core_Memory_malloc((const void* const * const)(&node), sizeof(struct Core_Containers_Map_Node), succeeded,
		{
			*succeeded = 0;
			return 0;
		},
		{
			// TODO: log failed to allocate memory block for list's node!
			// *succeeded = 0;
			return 1;
		},
		{});

		*node = (struct Core_Containers_Map_Node) { .key = (const char*)key, .length = length, .value = (void*)value, .next = NULL };

		current->next = node;
		++((*map)->count);
		*succeeded = 1;
		return 1;
	}

	struct Core_Containers_Map_Node* node = NULL;

	W_Core_Memory_malloc((const void* const * const)(&node), sizeof(struct Core_Containers_Map_Node), succeeded,
	{
		*succeeded = 0;
		return 0;
	},
	{
		// TODO: log failed to allocate memory block for list's node!
		// *succeeded = 0;
		return 1;
	},
	{});

	*node = (struct Core_Containers_Map_Node) { .key = (const char*)key, .length = length, .value = (void*)value, .next = NULL };

	(*map)->nodes[hash.value] = node;
	++((*map)->count);

	*succeeded = 1;
	return 1;
}

static signed char Hash64_hash(
	struct Hash64* const hash,
	const unsigned char* const bytes,
	const unsigned long long length,
	signed char* const succeeded)
{
	if (succeeded == NULL)
	{
		// TODO: log invalid `succeeded` parameter error!
		return 0;
	}

	if (hash == NULL)
	{
		// TODO: log invalid `hash` parameter error!
		*succeeded = 0;
		return 0;
	}

	*succeeded = 0;

	unsigned long long state = 0;
	#define PRIMARY1 ((const unsigned char)13)
	#define PRIMARY2 ((const unsigned char)31)

	for (unsigned long long i = 0; i < length; ++i)
	{
		const unsigned char value = *(const unsigned char* const)(bytes + i);
		state += ((value + (state ^ PRIMARY2)) % PRIMARY2) & PRIMARY1;
	}

	hash->value = state;
	#undef PRIMARY1
	#undef PRIMARY2

	*succeeded = 1;
	return 1;
}

/**
 * @}
 */
