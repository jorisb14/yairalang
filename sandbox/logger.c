
/**
 * @file logger.c
 *
 * @copyright This file is a part of the project yarac and is distributed under GNU GPLv3 license
 * that should have been included with the project.
 * If not, see https://www.gnu.org/licenses/gpl-3.0.en.html
 *
 * @author jorisb14
 *
 * @date 2022-12-20
 */

#include <execinfo.h>
#include <signal.h>
#include <assert.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

enum
{
	LOG_KIND_DEBUG = 0,
	LOG_KIND_INFO,
	LOG_KIND_WARN,
	LOG_KIND_ERROR,

	LOG_KINDS_COUNT
};

struct Trace
{
	void* line;
};

struct Stack
{
	#define tracesCapacity 128
	struct Trace traces[tracesCapacity];
	unsigned long long tracesCount;
};

struct Log
{
	unsigned long long kind;

	struct Stack stackTrace;
};

void print_trace(
	const char* program)
{
	/*
	void *array[10];
	size_t size;

	// get void*'s for all entries on the stack
	size = backtrace(array, 10);

	// print out all the frames to stderr
	backtrace_symbols_fd(array, size, STDERR_FILENO);
	*/

	void *array[10];
	char **strings;
	int size, i;

	size = backtrace (array, 10);
	strings = backtrace_symbols (array, size);
	if (strings == NULL)
	{
		return;
	}

	printf ("Obtained %d stack frames.\n", size);
	for (i = 0; i < size; i++) {
		char addr2line_cmd[512] = {0};
		// fprintf(stdout, "%s\n", (const char*)array);
		// fprintf(stdout, "%s\n", (const char*)strings[i]);
		// fprintf(stdout, "%p\n", (void*)array[i]);
		// sprintf(addr2line_cmd,"addr2line -f -p -e %p %.256s", (void*)(array[i]), program);
		sprintf(addr2line_cmd,"addr2line -a -f --exe=%p %.256s", (void*)(array[i]), program);
		// fprintf(stdout, "%s\n", addr2line_cmd);
		assert(system(addr2line_cmd) != 0);
		// printf("%s\n\n", strings[i]);
	}

	free (strings);
}

static int global = 1;

void dummy(
	const char* p)
{
	int i = 0;
	i++;
	global *= i;
	print_trace(p);
}

int main(
	const int argc,
	const char* argv[])
{
	(void)argc;
	(void)argv;

	dummy(argv[0]);
	// dummy(argv[0]);
	// dummy(argv[0]);

	fprintf(stdout, "%d", global);

	return 0;
}
