
/**
 * @file main.c
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
#include <core/containers/wrappers/vector.h>

#include <core/containers/list.h>
#include <core/containers/wrappers/list.h>

// C standard library headers
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
