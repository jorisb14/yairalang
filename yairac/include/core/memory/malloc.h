
/**
 * @file malloc.h
 *
 * @copyright This file is a part of the project yarac and is distributed under GNU GPLv3 license
 * that should have been included with the project.
 * If not, see https://www.gnu.org/licenses/gpl-3.0.en.html
 *
 * @author jorisb14
 *
 * @date 2022-12-17
 */

#ifndef _YAIRAC_INCLUDE_CORE_MEMORY_MALLOC_H_
#define _YAIRAC_INCLUDE_CORE_MEMORY_MALLOC_H_

#include <core/memory/null.h>

/**
 * @addtogroup memory
 * 
 * @{
 */

// TODO: document!
signed char Core_Memory_malloc(
	const void* const * const destination,
	const unsigned long long size,
	signed char* const succeeded);

/**
 * @}
 */

#endif
