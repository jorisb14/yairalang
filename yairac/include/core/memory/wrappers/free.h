
/**
 * @file free.h
 *
 * @copyright This file is a part of the project yarac and is distributed under GNU GPLv3 license
 * that should have been included with the project.
 * If not, see https://www.gnu.org/licenses/gpl-3.0.en.html
 *
 * @author jorisb14
 *
 * @date 2022-12-17
 */

#ifndef _YAIRAC_INCLUDE_CORE_MEMORY_WRAPPERS_FREE_H_
#define _YAIRAC_INCLUDE_CORE_MEMORY_WRAPPERS_FREE_H_

#include <core/memory/free.h>

/**
 * @addtogroup memory
 * 
 * @{
 */

// TODO: add log for the internal crash!
// Previous log: "function Core_Memory_free(...) returned with internal failure!"
// TODO: document!
#define W_Core_Memory_free(_inmacro_destination, _inmacro_succeeded, _inmacro_internalFailCallback, _inmacro_logicalFailCallback, _inmacro_successCallback) \
	{ \
		if (!Core_Memory_free((_inmacro_destination), (_inmacro_succeeded))) \
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
