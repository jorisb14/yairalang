
/**
 * @file core_memory_test.c
 *
 * @copyright This file is a part of the project yarac and is distributed under GNU GPLv3 license
 * that should have been included with the project.
 * If not, see https://www.gnu.org/licenses/gpl-3.0.en.html
 *
 * @author jorisb14
 *
 * @date 2022-12-21
 */

#include <test.h>

#include <core/memory.h>

TEST_NEW(core_memory_malloc)
{
	LOG_INFO("running test 'core_memory_malloc'...");

	unsigned char* data = NULL;
	signed char succeeded = 0;

	W_Core_Memory_malloc((const void* const * const)&data, 10 * sizeof(unsigned char), &succeeded, { }, { }, { });
	ASSERT_TRUE(data != NULL,
	{
		LOG_ERROR(TAB"failed to allocate a block of memory using W_Core_Memory_malloc!");
	},
	{
		LOG_SUCCESS(TAB"successfully allocated a block of memory using W_Core_Memory_malloc!");
	});

	EMPTY_LINE;
}

TEST_NEW(core_memory_realloc)
{
	LOG_INFO("running test 'core_memory_realloc'...");

	unsigned char* data = NULL;
	signed char succeeded = 0;

	W_Core_Memory_malloc((const void* const * const)&data, 10 * sizeof(unsigned char), &succeeded, { }, { }, { });
	ASSERT_TRUE(data != NULL,
	{
		LOG_ERROR(TAB"failed to allocate a block of memory using W_Core_Memory_malloc!");
	},
	{
		LOG_SUCCESS(TAB"successfully allocated a block of memory using W_Core_Memory_malloc!");
	});

	W_Core_Memory_realloc((const void* const * const)&data, 20 * sizeof(unsigned char), &succeeded, { }, { }, { });
	ASSERT_TRUE(data != NULL,
	{
		LOG_ERROR(TAB"failed to reallocate a block of memory using W_Core_Memory_realloc!");
	},
	{
		LOG_SUCCESS(TAB"successfully reallocated a block of memory using W_Core_Memory_realloc!");
	});

	W_Core_Memory_free((const void* const * const)&data, &succeeded, { }, { }, { });
	ASSERT_TRUE(data == NULL,
	{
		LOG_ERROR(TAB"failed to deallocate a block of memory using W_Core_Memory_free!");
	},
	{
		LOG_SUCCESS(TAB"successfully deallocated a block of memory using W_Core_Memory_free!");
	});

	EMPTY_LINE;
}

TEST_NEW(core_memory_free)
{
	LOG_INFO("running test 'core_memory_free'...");

	unsigned char* data = NULL;
	signed char succeeded = 0;

	W_Core_Memory_malloc((const void* const * const)&data, 10 * sizeof(unsigned char), &succeeded, { }, { }, { });
	ASSERT_TRUE(data != NULL,
	{
		LOG_ERROR(TAB"failed to allocate a block of memory using W_Core_Memory_malloc!");
	},
	{
		LOG_SUCCESS(TAB"successfully allocated a block of memory using W_Core_Memory_malloc!");
	});

	W_Core_Memory_free((const void* const * const)&data, &succeeded, { }, { }, { });
	ASSERT_TRUE(data == NULL,
	{
		LOG_ERROR(TAB"failed to deallocate a block of memory using W_Core_Memory_free!");
	},
	{
		LOG_SUCCESS(TAB"successfully deallocated a block of memory using W_Core_Memory_free!");
	});

	EMPTY_LINE;
}

SUITE_NEW(core_memory)
{
	TEST_ADD(core_memory_malloc),
	TEST_ADD(core_memory_realloc),
	TEST_ADD(core_memory_free),
	SUITE_END
};

ENTRY
{
	SUITE_RUN(core_memory);
	EXIT;
}
