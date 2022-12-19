
# !/bin/sh

if [ ! -d ./build ]; then
	mkdir -p ./build
fi

if [ ! -d ./logs ]; then
	mkdir -p ./logs
fi

for file in *.c; do
	gcc \
		-std=gnu11 \
		-Wall \
		-Wextra \
		-Wpedantic \
		-Werror \
		-Wshadow \
		-O3 \
		-I./include \
		-I./../include \
		-o ./build/$file.out \
		./$file \
		./../source/core/memory/malloc.c \
		./../source/core/memory/realloc.c \
		./../source/core/memory/free.c \
		./../source/core/containers/vector.c \
		./../source/core/containers/list.c \
		./../source/core/containers/map.c

	./build/$file.out
done
