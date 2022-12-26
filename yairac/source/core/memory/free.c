
/**
 * @file free.c
 *
 * @copyright This file is a part of the project yairac and is distributed under GNU GPLv3 license
 * that should have been included with the project.
 * If not, see https://www.gnu.org/licenses/gpl-3.0.en.html
 *
 * @author jorisb14
 *
 * @date 2022-12-17
 */

#include <core/memory/free.h>

// TODO: include logger!

#include <stdlib.h>

/**
 * @addtogroup memory
 * 
 * @{
 */

signed char Core_Memory_free(
	const void* const * const source,
	signed char* const succeeded)
{
	if (succeeded == NULL)
	{
		// TODO: log invalid `succeeded` parameter error!
		return 0;
	}

	if (source == NULL)
	{
		// TODO: log invalid `source` parameter error!
		*succeeded = 0;
		return 0;
	}

	// TODO: set the source/inner to NULL;
	const void** const inner = (const void** const)source;
	free((void*)(*inner));
	*inner = NULL;

	*succeeded = 1;
	return 1;
}

/**
 * @}
 */

