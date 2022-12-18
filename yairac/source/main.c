
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

#include <core/containers/map.h>
#include <core/containers/wrappers/map.h>

// C standard library headers
#include <stdio.h>

int main(
	int argc,
	char** argv)
{
	(void)(argc);
	(void)(argv);
	fprintf(stdout, "Hello from yairac!\n");

	signed char succeeded = 0;
	struct Core_Containers_Vector* vector = NULL;

	W_Core_Containers_Vector_create(&vector, 4, &succeeded, {}, {}, {});

	static int val = 0;

	for (int i = 0; i < 10; ++i)
	{
		fprintf(stdout, "%llu\n", vector->capacity);
		W_Core_Containers_Vector_push(&vector, (const void* const * const)&val, &succeeded, {}, {}, {});
	}

	fprintf(stdout, "%llu\n", vector->capacity);
	W_Core_Containers_Vector_shrink(&vector, &succeeded, {}, {}, {});
	fprintf(stdout, "%llu\n", vector->capacity);

	W_Core_Containers_Vector_destroy((const struct Core_Containers_Vector* const * const)&vector, &succeeded, {}, {}, {});

	struct Core_Containers_List* list = NULL;
	W_Core_Containers_List_create(&list, &succeeded, {}, {}, {});
	W_Core_Containers_List_destroy((const struct Core_Containers_List* const * const)&list, &succeeded, {}, {}, {});

	return 0;
}
