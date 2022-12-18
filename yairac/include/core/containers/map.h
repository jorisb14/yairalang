
/**
 * @file map.h
 *
 * @copyright This file is a part of the project yarac and is distributed under GNU GPLv3 license
 * that should have been included with the project.
 * If not, see https://www.gnu.org/licenses/gpl-3.0.en.html
 *
 * @author jorisb14
 *
 * @date 2022-12-18
 */

#ifndef _YAIRAC_INCLUDE_CORE_CONTAINERS_MAP_H_
#define _YAIRAC_INCLUDE_CORE_CONTAINERS_MAP_H_

/**
 * @addtogroup containers
 * 
 * @{
 */

// TODO: document!
struct Core_Containers_Map_Node
{
	const char* key;
	unsigned long long length;
	void* value;
	struct Core_Containers_Map_Node* next;
};

// TODO: document!
struct Core_Containers_Map
{
	struct Core_Containers_Map_Node** nodes;
	unsigned long long capacity;
	unsigned long long count;
};

// TODO: document!
signed char Core_Containers_Map_create(
	struct Core_Containers_Map** const map,
	const unsigned long long capacity,
	signed char* const succeeded);

// TODO: document!
signed char Core_Containers_Map_destroy(
	const struct Core_Containers_Map* const * const map,
	signed char* const succeeded);

// TODO: document!
signed char Core_Containers_Map_get(
	struct Core_Containers_Map* const * const map,
	const char* const key,
	const unsigned long long length,
	const void* const * const value,
	signed char* const succeeded);

// TODO: document!
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
