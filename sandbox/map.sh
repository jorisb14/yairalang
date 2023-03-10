
#!/bin/sh

if [ ! -d ./build ]; then
	mkdir -p ./build
fi

# Compiling unit_tester
gcc \
	-std=gnu11 \
	-Wall \
	-Wextra \
	-Wpedantic \
	-Werror \
	-Wshadow \
	-o ./build/map.out \
	./map.c

# Run the tester
./build/map.out
