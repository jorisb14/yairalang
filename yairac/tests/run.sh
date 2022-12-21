
# !/bin/sh

if [ ! -d ./build ]; then
	mkdir -p ./build
fi

if [ ! -d ./logs ]; then
	mkdir -p ./logs
fi

rm -f ./logs/*.log
touch ./logs/all.log
chmod 777 ./logs/all.log

for file in ./*.c; do
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

	touch ./logs/$file.log
	chmod 777 ./logs/$file.log
	./build/$file.out
	./build/$file.out > ./logs/$file.log
	cat ./logs/$file.log >> ./logs/all.log
done
