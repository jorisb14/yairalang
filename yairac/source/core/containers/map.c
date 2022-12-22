
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

#include <string.h>

/**
 * @addtogroup containers
 * 
 * @{
 */

static signed char Core_Containers_Map_hash(
	unsigned long long* const hash,
	const unsigned char* const * const bytes,
	const unsigned long long length,
	const unsigned long long capacity,
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

	if (bytes == NULL)
	{
		// TODO: log invalid `bytes` parameter error!
		*succeeded = 0;
		return 0;
	}

	if (*bytes == NULL)
	{
		// TODO: log invalid `bytes`'s deref parameter error!
		*succeeded = 0;
		return 0;
	}

	if (length <= 0)
	{
		// TODO: log invalid `length` parameter error!
		*succeeded = 0;
		return 0;
	}

	if (capacity <= 0)
	{
		// TODO: log invalid `capacity` parameter error!
		*succeeded = 0;
		return 0;
	}

	unsigned long long value = 0;

	for (unsigned long long i = 0; i < length; ++i)
	{
		const unsigned char byte = *(const unsigned char* const)(bytes + i);
		value += (value ^ (value * (byte >> 13))) + ((byte + (value | 31)) ^ 13);
	}

	*hash = value % capacity;

	*succeeded = 1;
	return 1;
}

// TODO: add log for the internal crash!
// Previous log: "function Core_Containers_Map_hash(...) returned with internal failure!"
// TODO: document!
#define W_Core_Containers_Map_hash(_inmacro_hash, _inmacro_bytes, _inmacro_length, _inmacro_capacity, _inmacro_succeeded, _inmacro_internalFailCallback, _inmacro_logicalFailCallback, _inmacro_successCallback) \
	{ \
		if (!Core_Containers_Map_hash((_inmacro_hash), (_inmacro_bytes), (_inmacro_length), (_inmacro_capacity), (_inmacro_succeeded))) \
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

signed char Core_Containers_Map_get(
	const struct Core_Containers_Map* const * const map,
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

	if (length <= 0)
	{
		// TODO: log invalid `length` parameter error!
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

	unsigned long long hash = 0;

	W_Core_Containers_Map_hash(&hash, (const unsigned char* const *const)&key, length, (*map)->capacity, succeeded,
	{
		*succeeded = 0;
		return 0;
	},
	{
		// TODO: failed to hash key!
		// *succeeded = 0;
		return 1;
	},
	{});

	struct Core_Containers_Map_Node* iterator = (*map)->nodes[hash];

	while (iterator != NULL)
	{
		if (length == iterator->key.length && strncmp(key, iterator->key.buffer, length) == 0)
		{
			const void** const inner = (const void** const)value;
			*inner = (void*)(iterator->value);

			*succeeded = 1;
			return 1;
		}

		if (iterator->next == NULL)
		{
			break;
		}

		iterator = iterator->next;
	}

	// TODO: log!
	const void** const inner = (const void** const)value;
	*inner = (void*)(NULL);

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

	if (length <= 0)
	{
		// TODO: log invalid `length` parameter error!
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

	unsigned long long hash = 0;

	W_Core_Containers_Map_hash(&hash, (const unsigned char* const *const)&key, length, (*map)->capacity, succeeded,
	{
		*succeeded = 0;
		return 0;
	},
	{
		// TODO: failed to hash key!
		// *succeeded = 0;
		return 1;
	},
	{});

	struct Core_Containers_Map_Node** nodeAddr = &((*map)->nodes[hash]);

	if (*nodeAddr != NULL)
	{
		struct Core_Containers_Map_Node* iterator = *nodeAddr;

		while (iterator != NULL)
		{
			if (length == iterator->key.length && strncmp(key, iterator->key.buffer, length) == 0)
			{
				const void** const inner = (const void** const)value;
				iterator->value = (void*)(*inner);

				*succeeded = 1;
				return 1;
			}

			if (iterator->next == NULL)
			{
				break;
			}

			iterator = iterator->next;
		}

		nodeAddr = &(iterator->next);
	}

	W_Core_Memory_malloc((const void* const * const)nodeAddr, sizeof(struct Core_Containers_Map_Node), succeeded,
	{
		*succeeded = 0;
		return 0;
	},
	{
		// TODO: failed to allocate node key!
		// *succeeded = 0;
		return 1;
	},
	{});

	(*nodeAddr)->key.buffer = key;
	(*nodeAddr)->key.length = length;

	const void** const inner = (const void** const)value;
	(*nodeAddr)->value = (void*)(*inner);

	(*nodeAddr)->next = NULL;

	*succeeded = 1;
	return 1;
}

/**
 * @}
 */
