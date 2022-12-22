
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

/**
 * The list's node structure. It contains the pointer to it's data, the next node, and the previous
 * node.
 */
struct Core_Containers_List_Node
{
	struct Core_Containers_List_Node* next;
	struct Core_Containers_List_Node* previous;
	void* data;
};

/**
 * The list data structure. It contains the pointer to it's head node and the count of it's items.
 */
struct Core_Containers_List
{
	struct Core_Containers_List_Node* head;
	unsigned long long count;
};

/**
 * Create a dynamic list container. Return 0 in case of an internal error and 1 otherwise. The
 * parameter `succeeded` indicates logic level errors. Should be used as this:
 * 
 * @code{.c}
 *     struct Core_Containers_List* list = NULL;
 *     signed char succeeded = 0;
 *     assert(Core_Containers_List_create(&list, &succeeded) == 1);
 *     assert(succeeded == 1);
 * @endcode
 */
signed char Core_Containers_List_create(
	struct Core_Containers_List** const list,
	signed char* const succeeded);

/**
 * Destroy the dynamic list container. Return 0 in case of an internal error and 1 otherwise. The
 * parameter `succeeded` indicates logic level errors. Should be used as this:
 * 
 * @code{.c}
 *     struct Core_Containers_List* list = NULL;
 *     signed char succeeded = 0;
 *     assert(Core_Containers_List_destroy((const struct Core_Containers_List* const * const)&list, &succeeded) == 1);
 *     assert(succeeded == 1);
 * @endcode
 */
signed char Core_Containers_List_destroy(
	const struct Core_Containers_List* const * const list,
	signed char* const succeeded);

/**
 * Push new element into the list's end. Return 0 in case of an internal error and 1 otherwise. The
 * parameter `succeeded` indicates logic level errors. Should be used as this:
 * 
 * @code{.c}
 *     struct Core_Containers_List* list = NULL;
 *     signed char succeeded = 0;
 *     assert(Core_Containers_List_push(&list, (const void* const * const)&data, &succeeded) == 1);
 *     assert(succeeded == 1);
 * @endcode
 */
signed char Core_Containers_List_push(
	struct Core_Containers_List* const * const list,
	const void* const * const data,
	signed char* const succeeded);

/**
 * Pop the last element from the list. Return 0 in case of an internal error and 1 otherwise. The
 * parameter `succeeded` indicates logic level errors. Should be used as this:
 * 
 * @code{.c}
 *     struct Core_Containers_List* list = NULL;
 *     void* data = NULL;
 *     signed char succeeded = 0;
 *     assert(Core_Containers_List_pop(&list, (const void* const * const)&data, &succeeded) == 1);
 *     assert(succeeded == 1);
 * @endcode
 */
signed char Core_Containers_List_pop(
	struct Core_Containers_List* const * const list,
	const void* const * const data,
	signed char* const succeeded);

/**
 * @}
 */

#endif
