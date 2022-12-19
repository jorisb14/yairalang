
/**
 * @file core_containers_vector.c
 *
 * @copyright This file is a part of the project yarac and is distributed under GNU GPLv3 license
 * that should have been included with the project.
 * If not, see https://www.gnu.org/licenses/gpl-3.0.en.html
 *
 * @author jorisb14
 *
 * @date 2022-12-19
 */

#include <macros.h>

#include <core/containers/vector.h>
#include <core/containers/wrappers/vector.h>

#include <core/containers/list.h>
#include <core/containers/wrappers/list.h>

#include <core/containers/map.h>
#include <core/containers/wrappers/map.h>

NEW_TEST(core_containers_vector)
{
	DEFINE_LOCALS(core_containers_vector, test);

	signed char succeeded = 0;
	struct Core_Containers_Vector* vector = NULL;

	W_Core_Containers_Vector_create(&vector, 4, &succeeded,
	{
		ASSERT_TRUE(test, !"Internal failure");
		RETURN;
	},
	{
		ASSERT_TRUE(test, !"Logical failure");
		RETURN;
	},
	{});

	ASSERT_TRUE(test, vector != NULL);
	ASSERT_TRUE(test, vector->capacity == 4);
	ASSERT_TRUE(test, vector->count == 0);

	static signed int values[] = { 1, 2, 3, 4, 5 };
	static void* addresses[] = { values, values + 1, values + 2, values + 3, values + 4 };

	for (unsigned int i = 0; i < 5; ++i)
	{
		W_Core_Containers_Vector_push(&vector, (const void* const * const)(&(addresses[i])), &succeeded,
		{
			ASSERT_TRUE(test, !"Internal failure");
			RETURN;
		},
		{
			ASSERT_TRUE(test, !"Logical failure");
			RETURN;
		},
		{});
	}

	ASSERT_TRUE(test, vector->capacity == 6);
	ASSERT_TRUE(test, vector->count == 5);

	for (unsigned int i = 0; i < 5; ++i)
	{
		void* val = NULL;

		W_Core_Containers_Vector_get((const struct Core_Containers_Vector* const * const)&vector, i, (const void* const * const)&val, &succeeded,
		{
			ASSERT_TRUE(test, !"Internal failure");
			RETURN;
		},
		{
			ASSERT_TRUE(test, !"Logical failure");
			RETURN;
		},
		{});

		ASSERT_TRUE(test, val == addresses[i]);
		ASSERT_TRUE(test, *(signed int*)val == values[i]);
	}

	ASSERT_TRUE(test, vector->capacity == 6);
	ASSERT_TRUE(test, vector->count == 5);

	static signed int newValues[] = { 10, 20, 30, 40, 50 };
	static void* newAddresses[] = { newValues, newValues + 1, newValues + 2, newValues + 3, newValues + 4 };

	for (unsigned int i = 0; i < 5; ++i)
	{
		W_Core_Containers_Vector_set(&vector, i, (const void* const * const)(&(newAddresses[i])), &succeeded,
		{
			ASSERT_TRUE(test, !"Internal failure");
			RETURN;
		},
		{
			ASSERT_TRUE(test, !"Logical failure");
			RETURN;
		},
		{});
	}

	ASSERT_TRUE(test, vector->capacity == 6);
	ASSERT_TRUE(test, vector->count == 5);

	for (unsigned int i = 0; i < 5; ++i)
	{
		void* val = NULL;

		W_Core_Containers_Vector_get((const struct Core_Containers_Vector* const * const)&vector, i, (const void* const * const)&val, &succeeded,
		{
			ASSERT_TRUE(test, !"Internal failure");
			RETURN;
		},
		{
			ASSERT_TRUE(test, !"Logical failure");
			RETURN;
		},
		{});

		ASSERT_TRUE(test, val == newAddresses[i]);
		ASSERT_TRUE(test, *(signed int*)val == newValues[i]);
	}

	ASSERT_TRUE(test, vector->capacity == 6);
	ASSERT_TRUE(test, vector->count == 5);

	W_Core_Containers_Vector_shrink(&vector, &succeeded,
	{
		ASSERT_TRUE(test, !"Internal failure");
		RETURN;
	},
	{
		ASSERT_TRUE(test, !"Logical failure");
		RETURN;
	},
	{});

	ASSERT_TRUE(test, vector->capacity == 5);
	ASSERT_TRUE(test, vector->count == 5);

	W_Core_Containers_Vector_destroy((const struct Core_Containers_Vector* const * const)&vector, &succeeded,
	{
		ASSERT_TRUE(test, !"Internal failure");
		RETURN;
	},
	{
		ASSERT_TRUE(test, !"Logical failure");
		RETURN;
	},
	{});

	ASSERT_TRUE(test, vector == NULL);
}

NEW_TEST(core_containers_list)
{
	DEFINE_LOCALS(core_containers_list, test);

	signed char succeeded = 0;
	struct Core_Containers_List* list = NULL;

	W_Core_Containers_List_create(&list, &succeeded,
	{
		ASSERT_TRUE(test, !"Internal failure");
		RETURN;
	},
	{
		ASSERT_TRUE(test, !"Logical failure");
		RETURN;
	},
	{});

	ASSERT_TRUE(test, list != NULL);
	ASSERT_TRUE(test, list->head == NULL);
	ASSERT_TRUE(test, list->count == 0);

	static signed int values[] = { 1, 2, 3, 4, 5 };
	static void* addresses[] = { values, values + 1, values + 2, values + 3, values + 4 };

	for (unsigned int i = 0; i < 5; ++i)
	{
		W_Core_Containers_List_push(&list, (const void* const * const)(&(addresses[i])), &succeeded,
		{
			ASSERT_TRUE(test, !"Internal failure");
			RETURN;
		},
		{
			ASSERT_TRUE(test, !"Logical failure");
			RETURN;
		},
		{});
	}

	ASSERT_TRUE(test, list->head != NULL);
	ASSERT_TRUE(test, list->count == 5);

	{
		unsigned long long i = 0;

		for (struct Core_Containers_List_Node* iterator = list->head; iterator != NULL; iterator = iterator->next)
		{
			void* val = iterator->data;
			ASSERT_TRUE(test, val == addresses[i]);
			ASSERT_TRUE(test, *(signed int*)val == values[i]);
			++i;
		}
	}

	ASSERT_TRUE(test, list->head != NULL);
	ASSERT_TRUE(test, list->count == 5);

	W_Core_Containers_List_destroy((const struct Core_Containers_List* const * const)&list, &succeeded,
	{
		ASSERT_TRUE(test, !"Internal failure");
		RETURN;
	},
	{
		ASSERT_TRUE(test, !"Logical failure");
		RETURN;
	},
	{});

	ASSERT_TRUE(test, list == NULL);
}

NEW_TEST(core_containers_map)
{
	DEFINE_LOCALS(core_containers_map, test);

	signed char succeeded = 0;
	struct Core_Containers_Map* map = NULL;

	W_Core_Containers_Map_create(&map, 4, &succeeded,
	{
		ASSERT_TRUE(test, !"Internal failure");
		RETURN;
	},
	{
		ASSERT_TRUE(test, !"Logical failure");
		RETURN;
	},
	{});

	ASSERT_TRUE(test, map != NULL);
	ASSERT_TRUE(test, map->nodes != NULL);
	ASSERT_TRUE(test, map->capacity == 4);
	ASSERT_TRUE(test, map->count == 0);

	W_Core_Containers_Map_destroy((const struct Core_Containers_Map* const * const)&map, &succeeded,
	{
		ASSERT_TRUE(test, !"Internal failure");
		RETURN;
	},
	{
		ASSERT_TRUE(test, !"Logical failure");
		RETURN;
	},
	{});

	ASSERT_TRUE(test, map == NULL);
}

NEW_SUITE(core_containers)
{
	RUN_TEST(core_containers_vector);
	RUN_TEST(core_containers_list);
	RUN_TEST(core_containers_map);
}
