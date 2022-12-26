
/**
 * @file map.h
 *
 * @copyright This file is a part of the project yairac and is distributed under GNU GPLv3 license
 * that should have been included with the project.
 * If not, see https://www.gnu.org/licenses/gpl-3.0.en.html
 *
 * @author jorisb14
 *
 * @date 2022-12-19
 */

#ifndef _YAIRAC_INCLUDE_CORE_CONTAINERS_MAP_H_
#define _YAIRAC_INCLUDE_CORE_CONTAINERS_MAP_H_

/**
 * @addtogroup containers
 * 
 * @{
 */

/**
 * The map's node structure. It contains the key (string), the value pointer, and the node to the
 * next node.
 */
struct Core_Containers_Map_Node
{
	struct
	{
		const char* buffer;
		unsigned long length;
	} key;

	void* value;
	struct Core_Containers_Map_Node* next;
};

/**
 * The map data structure. It contains the pointer to it's inner nodes table and the capacity.
 */
struct Core_Containers_Map
{
	struct Core_Containers_Map_Node** nodes;
	unsigned long long capacity;
};

/**
 * Create a dynamic map container. Return 0 in case of an internal error and 1 otherwise. The
 * parameter `succeeded` indicates logic level errors. Should be used as this:
 * 
 * @code{.c}
 *     struct Core_Containers_Map* map = NULL;
 *     signed char succeeded = 0;
 *     assert(Core_Containers_Map_create(&map, 1024, &succeeded) == 1);
 *     assert(succeeded == 1);
 * @endcode
 */
signed char Core_Containers_Map_create(
	struct Core_Containers_Map** const map,
	const unsigned long long capacity,
	signed char* const succeeded);

/**
 * Destroy the dynamic map container. Return 0 in case of an internal error and 1 otherwise. The
 * parameter `succeeded` indicates logic level errors. Should be used as this:
 * 
 * @code{.c}
 *     struct Core_Containers_Map* map = NULL;
 *     signed char succeeded = 0;
 *     assert(Core_Containers_Map_destroy((const struct Core_Containers_Map* const * const)&map, &succeeded) == 1);
 *     assert(succeeded == 1);
 * @endcode
 */
signed char Core_Containers_Map_destroy(
	const struct Core_Containers_Map* const * const map,
	signed char* const succeeded);

/**
 * Get a value from the map container with specified key. Return 0 in case of an internal error and
 * 1 otherwise. The parameter `succeeded` indicates logic level errors. Should be used as this:
 * 
 * @code{.c}
 *     struct Core_Containers_Map* map = NULL;
 *     void* value = NULL;
 *     signed char succeeded = 0;
 *     assert(Core_Containers_Map_get((const struct Core_Containers_Map* const * const)&map, key, keyLength, (const void* const * const)&value, &succeeded) == 1);
 *     assert(succeeded == 1);
 * @endcode
 */
signed char Core_Containers_Map_get(
	const struct Core_Containers_Map* const * const map,
	const char* const key,
	const unsigned long long length,
	const void* const * const value,
	signed char* const succeeded);

/**
 * Set a value to the map container with specified key. Return 0 in case of an internal error and
 * 1 otherwise. The parameter `succeeded` indicates logic level errors. Should be used as this:
 * 
 * @code{.c}
 *     struct Core_Containers_Map* map = NULL;
 *     signed char succeeded = 0;
 *     assert(Core_Containers_Map_set(&map, key, keyLength, (const void* const * const)&value, &succeeded) == 1);
 *     assert(succeeded == 1);
 * @endcode
 */
signed char Core_Containers_Map_set(
	struct Core_Containers_Map* const * const map,
	const char* const key,
	const unsigned long long length,
	const void* const * const value,
	signed char* const succeeded);

/**
 * @}
 */

#endif

