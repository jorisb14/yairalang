
/**
 * @file realloc.c
 *
 * @copyright This file is a part of the project yairac and is distributed under GNU GPLv3 license
 * that should have been included with the project.
 * If not, see https://www.gnu.org/licenses/gpl-3.0.en.html
 *
 * @author jorisb14
 *
 * @date 2022-12-17
 */

#include <core/memory/realloc.h>

// TODO: include logger!

#include <stdlib.h>

/**
 * @addtogroup memory
 * 
 * @{
 */

signed char Core_Memory_realloc(
	const void* const * const destination,
	const unsigned long long size,
	signed char* const succeeded)
{
	if (succeeded == NULL)
	{
		// TODO: log invalid `succeeded` parameter error!
		return 0;
	}

	if (destination == NULL)
	{
		// TODO: log invalid `destination` parameter error!
		*succeeded = 0;
		return 0;
	}

	const void** const inner = (const void** const)destination;
	*inner = (const void*)realloc((void*)*inner, size);

	if (*destination == NULL)
	{
		// TODO: log realloc error!
		*succeeded = 0;
		return 1;
	}

	*succeeded = 1;
	return 1;
}

/**
 * @}
 */

