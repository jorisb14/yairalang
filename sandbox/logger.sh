
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
	-g \
	-O0 \
	-rdynamic \
	-o ./build/logger.out \
	./logger.c

# Run the tester
./build/logger.out
