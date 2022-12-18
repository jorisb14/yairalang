
/**
 * @file core_memory_test.c
 *
 * @copyright This file is a part of the project yarac and is distributed under GNU GPLv3 license
 * that should have been included with the project.
 * If not, see https://www.gnu.org/licenses/gpl-3.0.en.html
 *
 * @author jorisb14
 *
 * @date 2022-12-18
 */

#include <macros.h>

#include <core/memory.h>

struct Data64
{
	char bytes[64];
};

NEW_TEST(core_memory_malloc)
{
	DEFINE_LOCALS(core_memory_malloc, test);

	struct Data64* data = NULL;
	signed char succeeded = 0;

	W_Core_Memory_malloc((const void* const * const)&data, sizeof(struct Data64), &succeeded, {}, {}, {});
	ASSERT_TRUE(test, data != NULL);

	W_Core_Memory_free((const void* const * const)&data, &succeeded, {}, {}, {});
	ASSERT_TRUE(test, data == NULL);
}

NEW_TEST(core_memory_realloc)
{
	DEFINE_LOCALS(core_memory_realloc, test);

	struct Data64* data = NULL;
	signed char succeeded = 0;

	W_Core_Memory_realloc((const void* const * const)&data, sizeof(struct Data64), &succeeded, {}, {}, {});
	ASSERT_TRUE(test, data != NULL);
}

NEW_TEST(core_memory_free)
{
	DEFINE_LOCALS(core_memory_free, test);

	ASSERT_TRUE(test, 1 == 1);
}

NEW_SUITE(my_suite)
{
	RUN_TEST(core_memory_malloc);
	RUN_TEST(core_memory_realloc);
	RUN_TEST(core_memory_free);
}
