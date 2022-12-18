
/**
 * @file list.c
 *
 * @copyright This file is a part of the project yarac and is distributed under GNU GPLv3 license
 * that should have been included with the project.
 * If not, see https://www.gnu.org/licenses/gpl-3.0.en.html
 *
 * @author jorisb14
 *
 * @date 2022-12-18
 */

#include <core/containers/list.h>

#include <core/memory.h> // For memory related functions: malloc, free, and NULL.

// TODO: include logger!

/**
 * @addtogroup containers
 * 
 * @{
 */

signed char Core_Containers_List_create(
	struct Core_Containers_List** const list,
	signed char* const succeeded)
{
	if (succeeded == NULL)
	{
		// TODO: log invalid `succeeded` parameter error!
		return 0;
	}

	if (list == NULL)
	{
		// TODO: log invalid `list` parameter error!
		*succeeded = 0;
		return 0;
	}

	*list = NULL;

	W_Core_Memory_malloc((const void* const * const)list, sizeof(struct Core_Containers_List), succeeded,
	{
		*succeeded = 0;
		return 0;
	},
	{
		// TODO: log failed list's allocation!
		// *succeeded = 0;
		return 1;
	},
	{});

	(*list)->head = NULL;
	(*list)->count = 0;

	*succeeded = 1;
	return 1;
}

signed char Core_Containers_List_destroy(
	const struct Core_Containers_List* const * const list,
	signed char* const succeeded)
{
	if (succeeded == NULL)
	{
		// TODO: log invalid `succeeded` parameter error!
		return 0;
	}

	if (list == NULL)
	{
		// TODO: log invalid `list` parameter error!
		*succeeded = 0;
		return 0;
	}

	if (*list == NULL)
	{
		// TODO: log invalid `list`'s deref parameter error!
		*succeeded = 0;
		return 0;
	}

	*succeeded = 0;

	struct Core_Containers_List_Node* last = (*list)->head;

	while (last != NULL)
	{
		struct Core_Containers_List_Node* current = last;
		last = last->next;

		W_Core_Memory_free((const void* const * const)(&current), succeeded,
		{
			*succeeded = 0;
			return 0;
		},
		{
			// TODO: failed to deallocate list's node!
			// *succeeded = 0;
			return 1;
		},
		{});
	}

	W_Core_Memory_free((const void* const * const)list, succeeded,
	{
		*succeeded = 0;
		return 0;
	},
	{
		// TODO: failed to deallocate list!
		// *succeeded = 0;
		return 1;
	},
	{});

	*succeeded = 1;
	return 1;
}

signed char Core_Containers_List_push(
	struct Core_Containers_List* const * const list,
	const void* const * const data,
	signed char* const succeeded)
{
	if (succeeded == NULL)
	{
		// TODO: log invalid `succeeded` parameter error!
		return 0;
	}

	if (list == NULL)
	{
		// TODO: log invalid `list` parameter error!
		*succeeded = 0;
		return 0;
	}

	if (*list == NULL)
	{
		// TODO: log invalid `list`'s deref parameter error!
		*succeeded = 0;
		return 0;
	}

	if (data == NULL)
	{
		// TODO: log that provided function parameter `data` is invalid!
		*succeeded = 0;
		return 0;
	}

	*succeeded = 0;

	struct Core_Containers_List_Node* node = NULL;

	W_Core_Memory_malloc((const void** const)(&node), sizeof(struct Core_Containers_List_Node), succeeded,
	{
		*succeeded = 0;
		return 0;
	},
	{
		// TODO: log failed to allocate node error!
		// *succeeded = 0;
		return 1;
	},
	{});

	// Setting up node's 
	node->data = (void*)data;

	// Setting up node's 
	node->next = NULL;

	if ((*list)->head == NULL)
	{
		node->previous = NULL;
		(*list)->head = node;
		++((*list)->count);

		*succeeded = 1;
		return 1;
	}

	struct Core_Containers_List_Node* last = (*list)->head;

	while (last->next != NULL)
	{
		last = last->next;
	}

	last->next = node;
	node->previous = last;
	++((*list)->count);

	*succeeded = 1;
	return 1;
}

signed char Core_Containers_List_pop(
	struct Core_Containers_List* const * const list,
	const void* const * const data,
	signed char* const succeeded)
{
	if (succeeded == NULL)
	{
		// TODO: log invalid `succeeded` parameter error!
		return 0;
	}

	if (list == NULL)
	{
		// TODO: log invalid `list` parameter error!
		*succeeded = 0;
		return 0;
	}

	if (*list == NULL)
	{
		// TODO: log invalid `list`'s deref parameter error!
		*succeeded = 0;
		return 0;
	}

	if ((*list)->head == NULL)
	{
		// TODO: log that provided function parameter `list`'s head is NULL!
		*succeeded = 0;
		return 0;
	}

	if (data == NULL)
	{
		// TODO: log that provided function parameter `data` is invalid!
		*succeeded = 0;
		return 0;
	}

	*succeeded = 0;

	struct Core_Containers_List_Node* last = (*list)->head;

	while (last->next != NULL)
	{
		last = last->next;
	}

	const void** const inner = (const void** const)data;
	*inner = last->data;

	--((*list)->count);
	last = NULL;

	*succeeded = 1;
	return 1;
}

signed char Core_Containers_List_peek(
	const struct Core_Containers_List* const * const list,
	const unsigned long long offset,
	const void* const * const data,
	signed char* const succeeded)
{
	if (succeeded == NULL)
	{
		// TODO: log invalid `succeeded` parameter error!
		return 0;
	}

	if (list == NULL)
	{
		// TODO: log invalid `list` parameter error!
		*succeeded = 0;
		return 0;
	}

	if (*list == NULL)
	{
		// TODO: log invalid `list`'s deref parameter error!
		*succeeded = 0;
		return 0;
	}

	if (offset >= (*list)->count)
	{
		// TODO: log that provided function parameter `offset` is out of bounds!
		*succeeded = 0;
		return 0;
	}

	if (data == NULL)
	{
		// TODO: log that provided function parameter `data` is invalid!
		*succeeded = 0;
		return 0;
	}

	*succeeded = 0;

	struct Core_Containers_List_Node* last = (*list)->head;

	for (unsigned long long count = 0; last->next != NULL && count != offset; ++count)
	{
		last = last->next;
	}

	const void** const inner = (const void** const)data;
	*inner = last->data;

	*succeeded = 1;
	return 1;
}

/**
 * @}
 */
