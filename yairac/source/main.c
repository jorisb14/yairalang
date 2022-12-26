
/**
 * @file main.c
 *
 * @copyright This file is a part of the project yairac and is distributed under GNU GPLv3 license
 * that should have been included with the project.
 * If not, see https://www.gnu.org/licenses/gpl-3.0.en.html
 *
 * @author jorisb14
 *
 * @date 2022-12-17
 */

#include <core/memory/null.h>

#include <core/memory/malloc.h>
#include <core/memory/wrappers/malloc.h>

#include <core/memory/malloc.h>
#include <core/memory/wrappers/malloc.h>

#include <core/memory/realloc.h>
#include <core/memory/wrappers/realloc.h>

#include <core/memory/free.h>
#include <core/memory/wrappers/free.h>

#include <core/containers/vector.h>
#include <core/containers/wrappers/vector.h>

#include <core/containers/list.h>
#include <core/containers/wrappers/list.h>

#include <core/containers/map.h>
#include <core/containers/wrappers/map.h>

// C standard library headers
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(
	int argc,
	char** argv)
{
	(void)(argc);
	(void)(argv);
	fprintf(stdout, "Hello from yairac!\n");
	return 0;
}

