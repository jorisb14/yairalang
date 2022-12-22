
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

#ifndef _YAIRAC_INCLUDE_CORE_CONTAINERS_VECTOR_H_
#define _YAIRAC_INCLUDE_CORE_CONTAINERS_VECTOR_H_

/**
 * @addtogroup containers
 * 
 * @{
 */

/**
 * The vector data structure. It contains the pointer to it's memory block, the count of the items
 * added to it, and it's capacity.
 * 
 * It grows with the added items at the rate of capacity + capacity / 2.
 */
struct Core_Containers_Vector
{
	void** data;
	unsigned long long capacity;
	unsigned long long count;
};

/**
 * Create a dynamic vector container. Return 0 in case of an internal error and 1 otherwise. The
 * parameter `succeeded` indicates logic level errors. Should be used as this:
 * 
 * @code{.c}
 *     struct Core_Containers_Vector* vector = NULL;
 *     signed char succeeded = 0;
 *     assert(Core_Containers_Vector_create(&vector, 10, &succeeded) == 1);
 *     assert(succeeded == 1);
 * @endcode
 */
signed char Core_Containers_Vector_create(
	struct Core_Containers_Vector** const vector,
	const unsigned long long capacity,
	signed char* const succeeded);

/**
 * Destroy the dynamic vector container. Return 0 in case of an internal error and 1 otherwise. The
 * parameter `succeeded` indicates logic level errors. Should be used as this:
 * 
 * @code{.c}
 *     struct Core_Containers_Vector* vector = NULL;
 *     signed char succeeded = 0;
 *     assert(Core_Containers_Vector_destroy((const struct Core_Containers_Vector* const * const)&vector, &succeeded) == 1);
 *     assert(succeeded == 1);
 * @endcode
 */
signed char Core_Containers_Vector_destroy(
	const struct Core_Containers_Vector* const * const vector,
	signed char* const succeeded);

/**
 * Get an element from the vector at specified index. Return 0 in case of an internal error and 1
 * otherwise. The parameter `succeeded` indicates logic level errors. Should be used as this:
 * 
 * @code{.c}
 *     struct Core_Containers_Vector* vector = NULL;
 *     void* data = NULL;
 *     signed char succeeded = 0;
 *     assert(Core_Containers_Vector_get(&vector, 0, (const void* const * const)&data, &succeeded) == 1);
 *     assert(succeeded == 1);
 * @endcode
 */
signed char Core_Containers_Vector_get(
	const struct Core_Containers_Vector* const * const vector,
	const unsigned long long index,
	const void* const * const data,
	signed char* const succeeded);

/**
 * Set an element in the vector at specified index. Return 0 in case of an internal error and 1
 * otherwise. The parameter `succeeded` indicates logic level errors. Should be used as this:
 * 
 * @code{.c}
 *     struct Core_Containers_Vector* vector = NULL;
 *     signed char succeeded = 0;
 *     assert(Core_Containers_Vector_set(&vector, 0, (const void* const * const)&data, &succeeded) == 1);
 *     assert(succeeded == 1);
 * @endcode
 */
signed char Core_Containers_Vector_set(
	struct Core_Containers_Vector* const * const vector,
	const unsigned long long index,
	const void* const * const data,
	signed char* const succeeded);

/**
 * Push new element into the vector at specified index. Return 0 in case of an internal error and 1
 * otherwise. The parameter `succeeded` indicates logic level errors. Should be used as this:
 * 
 * @code{.c}
 *     struct Core_Containers_Vector* vector = NULL;
 *     signed char succeeded = 0;
 *     assert(Core_Containers_Vector_push(&vector, (const void* const * const)&data, &succeeded) == 1);
 *     assert(succeeded == 1);
 * @endcode
 */
signed char Core_Containers_Vector_push(
	struct Core_Containers_Vector* const * const vector,
	const void* const * const data,
	signed char* const succeeded);

/**
 * Shrink a vector container to it's count. Return 0 in case of an internal error and 1 otherwise.
 * The parameter `succeeded` indicates logic level errors. Should be used as this:
 * 
 * @code{.c}
 *     struct Core_Containers_Vector* vector = NULL;
 *     signed char succeeded = 0;
 *     assert(Core_Containers_Vector_shrink(&vector, &succeeded) == 1);
 *     assert(succeeded == 1);
 * @endcode
 */
signed char Core_Containers_Vector_shrink(
	struct Core_Containers_Vector* const * const vector,
	signed char* const succeeded);

/**
 * @}
 */

#endif
