
# !/bin/sh

if [ ! -d ./build ]; then
	mkdir -p ./build
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
		./../source/core/containers/list.c

	./build/$file.out
done

rm -r ./build
