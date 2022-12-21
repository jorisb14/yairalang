
cmake_minimum_required(VERSION 3.3)
project("yairac" LANGUAGES C)

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

set(YAIRAC_BIN_DIRECTORY     "${CMAKE_CURRENT_SOURCE_DIR}/build")
set(YAIRAC_INCLUDE_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(YAIRAC_SOURCE_DIRECTORY  "${CMAKE_CURRENT_SOURCE_DIR}/source")

file(GLOB YAIRAC_HEADER_FILES
	"${YAIRAC_INCLUDE_DIRECTORY}/core/memory/malloc.h"
	"${YAIRAC_INCLUDE_DIRECTORY}/core/memory/realloc.h"
	"${YAIRAC_INCLUDE_DIRECTORY}/core/memory/free.h"
	"${YAIRAC_INCLUDE_DIRECTORY}/core/memory/null.h"
	"${YAIRAC_INCLUDE_DIRECTORY}/core/memory/wrappers/malloc.h"
	"${YAIRAC_INCLUDE_DIRECTORY}/core/memory/wrappers/realloc.h"
	"${YAIRAC_INCLUDE_DIRECTORY}/core/memory/wrappers/free.h"
	"${YAIRAC_INCLUDE_DIRECTORY}/core/memory.h"

	"${YAIRAC_INCLUDE_DIRECTORY}/core/containers/vector.h"
	"${YAIRAC_INCLUDE_DIRECTORY}/core/containers/list.h"
	"${YAIRAC_INCLUDE_DIRECTORY}/core/containers/map.h"
	"${YAIRAC_INCLUDE_DIRECTORY}/core/containers/wrappers/vector.h"
	"${YAIRAC_INCLUDE_DIRECTORY}/core/containers/wrappers/list.h"
	"${YAIRAC_INCLUDE_DIRECTORY}/core/containers/wrappers/map.h"
	"${YAIRAC_INCLUDE_DIRECTORY}/core/containers.h"
)

set(YAIRAC_PUBLIC_HEADER_FILES ${YAIRAC_HEADER_FILES})

file(GLOB YAIRAC_SOURCE_FILES
	"${YAIRAC_SOURCE_DIRECTORY}/core/memory/malloc.c"
	"${YAIRAC_SOURCE_DIRECTORY}/core/memory/realloc.c"
	"${YAIRAC_SOURCE_DIRECTORY}/core/memory/free.c"
	"${YAIRAC_SOURCE_DIRECTORY}/core/containers/vector.c"
	"${YAIRAC_SOURCE_DIRECTORY}/core/containers/list.c"
	"${YAIRAC_SOURCE_DIRECTORY}/core/containers/map.c"

	"${YAIRAC_SOURCE_DIRECTORY}/main.c"
)

string(TOUPPER "${CMAKE_BUILD_TYPE}" BUILD_VARIANT)
set(YAIRAC_BUILD_VARIANT "YAIRAC_${BUILD_VARIANT}")
message(${YAIRAC_BUILD_VARIANT})

add_executable(${PROJECT_NAME} ${YAIRAC_SOURCE_FILES})

target_compile_definitions(${PROJECT_NAME}
	PUBLIC
		"${YAIRAC_BUILD_VARIANT}=1"
)

target_include_directories(${PROJECT_NAME}
	PUBLIC
		$<INSTALL_INTERFACE:include>
		$<BUILD_INTERFACE:${YAIRAC_INCLUDE_DIRECTORY}>
)

set_target_properties(${PROJECT_NAME} PROPERTIES
	PUBLIC_HEADER
		"${YAIRAC_PUBLIC_HEADER_FILES}"
)
