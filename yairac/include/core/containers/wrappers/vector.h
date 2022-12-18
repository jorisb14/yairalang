
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

// TODO: add log for the internal crash!
// Previous log: "function Core_Containers_Vector_create(...) returned with internal failure!"
// TODO: document!
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

// TODO: add log for the internal crash!
// Previous log: "function Core_Containers_Vector_destroy(...) returned with internal failure!"
// TODO: document!
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

// TODO: add log for the internal crash!
// Previous log: "function Core_Containers_Vector_get(...) returned with internal failure!"
// TODO: document!
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

// TODO: add log for the internal crash!
// Previous log: "function Core_Containers_Vector_set(...) returned with internal failure!"
// TODO: document!
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

// TODO: add log for the internal crash!
// Previous log: "function Core_Containers_Vector_push(...) returned with internal failure!"
// TODO: document!
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

// TODO: add log for the internal crash!
// Previous log: "function Core_Containers_Vector_shrink(...) returned with internal failure!"
// TODO: document!
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
