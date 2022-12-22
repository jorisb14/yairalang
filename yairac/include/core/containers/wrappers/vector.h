
/**
 * @file vector.h
 *
 * @copyright This file is a part of the project yarac and is distributed under GNU GPLv3 license
 * that should have been included with the project.
 * If not, see https://www.gnu.org/licenses/gpl-3.0.en.html
 *
 * @author jorisb14
 *
 * @date 2022-12-17
 */

#ifndef _YAIRAC_INCLUDE_CORE_CONTAINERS_WRAPPERS_VECTOR_H_
#define _YAIRAC_INCLUDE_CORE_CONTAINERS_WRAPPERS_VECTOR_H_

#include <core/containers/vector.h>

/**
 * @addtogroup containers
 * 
 * @{
 */

/**
 * Function Core_Containers_Vector_create wrapper. It abstracts some internal logging functionality
 * and provides cleaner way to code the callbacks for the success and fails of the inner function.
 * Should be used as this:
 * 
 * @code{.c}
 *     struct Core_Containers_Vector* vector = NULL;
 *     signed char succeeded = 0;
 * 
 *     W_Core_Containers_Vector_create(&vector, 10, &succeeded,
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
 * TODO: add log for the internal crash! Previous log: "function Core_Containers_Vector_create(...) returned
 *       with internal failure!"
 */
#define W_Core_Containers_Vector_create(_inmacro_vector, _inmacro_capacity, _inmacro_succeeded, _inmacro_internalFailCallback, _inmacro_logicalFailCallback, _inmacro_successCallback) \
	{ \
		if (!Core_Containers_Vector_create((_inmacro_vector), (_inmacro_capacity), (_inmacro_succeeded))) \
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
 * Function Core_Containers_Vector_destroy wrapper. It abstracts some internal logging functionality
 * and provides cleaner way to code the callbacks for the success and fails of the inner function.
 * Should be used as this:
 * 
 * @code{.c}
 *     struct Core_Containers_Vector* vector = NULL;
 *     signed char succeeded = 0;
 * 
 *     W_Core_Containers_Vector_destroy((const struct Core_Containers_Vector* const * const)&vector, &succeeded,
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
 * TODO: add log for the internal crash! Previous log: "function Core_Containers_Vector_destroy(...) returned
 *       with internal failure!"
 */
#define W_Core_Containers_Vector_destroy(_inmacro_vector, _inmacro_succeeded, _inmacro_internalFailCallback, _inmacro_logicalFailCallback, _inmacro_successCallback) \
	{ \
		if (!Core_Containers_Vector_destroy((_inmacro_vector), (_inmacro_succeeded))) \
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
 * Function Core_Containers_Vector_get wrapper. It abstracts some internal logging functionality
 * and provides cleaner way to code the callbacks for the success and fails of the inner function.
 * Should be used as this:
 * 
 * @code{.c}
 *     struct Core_Containers_Vector* vector = NULL;
 *     void* data = NULL;
 *     signed char succeeded = 0;
 * 
 *     W_Core_Containers_Vector_get((const struct Core_Containers_Vector* const * const)&vector, 0, (const void* const * const)&data, &succeeded,
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
 * TODO: add log for the internal crash! Previous log: "function Core_Containers_Vector_get(...) returned
 *       with internal failure!"
 */
#define W_Core_Containers_Vector_get(_inmacro_vector, _inmacro_index, _inmacro_data, _inmacro_succeeded, _inmacro_internalFailCallback, _inmacro_logicalFailCallback, _inmacro_successCallback) \
	{ \
		if (!Core_Containers_Vector_get((_inmacro_vector), (_inmacro_index), (_inmacro_data), (_inmacro_succeeded))) \
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
 * Function Core_Containers_Vector_set wrapper. It abstracts some internal logging functionality
 * and provides cleaner way to code the callbacks for the success and fails of the inner function.
 * Should be used as this:
 * 
 * @code{.c}
 *     struct Core_Containers_Vector* vector = NULL;
 *     signed char succeeded = 0;
 * 
 *     W_Core_Containers_Vector_set(&vector, 0, (const void* const * const)&data, &succeeded,
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
 * TODO: add log for the internal crash! Previous log: "function Core_Containers_Vector_set(...) returned
 *       with internal failure!"
 */
#define W_Core_Containers_Vector_set(_inmacro_vector, _inmacro_index, _inmacro_data, _inmacro_succeeded, _inmacro_internalFailCallback, _inmacro_logicalFailCallback, _inmacro_successCallback) \
	{ \
		if (!Core_Containers_Vector_set((_inmacro_vector), (_inmacro_index), (_inmacro_data), (_inmacro_succeeded))) \
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
 * Function Core_Containers_Vector_push wrapper. It abstracts some internal logging functionality
 * and provides cleaner way to code the callbacks for the success and fails of the inner function.
 * Should be used as this:
 * 
 * @code{.c}
 *     struct Core_Containers_Vector* vector = NULL;
 *     signed char succeeded = 0;
 * 
 *     W_Core_Containers_Vector_push(&vector, (const void* const * const)&data, &succeeded,
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
 * TODO: add log for the internal crash! Previous log: "function Core_Containers_Vector_push(...) returned
 *       with internal failure!"
 */
#define W_Core_Containers_Vector_push(_inmacro_vector, _inmacro_data, _inmacro_succeeded, _inmacro_internalFailCallback, _inmacro_logicalFailCallback, _inmacro_successCallback) \
	{ \
		if (!Core_Containers_Vector_push((_inmacro_vector), (_inmacro_data), (_inmacro_succeeded))) \
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
 * Function Core_Containers_Vector_shrink wrapper. It abstracts some internal logging functionality
 * and provides cleaner way to code the callbacks for the success and fails of the inner function.
 * Should be used as this:
 * 
 * @code{.c}
 *     struct Core_Containers_Vector* vector = NULL;
 *     signed char succeeded = 0;
 * 
 *     W_Core_Containers_Vector_shrink(&vector, &succeeded,
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
 * TODO: add log for the internal crash! Previous log: "function Core_Containers_Vector_shrink(...) returned
 *       with internal failure!"
 */
#define W_Core_Containers_Vector_shrink(_inmacro_vector, _inmacro_succeeded, _inmacro_internalFailCallback, _inmacro_logicalFailCallback, _inmacro_successCallback) \
	{ \
		if (!Core_Containers_Vector_shrink((_inmacro_vector), (_inmacro_succeeded))) \
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
