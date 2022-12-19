
/**
 * @file vector.c
 *
 * @copyright This file is a part of the project yarac and is distributed under GNU GPLv3 license
 * that should have been included with the project.
 * If not, see https://www.gnu.org/licenses/gpl-3.0.en.html
 *
 * @author jorisb14
 *
 * @date 2022-12-17
 */

#include <core/containers/vector.h>

#include <core/memory.h> // For memory related functions: malloc, realloc, free, and NULL.

// TODO: include logger!

/**
 * @addtogroup containers
 * 
 * @{
 */

signed char Core_Containers_Vector_create(
	struct Core_Containers_Vector** const vector,
	const unsigned long long capacity,
	signed char* const succeeded)
{
	if (succeeded == NULL)
	{
		// TODO: log invalid `succeeded` parameter error!
		return 0;
	}

	if (vector == NULL)
	{
		// TODO: log invalid `vector` parameter error!
		*succeeded = 0;
		return 0;
	}

	*vector = NULL;

	W_Core_Memory_malloc((const void* const * const)vector, sizeof(struct Core_Containers_Vector), succeeded,
	{
		*succeeded = 0;
		return 0;
	},
	{
		// TODO: log failed vector's allocation!
		// *succeeded = 0;
		return 1;
	},
	{});

	(*vector)->data = NULL;

	W_Core_Memory_malloc((const void* const * const)(&((*vector)->data)), capacity * sizeof(void*), succeeded,
	{
		*succeeded = 0;
		return 0;
	},
	{
		// TODO: log failed vector's data allocation!
		// *succeeded = 0;
		return 1;
	},
	{});

	// TODO: consider testing memset for NULL'yfing data.
	// I think it should result in the same thing, but GCC
	// might optimize memset better. TEST IT!
	for (unsigned long long i = 0; i < capacity; ++i)
	{
		(*vector)->data[i] = NULL;
	}

	(*vector)->capacity = capacity;
	(*vector)->count = 0;

	*succeeded = 1;
	return 1;
}

signed char Core_Containers_Vector_destroy(
	const struct Core_Containers_Vector* const * const vector,
	signed char* const succeeded)
{
	if (succeeded == NULL)
	{
		// TODO: log invalid `succeeded` parameter error!
		return 0;
	}

	if (vector == NULL)
	{
		// TODO: log invalid `vector` parameter error!
		*succeeded = 0;
		return 0;
	}

	if (*vector == NULL)
	{
		// TODO: log invalid `vector`'s deref parameter error!
		*succeeded = 0;
		return 0;
	}

	*succeeded = 0;

	W_Core_Memory_free((const void* const * const)(&((*vector)->data)), succeeded,
	{
		*succeeded = 0;
		return 0;
	},
	{
		// TODO: failed to deallocate vector's data!
		// *succeeded = 0;
		return 1;
	},
	{});

	W_Core_Memory_free((const void* const * const)vector, succeeded,
	{
		*succeeded = 0;
		return 0;
	},
	{
		// TODO: failed to deallocate vector!
		// *succeeded = 0;
		return 1;
	},
	{});

	*succeeded = 1;
	return 1;
}

signed char Core_Containers_Vector_get(
	const struct Core_Containers_Vector* const * const vector,
	const unsigned long long index,
	const void* const * const data,
	signed char* const succeeded)
{
	if (succeeded == NULL)
	{
		// TODO: log invalid `succeeded` parameter error!
		return 0;
	}

	if (vector == NULL)
	{
		// TODO: log invalid `vector` parameter error!
		*succeeded = 0;
		return 0;
	}

	if (*vector == NULL)
	{
		// TODO: log invalid `vector`'s deref parameter error!
		*succeeded = 0;
		return 0;
	}

	if (index >= (*vector)->count)
	{
		// TODO: log that provided function parameter `index` is out of bounds!
		*succeeded = 0;
		return 0;
	}

	if (data == NULL)
	{
		// TODO: log that provided function parameter `data` is invalid!
		*succeeded = 0;
		return 0;
	}

	const void** const inner = (const void** const)data;
	*inner = (*vector)->data[index];

	*succeeded = 1;
	return 1;
}

signed char Core_Containers_Vector_set(
	struct Core_Containers_Vector* const * const vector,
	const unsigned long long index,
	const void* const * const data,
	signed char* const succeeded)
{
	if (succeeded == NULL)
	{
		// TODO: log invalid `succeeded` parameter error!
		return 0;
	}

	if (vector == NULL)
	{
		// TODO: log invalid `vector` parameter error!
		*succeeded = 0;
		return 0;
	}

	if (*vector == NULL)
	{
		// TODO: log invalid `vector`'s deref parameter error!
		*succeeded = 0;
		return 0;
	}

	if (index >= (*vector)->count)
	{
		// TODO: log that provided function parameter `index` is out of bounds!
		*succeeded = 0;
		return 0;
	}

	if (data == NULL)
	{
		// TODO: log that provided function parameter `data` is invalid!
		*succeeded = 0;
		return 0;
	}

	const void** const inner = (const void** const)data;
	(*vector)->data[index] = (void*)(*inner);

	*succeeded = 1;
	return 1;
}

signed char Core_Containers_Vector_push(
	struct Core_Containers_Vector* const * const vector,
	const void* const * const data,
	signed char* const succeeded)
{
	if (succeeded == NULL)
	{
		// TODO: log invalid `succeeded` parameter error!
		return 0;
	}

	if (vector == NULL)
	{
		// TODO: log invalid `vector` parameter error!
		*succeeded = 0;
		return 0;
	}

	if (*vector == NULL)
	{
		// TODO: log invalid `vector`'s deref parameter error!
		*succeeded = 0;
		return 0;
	}

	if (data == NULL)
	{
		// TODO: log that provided function parameter `data` is invalid!
		*succeeded = 0;
		return 0;
	}

	*succeeded = 0;

	if ((*vector)->count + 1 > (*vector)->capacity)
	{
		const unsigned long long newCapacity = (*vector)->capacity + ((*vector)->capacity / 2);

		W_Core_Memory_realloc((const void* const * const)(&((*vector)->data)), newCapacity * sizeof(void*), succeeded,
		{
			*succeeded = 0;
			return 0;
		},
		{
			// TODO: failed to reallocate vector's data!
			// *succeeded = 0;
			return 1;
		},
		{});

		(*vector)->capacity = newCapacity;
	}

	const void** const inner = (const void** const)data;
	(*vector)->data[(*vector)->count++] = (void*)(*inner);

	*succeeded = 1;
	return 1;
}

signed char Core_Containers_Vector_shrink(
	struct Core_Containers_Vector* const * const vector,
	signed char* const succeeded)
{
	if (succeeded == NULL)
	{
		// TODO: log invalid `succeeded` parameter error!
		return 0;
	}

	if (vector == NULL)
	{
		// TODO: log invalid `vector` parameter error!
		*succeeded = 0;
		return 0;
	}

	if (*vector == NULL)
	{
		// TODO: log invalid `vector`'s deref parameter error!
		*succeeded = 0;
		return 0;
	}

	if ((*vector)->count >= (*vector)->capacity)
	{
		*succeeded = 1;
		return 1;
	}

	W_Core_Memory_realloc((const void* const * const)(&((*vector)->data)), (*vector)->count * sizeof(void*), succeeded,
	{
		*succeeded = 0;
		return 0;
	},
	{
		// TODO: failed to reallocate vector's data!
		// *succeeded = 0;
		return 1;
	},
	{});

	(*vector)->capacity = (*vector)->count;
	*succeeded = 1;
	return 1;
}

/**
 * @}
 */
