
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

// TODO: document!
struct Core_Containers_Vector
{
	void** data;
	unsigned long long capacity;
	unsigned long long count;
};

// TODO: document!
signed char Core_Containers_Vector_create(
	struct Core_Containers_Vector** const vector,
	const unsigned long long capacity,
	signed char* const succeeded);

// TODO: document!
signed char Core_Containers_Vector_destroy(
	const struct Core_Containers_Vector* const * const vector,
	signed char* const succeeded);

// TODO: document!
signed char Core_Containers_Vector_get(
	const struct Core_Containers_Vector* const * const vector,
	const unsigned long long index,
	const void* const * const data,
	signed char* const succeeded);

// TODO: document!
signed char Core_Containers_Vector_set(
	struct Core_Containers_Vector* const * const vector,
	const unsigned long long index,
	const void* const * const data,
	signed char* const succeeded);

// TODO: document!
signed char Core_Containers_Vector_push(
	struct Core_Containers_Vector* const * const vector,
	const void* const * const data,
	signed char* const succeeded);

// TODO: document!
signed char Core_Containers_Vector_shrink(
	struct Core_Containers_Vector* const * const vector,
	signed char* const succeeded);

/**
 * @}
 */

#endif
