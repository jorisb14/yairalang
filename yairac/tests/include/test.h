
/**
 * @file test.h
 *
 * @copyright This file is a part of the project yairac and is distributed under GNU GPLv3 license
 * that should have been included with the project.
 * If not, see https://www.gnu.org/licenses/gpl-3.0.en.html
 *
 * @author jorisb14
 *
 * @date 2022-12-21
 */

#ifndef _YAIRAC_TESTS_INCLUDE_TEST_H_
#define _YAIRAC_TESTS_INCLUDE_TEST_H_

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * @addtogroup test
 * 10
 * @{
 */

#define RED(_inmacro_string) \
	"\033[0;31m" _inmacro_string "\033[0m"

#define YELLOW(_inmacro_string) \
	"\033[0;33m" _inmacro_string "\033[0m"

#define GRAY(_inmacro_string) \
	"\033[0;90m" _inmacro_string "\033[0m"

#define GREEN(_inmacro_string) \
	"\033[0;32m" _inmacro_string "\033[0m"

#define LOG(_inmacro_message) \
	fprintf(stdout, "%s\n", _inmacro_message)

#define LOG_DEBUG(_inmacro_message) \
	fprintf(stdout, "%s:%llu: [%-18s]: %s\n", (const char*)__FILE__, (unsigned long long)__LINE__, GRAY("debug"), _inmacro_message)

#define LOG_SUCCESS(_inmacro_message) \
	fprintf(stdout, "%s:%llu: [%-7s]: %s\n", (const char*)__FILE__, (unsigned long long)__LINE__, GREEN("success"), _inmacro_message)

#define LOG_INFO(_inmacro_message) \
	fprintf(stdout, "%s:%llu: [%-7s]: %s\n", (const char*)__FILE__, (unsigned long long)__LINE__, "info", _inmacro_message)

#define LOG_WARNING(_inmacro_message) \
	fprintf(stdout, "%s:%llu: [%-7s]: %s\n", (const char*)__FILE__, (unsigned long long)__LINE__, YELLOW("warning"), _inmacro_message)

#define LOG_ERROR(_inmacro_message) \
	fprintf(stdout, "%s:%llu: [%-18s]: %s\n", (const char*)__FILE__, (unsigned long long)__LINE__, RED("error"), _inmacro_message)

#define EMPTY_LINE \
	LOG_DEBUG("")

#define TAB \
	"    "

#define RETURN \
	return

#define EXIT \
	exit(0)

#define NONE \
	{ }

#define STRLEN(_inmacro_string) \
	(strlen((_inmacro_string)))

#define STREQL(_inmacro_a, _inmacro_b) \
	(strcmp((_inmacro_a), (_inmacro_b)) == 0)

#define ASSERT_TRUE(_inmacro_expression, _inmacro_onFailure, _inmacro_onSuccess) \
	{ \
		if (!(_inmacro_expression)) \
		{ \
			_inmacro_onFailure; \
		} \
		else \
		{ \
			_inmacro_onSuccess \
		} \
	}

#define ASSERT_FALSE(_inmacro_expression, _inmacro_onFailure, _inmacro_onSuccess) \
	{ \
		if ((_inmacro_expression)) \
		{ \
			_inmacro_onFailure; \
		} \
		else \
		{ \
			_inmacro_onSuccess \
		} \
	}

#define ASSERT_EQUAL(_inmacro_a, _inmacro_b, _inmacro_onFailure, _inmacro_onSuccess) \
	{ \
		if ((a) != (b)) \
		{ \
			_inmacro_onFailure; \
		} \
		else \
		{ \
			_inmacro_onSuccess \
		} \
	}

#define ASSERT_NOT_EQUAL(_inmacro_a, _inmacro_b, _inmacro_onFailure, _inmacro_onSuccess) \
	{ \
		if ((a) == (b)) \
		{ \
			_inmacro_onFailure; \
		} \
		else \
		{ \
			_inmacro_onSuccess \
		} \
	}

struct Tests_Test
{
	const char* name;
	void(*function)(void);
};

#define TEST_NEW(_inmacro_name) \
	static void _inmacro_name ## _function( \
		void); \
	 \
	static const struct Tests_Test _inmacro_name ## _test = \
	{ \
		#_inmacro_name, \
		_inmacro_name ## _function \
	}; \
	 \
	static void _inmacro_name ## _function( \
		void)

#define TEST_ADD(_inmacro_name) \
	(&(_inmacro_name ## _test))

#define SUITE_NEW(_inmacro_name) \
	static void _inmacro_name ## _function( \
		const struct Tests_Test** const suite) \
	{ \
		if (suite == NULL) \
		{ \
			LOG_ERROR("internal failure: provided `suite` parameter was invalid (null)!"); \
			exit(1); \
		} \
		 \
		for (const struct Tests_Test** test = suite; test != NULL && *test != NULL; ++test) \
		{ \
			if (*test == NULL) \
			{ \
				LOG_ERROR("internal failure: while iterating through tests, encountered an invalid one (null)!"); \
				exit(1); \
			} \
			 \
			(*test)->function(); \
		} \
	} \
	 \
	static const struct Tests_Test* _inmacro_name ## _suite[] =

#define SUITE_END \
	NULL

#define SUITE_RUN(_inmacro_name) \
	_inmacro_name ## _function(((const struct Tests_Test** const)(_inmacro_name ## _suite)))

#define ENTRY \
	int main( \
		void)

/**
 * @}
 */

#endif

