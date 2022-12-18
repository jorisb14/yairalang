
/**
 * @file list.h
 *
 * @copyright This file is a part of the project yarac and is distributed under GNU GPLv3 license
 * that should have been included with the project.
 * If not, see https://www.gnu.org/licenses/gpl-3.0.en.html
 *
 * @author jorisb14
 *
 * @date 2022-12-18
 */

#ifndef _YAIRAC_INCLUDE_CORE_CONTAINERS_LIST_H_
#define _YAIRAC_INCLUDE_CORE_CONTAINERS_LIST_H_

/**
 * @addtogroup containers
 * 
 * @{
 */

// TODO: document!
struct Core_Containers_List_Node
{
	struct Core_Containers_List_Node* next;
	struct Core_Containers_List_Node* previous;
	void* data;
};

// TODO: document!
struct Core_Containers_List
{
	struct Core_Containers_List_Node* head;
	unsigned long long count;
};

// TODO: document!
signed char Core_Containers_List_create(
	struct Core_Containers_List** const list,
	signed char* const succeeded);

// TODO: document!
signed char Core_Containers_List_destroy(
	const struct Core_Containers_List* const * const list,
	signed char* const succeeded);

// TODO: document!
signed char Core_Containers_List_push(
	struct Core_Containers_List* const * const list,
	const void* const * const data,
	signed char* const succeeded);

// TODO: document!
signed char Core_Containers_List_pop(
	struct Core_Containers_List* const * const list,
	const void* const * const data,
	signed char* const succeeded);

// TODO: document!
signed char Core_Containers_List_peek(
	const struct Core_Containers_List* const * const list,
	const unsigned long long offset,
	const void* const * const data,
	signed char* const succeeded);

/**
 * @}
 */

#endif
