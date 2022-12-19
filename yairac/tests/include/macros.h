
/**
 * @file macros.h
 *
 * @copyright This file is a part of the project yarac and is distributed under GNU GPLv3 license
 * that should have been included with the project.
 * If not, see https://www.gnu.org/licenses/gpl-3.0.en.html
 *
 * @author jorisb14
 *
 * @date 2022-12-18
 */

#ifndef _YAIRAC_TESTS_INCLUDE_MACROS_H_
#define _YAIRAC_TESTS_INCLUDE_MACROS_H_

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * @addtogroup tests
 * 
 * @{
 */

typedef void(*TFunc)(void);

struct Tests_Test_Result
{
	const char* name;
	signed char result;
};

struct Tests_Test
{
	const char* name;
	TFunc function;

	const char* file;
	unsigned long long line;

	#define subtestsCapacity 128
	struct Tests_Test_Result subtests[subtestsCapacity];
	unsigned long long subtestsCount;
};

#define RED(str) "\033[0;31m"str"\033[0m"

#define YELLOW(str) "\033[0;33m"str"\033[0m"

#define GREEN(str) "\033[0;32m"str"\033[0m"

#define RETURN return

#define STREQL(a, b, l) (strncmp(a, b, l) == 0)

#define STRLEN(a) (strlen(a))

#define NONE NULL

#define NEW_TEST(_inmacro_testName) \
	static void _inmacro_testName ## _validate( \
		struct Tests_Test* const test); \
	 \
	static void _inmacro_testName ## _execute( \
		void); \
	 \
	static struct Tests_Test _inmacro_testName ## _test = \
		{ \
			""# _inmacro_testName, \
			_inmacro_testName ## _execute, \
			(const char*)__FILE__, \
			(unsigned long long)__LINE__, \
			{ {0} }, \
			0 \
		}; \
	 \
	static void _inmacro_testName ## _validate( \
		struct Tests_Test* const test) \
	{ \
		assert(test != NULL); \
		test->function(); \
		 \
		{ \
			fprintf(stdout, "+---+-------------------------------------------------------------------------+\n"); \
			fprintf(stdout, "|   | Running test:                                                           |\n"); \
			fprintf(stdout, "|   |  > %-68s |\n", test->name); \
			fprintf(stdout, "|   +-------------------------------------------------------------------------+\n"); \
			\
			unsigned long long passedCount = 0; \
			unsigned long long failedCount = 0; \
			\
			if (test->subtestsCount > 0) \
			{ \
				for (unsigned long long i = 0; i < test->subtestsCount; ++i) \
				{ \
					if (!(test->subtests[i].result)) \
					{ \
						++failedCount; \
					} \
					else \
					{ \
						++passedCount; \
					} \
					\
					fprintf(stdout, "|   |   +-------------------------------------------------------------------------+\n"); \
					fprintf(stdout, "|   +---| Running subtest:                                                        |\n"); \
					fprintf(stdout, "|   |   |  > %-68s |\n", test->subtests[i].name); \
					fprintf(stdout, "|   |   + - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - +\n"); \
					fprintf(stdout, "|   |   | Finished with result:                                                   |\n"); \
					fprintf(stdout, "|   |   |  > %-79s |\n", test->subtests[i].result ? GREEN("passed") : RED("failed")); \
				} \
				\
				fprintf(stdout, "|   |   +-------------------------------------------------------------------------+\n"); \
				fprintf(stdout, "|   +-------------------------------------------------------------------------+\n"); \
			} \
			\
			fprintf(stdout, "|   | End result:                                                             |\n"); \
			fprintf(stdout, "|   |  > %llu %-77s |\n", passedCount, GREEN("passed")); \
			fprintf(stdout, "|   |  > %llu %-77s |\n", failedCount, RED("failed")); \
			fprintf(stdout, "+---+-------------------------------------------------------------------------+\n"); \
		} \
		 \
		if (1) \
		{ \
			char path[256 + 1] = {0}; \
			memcpy(path, "./logs/", 7); \
			memcpy(path + 7, (const char*)(#_inmacro_testName), strlen((const char*)(#_inmacro_testName))); \
			memcpy(path + 7 + strlen((const char*)(#_inmacro_testName)), ".log", 4); \
			FILE* file = fopen(path, "w"); \
			assert(file != NULL); \
			\
			fprintf(file, "+---+-------------------------------------------------------------------------+\n"); \
			fprintf(file, "|   | Running test:                                                           |\n"); \
			fprintf(file, "|   |  > %-68s |\n", test->name); \
			fprintf(file, "|   +-------------------------------------------------------------------------+\n"); \
			\
			unsigned long long passedCount = 0; \
			unsigned long long failedCount = 0; \
			\
			if (test->subtestsCount > 0) \
			{ \
				for (unsigned long long i = 0; i < test->subtestsCount; ++i) \
				{ \
					if (!(test->subtests[i].result)) \
					{ \
						++failedCount; \
					} \
					else \
					{ \
						++passedCount; \
					} \
					\
					fprintf(file, "|   |   +-------------------------------------------------------------------------+\n"); \
					fprintf(file, "|   +---| Running subtest:                                                        |\n"); \
					fprintf(file, "|   |   |  > %-68s |\n", test->subtests[i].name); \
					fprintf(file, "|   |   + - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - +\n"); \
					fprintf(file, "|   |   | Finished with result:                                                   |\n"); \
					fprintf(file, "|   |   |  > %-68s |\n", test->subtests[i].result ? "passed" : "failed"); \
				} \
				\
				fprintf(file, "|   |   +-------------------------------------------------------------------------+\n"); \
				fprintf(file, "|   +-------------------------------------------------------------------------+\n"); \
			} \
			\
			fprintf(file, "|   | End result:                                                             |\n"); \
			fprintf(file, "|   |  > %llu %-66s |\n", passedCount, "passed"); \
			fprintf(file, "|   |  > %llu %-66s |\n", failedCount, "failed"); \
			fprintf(file, "+---+-------------------------------------------------------------------------+\n"); \
			fclose(file); \
		} \
	} \
	 \
	static void _inmacro_testName ## _execute( \
		void)

#define DEFINE_LOCALS(_inmacro_testName, _inmacro_test) \
	struct Tests_Test* const _inmacro_test = &(_inmacro_testName ## _test); \
	assert(_inmacro_test != NULL)

#define ASSERT_TRUE(_inmacro_test, _inmacro_expression) \
	assert(_inmacro_test != NULL); \
	 \
	if ((_inmacro_test)->subtestsCount + 1 > subtestsCapacity) \
	{ \
		fprintf(stdout, "Failed to add assert_true subtest - exceeding subtests capacity!\n"); \
		exit(1); \
	} \
	 \
	(_inmacro_test)->subtests[(_inmacro_test)->subtestsCount++] = (struct Tests_Test_Result) { .name = "assert_true -> " #_inmacro_expression, .result = (_inmacro_expression) }

#define ASSERT_FALSE(_inmacro_test, _inmacro_expression) \
	assert(_inmacro_test != NULL); \
	 \
	if ((_inmacro_test)->subtestsCount + 1 > subtestsCapacity) \
	{ \
		fprintf(stdout, "Failed to add assert_false subtest - exceeding subtests capacity!\n"); \
		exit(1); \
	} \
	 \
	(_inmacro_test)->subtests[(_inmacro_test)->subtestsCount++] = (struct Tests_Test_Result) { .name = "assert_false -> " #_inmacro_expression, .result = (!(_inmacro_expression)) }

#define RUN_TEST(_inmacro_testName) \
	_inmacro_testName ## _validate(&(_inmacro_testName ## _test));

#define NEW_SUITE(_inmacro_suiteName) \
	static void _inmacro_suiteName ## _func( \
		void); \
	 \
	int main( \
		void) \
	{ \
		_inmacro_suiteName ## _func(); \
		return 1; \
	} \
	 \
	static void _inmacro_suiteName ## _func( \
		void)

/**
 * @}
 */

#endif
