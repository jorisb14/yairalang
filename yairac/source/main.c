
/**
 * @file main.c
 *
 * @copyright This file is a part of the project yarac and is distributed under GNU GPLv3 license
 * that should have been included with the project.
 * If not, see https://www.gnu.org/licenses/gpl-3.0.en.html
 *
 * @author jorisb14
 *
 * @date 2022-12-17
 */

#include <core/containers/vector.h>
#include <core/containers/wrappers/vector.h>

#include <core/containers/list.h>
#include <core/containers/wrappers/list.h>

#include <core/containers/map.h>
#include <core/containers/wrappers/map.h>

// C standard library headers
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void Map_dump(
	struct Core_Containers_Map** map)
{
	assert(map != NULL);

	fprintf(stdout, "map with capacity=%llu:\n", (*map)->capacity);

	for (unsigned long long i = 0; i < (*map)->capacity; ++i)
	{
		const struct Core_Containers_Map_Node* node = (*map)->nodes[i];

		while (node != NULL)
		{
			fprintf(stdout, "    key: %.*s, value: %s\n",
				(signed int)node->key.length, node->key.buffer,
				(const char*)node->value);
			node = node->next;
		}
	}

	fprintf(stdout, "\n");
}

int main(
	int argc,
	char** argv)
{
	(void)(argc);
	(void)(argv);
	fprintf(stdout, "Hello from yairac!\n");

	signed char succeeded = 0;
	struct Core_Containers_Map* map = NULL;

	W_Core_Containers_Map_create(&map, 4, &succeeded, { }, { }, { });

	#define pairsCount 4
	static const char* keys[pairsCount] = { "a", "b", "c", "a" };
	static const char* values[pairsCount] = { "hello from a!", "hello from b!", "hello from c!", "hello from a! (clone)" };

	for (unsigned long long i = 0; i < pairsCount; ++i)
	{
		W_Core_Containers_Map_set(&map, keys[i], strlen(keys[i]),
			(const void* const * const)(&(values[i])), &succeeded, { }, { }, { });

		Map_dump(&map);
	}

	for (unsigned long long i = 0; i < pairsCount; ++i)
	{
		const char* val = NULL;

		W_Core_Containers_Map_get(&map, keys[i], strlen(keys[i]),
			(const void* const * const)(&val), &succeeded, { }, { }, { });

		fprintf(stdout, "%s -> %s\n", keys[i], val);
	}

	W_Core_Containers_Map_destroy((const struct Core_Containers_Map* const * const)&map, &succeeded, { }, { }, { });

	return 0;
}

// Hello from yairac!
// hashed key `a`: 1
// map with capacity=4 and count=1:
//     key: a, value: hello from a!

// hashed key `b`: 3
// map with capacity=4 and count=2:
//     key: a, value: hello from a!
//     key: b, value: hello from b!

// hashed key `c`: 1
// map with capacity=4 and count=3:
//     key: a, value: hello from a!
//     key: c, value: hello from c!
//     key: b, value: hello from b!

// hashed key `a`: 1
// map with capacity=4 and count=3:
//     key: a, value: hello from a! (clone)
//     key: c, value: hello from c!
//     key: b, value: hello from b!
