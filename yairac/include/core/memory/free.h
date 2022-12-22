
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

#ifndef _YAIRAC_INCLUDE_CORE_MEMORY_FREE_H_
#define _YAIRAC_INCLUDE_CORE_MEMORY_FREE_H_

#include <core/memory/null.h>

/**
 * @addtogroup memory
 * 
 * @{
 */

/**
 * Deallocate a specified memory block. Return 0 in case of an internal error and 1 otherwise. The
 * parameter `succeeded` indicates logic level errors. Should be used as this:
 * 
 * @code{.c}
 *     char* buffer = NULL;
 *     signed char succeeded = 0;
 *     assert(Core_Memory_free((const char* const * const)&buffer, &succeeded) == 1);
 *     assert(succeeded == 1);
 * @endcode
 */
signed char Core_Memory_free(
	const void* const * const source,
	signed char* const succeeded);

/**
 * @}
 */

#endif
