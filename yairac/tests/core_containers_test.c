
/**
 * @file core_containers_test.c
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

#include <core/containers.h>

TEST_NEW(core_containers_vector)
{
	LOG_INFO("running test 'core_containers_vector'...");

	signed char succeeded = 0;
	struct Core_Containers_Vector* vector = NULL;

	W_Core_Containers_Vector_create(&vector, 4, &succeeded, { }, { }, { });

	ASSERT_TRUE(vector != NULL,
	{
		LOG_ERROR(TAB"failed to create a vector using W_Core_Containers_Vector_create!");
	},
	{
		LOG_SUCCESS(TAB"successfully created a vector using W_Core_Containers_Vector_create!");
	});

	ASSERT_TRUE(vector->data != NULL,
	{
		LOG_ERROR(TAB"failed to create the vector's data!");
	},
	{
		LOG_SUCCESS(TAB"successfully created the vector's data!");
	});

	ASSERT_TRUE(vector->capacity == 4,
	{
		LOG_ERROR(TAB"failed to set the capacity of the vector to 4!");
	},
	{
		LOG_SUCCESS(TAB"successfully set the capacity of the vector to 4!");
	});

	ASSERT_TRUE(vector->count == 0,
	{
		LOG_ERROR(TAB"failed to set the count of the vector to 4!");
	},
	{
		LOG_SUCCESS(TAB"successfully set the count of the vector to 4!");
	});

	static signed int values[] = { 1, 2, 3, 4, 5 };
	static void* addresses[] = { values, values + 1, values + 2, values + 3, values + 4 };

	for (unsigned int i = 0; i < 5; ++i)
	{
		W_Core_Containers_Vector_push(&vector, (const void* const * const)(&(addresses[i])), &succeeded, { }, { }, { });
	}

	ASSERT_TRUE(vector->capacity == 6,
	{
		LOG_ERROR(TAB"failed to update the capacity of the vector to 6!");
	},
	{
		LOG_SUCCESS(TAB"successfully updated the capacity of the vector to 6!");
	});

	ASSERT_TRUE(vector->count == 5,
	{
		LOG_ERROR(TAB"failed to update the count of the vector to 5!");
	},
	{
		LOG_SUCCESS(TAB"successfully updated the count of the vector to 5!");
	});

	for (unsigned int i = 0; i < 5; ++i)
	{
		void* val = NULL;
		W_Core_Containers_Vector_get((const struct Core_Containers_Vector* const * const)&vector, i, (const void* const * const)&val, &succeeded, { }, { }, { });

		ASSERT_TRUE(val == addresses[i],
		{
			LOG_ERROR(TAB"failed to get a correct value from the vector using W_Core_Containers_Vector_get!");
		},
		{
			LOG_SUCCESS(TAB"successfully got the correct value from the vector using W_Core_Containers_Vector_get!");
		});

		ASSERT_TRUE(*(signed int*)val == values[i],
		{
			LOG_ERROR(TAB"failed to get a correct value from the vector using W_Core_Containers_Vector_get!");
		},
		{
			LOG_SUCCESS(TAB"successfully got the correct value from the vector using W_Core_Containers_Vector_get!");
		});
	}

	ASSERT_TRUE(vector->capacity == 6,
	{
		LOG_ERROR(TAB"failed to not change the capacity of the vector to 6!");
	},
	{
		LOG_SUCCESS(TAB"successfully did not change the capacity of the vector to 6!");
	});

	ASSERT_TRUE(vector->count == 5,
	{
		LOG_ERROR(TAB"failed to not change the count of the vector to 5!");
	},
	{
		LOG_SUCCESS(TAB"successfully did not change the count of the vector to 5!");
	});

	static signed int newValues[] = { 10, 20, 30, 40, 50 };
	static void* newAddresses[] = { newValues, newValues + 1, newValues + 2, newValues + 3, newValues + 4 };

	for (unsigned int i = 0; i < 5; ++i)
	{
		W_Core_Containers_Vector_set(&vector, i, (const void* const * const)(&(newAddresses[i])), &succeeded, { }, { }, { });
	}

	ASSERT_TRUE(vector->capacity == 6,
	{
		LOG_ERROR(TAB"failed to not change the capacity of the vector to 6!");
	},
	{
		LOG_SUCCESS(TAB"successfully did not change the capacity of the vector to 6!");
	});

	ASSERT_TRUE(vector->count == 5,
	{
		LOG_ERROR(TAB"failed to not change the count of the vector to 5!");
	},
	{
		LOG_SUCCESS(TAB"successfully did not change the count of the vector to 5!");
	});

	for (unsigned int i = 0; i < 5; ++i)
	{
		void* val = NULL;
		W_Core_Containers_Vector_get((const struct Core_Containers_Vector* const * const)&vector, i, (const void* const * const)&val, &succeeded, { }, { }, { });

		ASSERT_TRUE(val == newAddresses[i],
		{
			LOG_ERROR(TAB"failed to get a correct value from the vector using W_Core_Containers_Vector_get!");
		},
		{
			LOG_SUCCESS(TAB"successfully got the correct value from the vector using W_Core_Containers_Vector_get!");
		});

		ASSERT_TRUE(*(signed int*)val == newValues[i],
		{
			LOG_ERROR(TAB"failed to get a correct value from the vector using W_Core_Containers_Vector_get!");
		},
		{
			LOG_SUCCESS(TAB"successfully got the correct value from the vector using W_Core_Containers_Vector_get!");
		});
	}

	ASSERT_TRUE(vector->capacity == 6,
	{
		LOG_ERROR(TAB"failed to not change the capacity of the vector to 6!");
	},
	{
		LOG_SUCCESS(TAB"successfully did not change the capacity of the vector to 6!");
	});

	ASSERT_TRUE(vector->count == 5,
	{
		LOG_ERROR(TAB"failed to not change the count of the vector to 5!");
	},
	{
		LOG_SUCCESS(TAB"successfully did not change the count of the vector to 5!");
	});

	W_Core_Containers_Vector_shrink(&vector, &succeeded, { }, { }, { });

	ASSERT_TRUE(vector->capacity == 5,
	{
		LOG_ERROR(TAB"failed to shrink the vector to the capacity of 5!");
	},
	{
		LOG_SUCCESS(TAB"successfully shrank the vector to the capacity of 5!");
	});

	ASSERT_TRUE(vector->count == 5,
	{
		LOG_ERROR(TAB"failed to not change the count of the vector to 5!");
	},
	{
		LOG_SUCCESS(TAB"successfully did not change the count of the vector to 5!");
	});

	W_Core_Containers_Vector_destroy((const struct Core_Containers_Vector* const * const)&vector, &succeeded, { }, { }, { });

	ASSERT_TRUE(vector == NULL,
	{
		LOG_ERROR(TAB"failed to destroy the vector using W_Core_Containers_Vector_destroy!");
	},
	{
		LOG_SUCCESS(TAB"successfully destroyed the vector using W_Core_Containers_Vector_destroy!");
	});

	EMPTY_LINE;
}

TEST_NEW(core_containers_list)
{
	LOG_INFO("running test 'core_containers_list'...");

	signed char succeeded = 0;
	struct Core_Containers_List* list = NULL;

	W_Core_Containers_List_create(&list, &succeeded, { }, { }, { });

	ASSERT_TRUE(list != NULL,
	{
		LOG_ERROR(TAB"failed to create a list using W_Core_Containers_List_create!");
	},
	{
		LOG_SUCCESS(TAB"successfully created a list using W_Core_Containers_List_create!");
	});

	ASSERT_TRUE(list->head == NULL,
	{
		LOG_ERROR(TAB"failed to set the head of the list to NULL!");
	},
	{
		LOG_SUCCESS(TAB"successfully set the head of the list to NULL!");
	});

	ASSERT_TRUE(list->count == 0,
	{
		LOG_ERROR(TAB"failed to set the count of the list to 0!");
	},
	{
		LOG_SUCCESS(TAB"successfully set the count of the list to 0!");
	});

	static signed int values[] = { 1, 2, 3, 4, 5 };
	static void* addresses[] = { values, values + 1, values + 2, values + 3, values + 4 };

	for (unsigned int i = 0; i < 5; ++i)
	{
		W_Core_Containers_List_push(&list, (const void* const * const)(&(addresses[i])), &succeeded, { }, { }, { });
	}

	ASSERT_TRUE(list->head != NULL,
	{
		LOG_ERROR(TAB"failed to create the head fo the list!");
	},
	{
		LOG_SUCCESS(TAB"successfully created the head fo the list!");
	});

	ASSERT_TRUE(list->count == 5,
	{
		LOG_ERROR(TAB"failed to update the count of the list to 5!");
	},
	{
		LOG_SUCCESS(TAB"successfully updated the count of the list to 5!");
	});

	unsigned long long i = 0;

	for (struct Core_Containers_List_Node* iterator = list->head; iterator != NULL; iterator = iterator->next)
	{
		void* val = iterator->data;

		ASSERT_TRUE(val == addresses[i],
		{
			LOG_ERROR(TAB"failed to get a correct value from the list!");
		},
		{
			LOG_SUCCESS(TAB"successfully got the correct value from the list!");
		});

		ASSERT_TRUE(*(signed int*)val == values[i],
		{
			LOG_ERROR(TAB"failed to get a correct value from the list!");
		},
		{
			LOG_SUCCESS(TAB"successfully got the correct value from the list!");
		});

		++i;
	}

	ASSERT_TRUE(list->head != NULL,
	{
		LOG_ERROR(TAB"failed to not change the head of the list to NULL!");
	},
	{
		LOG_SUCCESS(TAB"successfully did not change the head of the list to NULL!");
	});

	ASSERT_TRUE(list->count == 5,
	{
		LOG_ERROR(TAB"failed to not change the count of the list to 5!");
	},
	{
		LOG_SUCCESS(TAB"successfully did not change the count of the list to 5!");
	});

	{
		void* val = NULL;

		W_Core_Containers_List_pop(&list, (const void* const * const)&val, &succeeded, { }, { }, { });

		ASSERT_TRUE(val == addresses[4],
		{
			LOG_ERROR(TAB"failed to pop a correct value from the list using W_Core_Containers_List_pop!");
		},
		{
			LOG_SUCCESS(TAB"successfully popped the correct value from the list using W_Core_Containers_List_pop!");
		});

		ASSERT_TRUE(*(signed int*)val == values[4],
		{
			LOG_ERROR(TAB"failed to pop a correct value from the list using W_Core_Containers_List_pop!");
		},
		{
			LOG_SUCCESS(TAB"successfully popped the correct value from the list using W_Core_Containers_List_pop!");
		});
	}

	ASSERT_TRUE(list->head != NULL,
	{
		LOG_ERROR(TAB"failed to not change the head of the list to NULL!");
	},
	{
		LOG_SUCCESS(TAB"successfully did not change the head of the list to NULL!");
	});

	ASSERT_TRUE(list->count == 4,
	{
		LOG_ERROR(TAB"failed to change the count of the list to 4!");
	},
	{
		LOG_SUCCESS(TAB"successfully did change the count of the list to 4!");
	});

	i = 0;

	for (struct Core_Containers_List_Node* iterator = list->head; iterator != NULL; iterator = iterator->next)
	{
		void* val = iterator->data;

		ASSERT_TRUE(val == addresses[i],
		{
			LOG_ERROR(TAB"failed to get a correct value from the list!");
		},
		{
			LOG_SUCCESS(TAB"successfully got the correct value from the list!");
		});

		ASSERT_TRUE(*(signed int*)val == values[i],
		{
			LOG_ERROR(TAB"failed to get a correct value from the list!");
		},
		{
			LOG_SUCCESS(TAB"successfully got the correct value from the list!");
		});

		++i;
	}

	ASSERT_TRUE(list->head != NULL,
	{
		LOG_ERROR(TAB"failed to not change the head of the list to NULL!");
	},
	{
		LOG_SUCCESS(TAB"successfully did not change the head of the list to NULL!");
	});

	ASSERT_TRUE(list->count == 4,
	{
		LOG_ERROR(TAB"failed to not change the count of the list to 4!");
	},
	{
		LOG_SUCCESS(TAB"successfully did not change the count of the list to 4!");
	});


	W_Core_Containers_List_destroy((const struct Core_Containers_List* const * const)&list, &succeeded, { }, { }, { });

	ASSERT_TRUE(list == NULL,
	{
		LOG_ERROR(TAB"failed to destroy the list using W_Core_Containers_List_destroy!");
	},
	{
		LOG_SUCCESS(TAB"successfully destroyed the list using W_Core_Containers_List_destroy!");
	});

	EMPTY_LINE;
}

TEST_NEW(core_containers_map)
{
	LOG_INFO("running test 'core_containers_map'...");

	signed char succeeded = 0;
	struct Core_Containers_Map* map = NULL;

	W_Core_Containers_Map_create(&map, 64, &succeeded, { }, { }, { });

	ASSERT_TRUE(map != NULL,
	{
		LOG_ERROR(TAB"failed to create a map using W_Core_Containers_Map_create!");
	},
	{
		LOG_SUCCESS(TAB"successfully created a map using W_Core_Containers_Map_create!");
	});

	ASSERT_TRUE(map->nodes != NULL,
	{
		LOG_ERROR(TAB"failed to create the map's nodes!");
	},
	{
		LOG_SUCCESS(TAB"successfully created the map's nodes!");
	});

	ASSERT_TRUE(map->capacity == 64,
	{
		LOG_ERROR(TAB"failed to set the capacity of the map to 64!");
	},
	{
		LOG_SUCCESS(TAB"successfully set the capacity of the map to 64!");
	});

	#define pairsCount 4
	static const char* keys[pairsCount] = { "a", "b", "c", "a" };
	static const char* values[pairsCount] = { "hello from a!", "hello from b!", "hello from c!", "hello from a! (clone)" };

	for (unsigned long long i = 0; i < pairsCount; ++i)
	{
		W_Core_Containers_Map_set(&map, keys[i], STRLEN(keys[i]), (const void* const * const)(&(values[i])), &succeeded, { }, { }, { });
	}

	static const char* answers[pairsCount] = { "hello from a! (clone)", "hello from b!", "hello from c!", "hello from a! (clone)" };

	for (unsigned long long i = 0; i < pairsCount; ++i)
	{
		const char* val = NULL;
		W_Core_Containers_Map_get((const struct Core_Containers_Map* const * const)&map, keys[i], STRLEN(keys[i]), (const void* const * const)(&val), &succeeded, { }, { }, { });

		ASSERT_TRUE(STREQL(val, answers[i]),
		{
			LOG_ERROR(TAB"failed to get a correct value from the map using W_Core_Containers_Map_get!");
		},
		{
			LOG_SUCCESS(TAB"successfully got the correct value from the map using W_Core_Containers_Map_get!");
		});
	}

	ASSERT_TRUE(map != NULL,
	{
		LOG_ERROR(TAB"failed to not change a map using W_Core_Containers_Map_create!");
	},
	{
		LOG_SUCCESS(TAB"successfully did not change a map using W_Core_Containers_Map_create!");
	});

	ASSERT_TRUE(map->nodes != NULL,
	{
		LOG_ERROR(TAB"failed to not change the map's nodes!");
	},
	{
		LOG_SUCCESS(TAB"successfully did not change the map's nodes!");
	});

	ASSERT_TRUE(map->capacity == 64,
	{
		LOG_ERROR(TAB"failed to not change the capacity of the map to 64!");
	},
	{
		LOG_SUCCESS(TAB"successfully did not change the capacity of the map to 64!");
	});

	W_Core_Containers_Map_destroy((const struct Core_Containers_Map* const * const)&map, &succeeded, { }, { }, { });

	ASSERT_TRUE(map == NULL,
	{
		LOG_ERROR(TAB"failed to destroy the map using W_Core_Containers_Map_destroy!");
	},
	{
		LOG_SUCCESS(TAB"successfully destroyed the map using W_Core_Containers_Map_destroy!");
	});

	EMPTY_LINE;
}

SUITE_NEW(core_containers)
{
	TEST_ADD(core_containers_vector),
	TEST_ADD(core_containers_list),
	TEST_ADD(core_containers_map),
	SUITE_END
};

ENTRY
{
	SUITE_RUN(core_containers);
	EXIT;
}
