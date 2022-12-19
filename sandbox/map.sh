
#!/bin/sh

# Cleanup
[ -e ./map.out ] && rm -- ./map.out

# Compiling unit_tester
gcc \
	-std=gnu11 \
	-Wall \
	-Wextra \
	-Wpedantic \
	-Werror \
	-Wshadow \
	-o ./map.out \
	./map.c

# Run the tester
./map.out
