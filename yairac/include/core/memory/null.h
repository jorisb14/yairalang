
/**
 * @file null.h
 *
 * @copyright This file is a part of the project yairac and is distributed under GNU GPLv3 license
 * that should have been included with the project.
 * If not, see https://www.gnu.org/licenses/gpl-3.0.en.html
 *
 * @author jorisb14
 *
 * @date 2022-12-17
 */

#ifndef _YAIRAC_INCLUDE_CORE_MEMORY_NULL_H_
#define _YAIRAC_INCLUDE_CORE_MEMORY_NULL_H_

/**
 * @addtogroup memory
 * 
 * @{
 */

#ifndef NULL
	/**
	 * Lightweight NULL macro, tht does not require stdlib.h header or any other C standard library
	 * utility. Should be used as any other NULL in the C programming language.
	 */
#	define NULL ((void*)0)
#endif

/**
 * @}
 */

#endif

