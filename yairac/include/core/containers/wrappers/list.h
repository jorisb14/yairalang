
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

#ifndef _YAIRAC_INCLUDE_CORE_CONTAINERS_WRAPPERS_LIST_H_
#define _YAIRAC_INCLUDE_CORE_CONTAINERS_WRAPPERS_LIST_H_

#include <core/containers/list.h>

/**
 * @addtogroup containers
 * 
 * @{
 */

/**
 * Function Core_Containers_List_create wrapper. It abstracts some internal logging functionality
 * and provides cleaner way to code the callbacks for the success and fails of the inner function.
 * Should be used as this:
 * 
 * @code{.c}
 *     struct Core_Containers_List* list = NULL;
 *     signed char succeeded = 0;
 * 
 *     W_Core_Containers_List_create(&list, &succeeded,
 *     {
 *         // Internal error!
 *     },
 *     {
 *         // Logical error!
 *     },
 *     {
 *         // Success!
 *     });
 * @endcode
 * 
 * TODO: add log for the internal crash! Previous log: "function Core_Containers_List_create(...) returned
 *       with internal failure!"
 */
#define W_Core_Containers_List_create(_inmacro_list, _inmacro_succeeded, _inmacro_internalFailCallback, _inmacro_logicalFailCallback, _inmacro_successCallback) \
	{ \
		if (!Core_Containers_List_create((_inmacro_list), (_inmacro_succeeded))) \
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

/**
 * Function Core_Containers_List_destroy wrapper. It abstracts some internal logging functionality
 * and provides cleaner way to code the callbacks for the success and fails of the inner function.
 * Should be used as this:
 * 
 * @code{.c}
 *     struct Core_Containers_List* list = NULL;
 *     signed char succeeded = 0;
 * 
 *     W_Core_Containers_List_destroy((const struct Core_Containers_List* const * const)&list, &succeeded,
 *     {
 *         // Internal error!
 *     },
 *     {
 *         // Logical error!
 *     },
 *     {
 *         // Success!
 *     });
 * @endcode
 * 
 * TODO: add log for the internal crash! Previous log: "function Core_Containers_List_destroy(...) returned
 *       with internal failure!"
 */
#define W_Core_Containers_List_destroy(_inmacro_list, _inmacro_succeeded, _inmacro_internalFailCallback, _inmacro_logicalFailCallback, _inmacro_successCallback) \
	{ \
		if (!Core_Containers_List_destroy((_inmacro_list), (_inmacro_succeeded))) \
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

/**
 * Function Core_Containers_List_push wrapper. It abstracts some internal logging functionality and
 * provides cleaner way to code the callbacks for the success and fails of the inner function.
 * Should be used as this:
 * 
 * @code{.c}
 *     struct Core_Containers_List* list = NULL;
 *     signed char succeeded = 0;
 * 
 *     W_Core_Containers_List_push(&list, (const char* const * const)&data, &succeeded,
 *     {
 *         // Internal error!
 *     },
 *     {
 *         // Logical error!
 *     },
 *     {
 *         // Success!
 *     });
 * @endcode
 * 
 * TODO: add log for the internal crash! Previous log: "function Core_Containers_List_push(...) returned
 *       with internal failure!"
 */
#define W_Core_Containers_List_push(_inmacro_list, _inmacro_data, _inmacro_succeeded, _inmacro_internalFailCallback, _inmacro_logicalFailCallback, _inmacro_successCallback) \
	{ \
		if (!Core_Containers_List_push((_inmacro_list), (_inmacro_data), (_inmacro_succeeded))) \
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

/**
 * Function Core_Containers_List_pop wrapper. It abstracts some internal logging functionality and
 * provides cleaner way to code the callbacks for the success and fails of the inner function.
 * Should be used as this:
 * 
 * @code{.c}
 *     struct Core_Containers_List* list = NULL;
 *     void* data = NULL;
 *     signed char succeeded = 0;
 * 
 *     W_Core_Containers_List_pop(&list, (const char* const * const)&data, &succeeded,
 *     {
 *         // Internal error!
 *     },
 *     {
 *         // Logical error!
 *     },
 *     {
 *         // Success!
 *     });
 * @endcode
 * 
 * TODO: add log for the internal crash! Previous log: "function Core_Containers_List_pop(...) returned
 *       with internal failure!"
 */
#define W_Core_Containers_List_pop(_inmacro_list, _inmacro_data, _inmacro_succeeded, _inmacro_internalFailCallback, _inmacro_logicalFailCallback, _inmacro_successCallback) \
	{ \
		if (!Core_Containers_List_pop((_inmacro_list), (_inmacro_data), (_inmacro_succeeded))) \
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

/**
 * @}
 */

#endif
