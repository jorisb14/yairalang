
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

#include <core/containers/map.h>

#include <core/memory.h> // For memory related functions: malloc, realloc, free, and NULL.

// TODO: include logger!

/**
 * @addtogroup containers
 * 
 * @{
 */

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

	W_Core_Memory_malloc((const void* const * const)(&((*map)->nodes)), capacity * sizeof(void*), succeeded,
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

	// TODO: consider testing memset for NULL'yfing nodes.
	// I think it should result in the same thing, but GCC
	// might optimize memset better. TEST IT!
	for (unsigned long long i = 0; i < capacity; ++i)
	{
		(*map)->nodes[i] = NULL;
	}

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
		struct Core_Containers_Map_Node* node = (*map)->nodes[i];

		while (node != NULL)
		{
			struct Core_Containers_Map_Node* current = node;
			node = node->next;

			W_Core_Memory_free((const void* const * const)(&current), succeeded,
			{
				*succeeded = 0;
				return 0;
			},
			{
				// TODO: failed to deallocate map's node!
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
		// TODO: failed to deallocate map's nodes!
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
		// TODO: failed to deallocate map!
		// *succeeded = 0;
		return 1;
	},
	{});

	*succeeded = 1;
	return 1;
}

/**
 * @}
 */
