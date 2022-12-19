
cmake_minimum_required(VERSION 3.3)
project("yarac" LANGUAGES C)

if(CMAKE_C_COMPILER_ID MATCHES "GNU")
	set(PEDANTIC_COMPILE_FLAGS -pedantic-errors -Wall -Wextra -pedantic
		-Wold-style-cast -Wundef
		-Wredundant-decls -Wwrite-strings -Wpointer-arith
		-Wcast-qual -Wformat=2 -Wmissing-include-dirs
		-Wcast-align
		-Wctor-dtor-privacy -Wdisabled-optimization
		-Winvalid-pch -Woverloaded-virtual
		-Wconversion -Wundef
		-Wno-ctor-dtor-privacy -Wno-format-nonliteral)

	if(NOT CMAKE_C_COMPILER_VERSION VERSION_LESS 4.6)
		set(PEDANTIC_COMPILE_FLAGS ${PEDANTIC_COMPILE_FLAGS}
			-Wno-dangling-else -Wno-unused-local-typedefs)
	endif()

	if(NOT CMAKE_C_COMPILER_VERSION VERSION_LESS 5.0)
		set(PEDANTIC_COMPILE_FLAGS ${PEDANTIC_COMPILE_FLAGS} -Wdouble-promotion
			-Wtrampolines -Wzero-as-null-pointer-constant -Wuseless-cast
			-Wvector-operation-performance -Wsized-deallocation -Wshadow)
	endif()

	if(NOT CMAKE_C_COMPILER_VERSION VERSION_LESS 6.0)
		set(PEDANTIC_COMPILE_FLAGS ${PEDANTIC_COMPILE_FLAGS} -Wshift-overflow=2
			-Wnull-dereference -Wduplicated-cond)
	endif()
	
	set(WERROR_FLAG -Werror)
	set(CFLAGS "${CFLAGS} -std=gnu11")
endif()

set(YARAC_BIN_DIRECTORY     "${CMAKE_CURRENT_SOURCE_DIR}/build")
set(YARAC_INCLUDE_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(YARAC_SOURCE_DIRECTORY  "${CMAKE_CURRENT_SOURCE_DIR}/source")

file(GLOB YARAC_HEADER_FILES
	"${YARAC_INCLUDE_DIRECTORY}/core/memory/malloc.h"
	"${YARAC_INCLUDE_DIRECTORY}/core/memory/realloc.h"
	"${YARAC_INCLUDE_DIRECTORY}/core/memory/free.h"
	"${YARAC_INCLUDE_DIRECTORY}/core/memory/null.h"
	"${YARAC_INCLUDE_DIRECTORY}/core/memory/wrappers/malloc.h"
	"${YARAC_INCLUDE_DIRECTORY}/core/memory/wrappers/realloc.h"
	"${YARAC_INCLUDE_DIRECTORY}/core/memory/wrappers/free.h"
	"${YARAC_INCLUDE_DIRECTORY}/core/memory.h"

	"${YARAC_INCLUDE_DIRECTORY}/core/containers/vector.h"
	"${YARAC_INCLUDE_DIRECTORY}/core/containers/list.h"
	"${YARAC_INCLUDE_DIRECTORY}/core/containers/wrappers/vector.h"
	"${YARAC_INCLUDE_DIRECTORY}/core/containers/wrappers/list.h"
	"${YARAC_INCLUDE_DIRECTORY}/core/containers.h"
)

set(YARAC_PUBLIC_HEADER_FILES
	"${YARAC_INCLUDE_DIRECTORY}/core/memory/malloc.h"
	"${YARAC_INCLUDE_DIRECTORY}/core/memory/realloc.h"
	"${YARAC_INCLUDE_DIRECTORY}/core/memory/free.h"
	"${YARAC_INCLUDE_DIRECTORY}/core/memory/null.h"
	"${YARAC_INCLUDE_DIRECTORY}/core/memory/wrappers/malloc.h"
	"${YARAC_INCLUDE_DIRECTORY}/core/memory/wrappers/realloc.h"
	"${YARAC_INCLUDE_DIRECTORY}/core/memory/wrappers/free.h"
	"${YARAC_INCLUDE_DIRECTORY}/core/memory.h"

	"${YARAC_INCLUDE_DIRECTORY}/core/containers/vector.h"
	"${YARAC_INCLUDE_DIRECTORY}/core/containers/list.h"
	"${YARAC_INCLUDE_DIRECTORY}/core/containers/wrappers/vector.h"
	"${YARAC_INCLUDE_DIRECTORY}/core/containers/wrappers/list.h"
	"${YARAC_INCLUDE_DIRECTORY}/core/containers.h"
)

file(GLOB YARAC_SOURCE_FILES
	"${YARAC_SOURCE_DIRECTORY}/core/memory/malloc.c"
	"${YARAC_SOURCE_DIRECTORY}/core/memory/realloc.c"
	"${YARAC_SOURCE_DIRECTORY}/core/memory/free.c"
	"${YARAC_SOURCE_DIRECTORY}/core/containers/vector.c"
	"${YARAC_SOURCE_DIRECTORY}/core/containers/list.c"

	"${YARAC_SOURCE_DIRECTORY}/main.c"
)

string(TOUPPER "${CMAKE_BUILD_TYPE}" BUILD_VARIANT)
set(YARAC_BUILD_VARIANT "YARAC_${BUILD_VARIANT}")
message(${YARAC_BUILD_VARIANT})

add_executable(${PROJECT_NAME} ${YARAC_SOURCE_FILES})

target_compile_definitions(${PROJECT_NAME}
	PUBLIC
		"${YARAC_BUILD_VARIANT}=1"
)

target_include_directories(${PROJECT_NAME}
	PUBLIC
		$<INSTALL_INTERFACE:include>
		$<BUILD_INTERFACE:${YARAC_INCLUDE_DIRECTORY}>
)

set_target_properties(${PROJECT_NAME} PROPERTIES
	PUBLIC_HEADER
		"${YARAC_PUBLIC_HEADER_FILES}"
)
