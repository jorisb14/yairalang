
/**
 * @file map.h
 *
 * @copyright This file is a part of the project yarac and is distributed under GNU GPLv3 license
 * that should have been included with the project.
 * If not, see https://www.gnu.org/licenses/gpl-3.0.en.html
 *
 * @author jorisb14
 *
 * @date 2022-12-19
 */

#ifndef _YAIRAC_INCLUDE_CORE_CONTAINERS_WRAPPERS_MAP_H_
#define _YAIRAC_INCLUDE_CORE_CONTAINERS_WRAPPERS_MAP_H_

/**
 * @addtogroup containers
 * 
 * @{
 */

/**
 * Function Core_Containers_Map_create wrapper. It abstracts some internal logging functionality
 * and provides cleaner way to code the callbacks for the success and fails of the inner function.
 * Should be used as this:
 * 
 * @code{.c}
 *     struct Core_Containers_Map* map = NULL;
 *     signed char succeeded = 0;
 * 
 *     W_Core_Containers_Map_create(&map, 1024, &succeeded,
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
 * TODO: add log for the internal crash! Previous log: "function Core_Containers_Map_create(...) returned
 *       with internal failure!"
 */
#define W_Core_Containers_Map_create(_inmacro_map, _inmacro_capacity, _inmacro_succeeded, _inmacro_internalFailCallback, _inmacro_logicalFailCallback, _inmacro_successCallback) \
	{ \
		if (!Core_Containers_Map_create((_inmacro_map), (_inmacro_capacity), (_inmacro_succeeded))) \
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
 * Function Core_Containers_Map_destroy wrapper. It abstracts some internal logging functionality
 * and provides cleaner way to code the callbacks for the success and fails of the inner function.
 * Should be used as this:
 * 
 * @code{.c}
 *     struct Core_Containers_Map* map = NULL;
 *     signed char succeeded = 0;
 * 
 *     W_Core_Containers_Map_destroy((const struct Core_Containers_Map* const * const)&map, &succeeded,
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
 * TODO: add log for the internal crash! Previous log: "function Core_Containers_Map_destroy(...) returned
 *       with internal failure!"
 */
#define W_Core_Containers_Map_destroy(_inmacro_map, _inmacro_succeeded, _inmacro_internalFailCallback, _inmacro_logicalFailCallback, _inmacro_successCallback) \
	{ \
		if (!Core_Containers_Map_destroy((_inmacro_map), (_inmacro_succeeded))) \
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
 * Function Core_Containers_Map_get wrapper. It abstracts some internal logging functionality and
 * provides cleaner way to code the callbacks for the success and fails of the inner function.
 * Should be used as this:
 * 
 * @code{.c}
 *     struct Core_Containers_Map* map = NULL;
 *     void* value = NULL;
 *     signed char succeeded = 0;
 * 
 *     W_Core_Containers_Map_get((const struct Core_Containers_Map* const * const)&map, key, keyLength, (const void* const * const)&value, &succeeded,
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
 * TODO: add log for the internal crash! Previous log: "function Core_Containers_Map_get(...) returned
 *       with internal failure!"
 */
#define W_Core_Containers_Map_get(_inmacro_map, _inmacro_key, _inmacro_length, _inmacro_value, _inmacro_succeeded, _inmacro_internalFailCallback, _inmacro_logicalFailCallback, _inmacro_successCallback) \
	{ \
		if (!Core_Containers_Map_get((_inmacro_map), (_inmacro_key), (_inmacro_length), (_inmacro_value), (_inmacro_succeeded))) \
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
 * Function Core_Containers_Map_set wrapper. It abstracts some internal logging functionality and
 * provides cleaner way to code the callbacks for the success and fails of the inner function.
 * Should be used as this:
 * 
 * @code{.c}
 *     struct Core_Containers_Map* map = NULL;
 *     signed char succeeded = 0;
 * 
 *     W_Core_Containers_Map_set((const struct Core_Containers_Map* const * const)&map, key, keyLength, (const void* const * const)&value, &succeeded,
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
 * TODO: add log for the internal crash! Previous log: "function Core_Containers_Map_set(...) returned
 *       with internal failure!"
 */
#define W_Core_Containers_Map_set(_inmacro_map, _inmacro_key, _inmacro_length, _inmacro_value, _inmacro_succeeded, _inmacro_internalFailCallback, _inmacro_logicalFailCallback, _inmacro_successCallback) \
	{ \
		if (!Core_Containers_Map_set((_inmacro_map), (_inmacro_key), (_inmacro_length), (_inmacro_value), (_inmacro_succeeded))) \
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
