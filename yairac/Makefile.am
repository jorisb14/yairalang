
# The yairac target
bin_PROGRAMS = yairac

# Yarac sources
yairac_SOURCES = \
	$(top_srcdir)/include/core/memory/malloc.h \
	$(top_srcdir)/include/core/memory/realloc.h \
	$(top_srcdir)/include/core/memory/free.h \
	$(top_srcdir)/include/core/memory/null.h \
	$(top_srcdir)/include/core/memory/wrappers/malloc.h \
	$(top_srcdir)/include/core/memory/wrappers/realloc.h \
	$(top_srcdir)/include/core/memory/wrappers/free.h \
	$(top_srcdir)/include/core/memory.h \
	$(top_srcdir)/include/core/containers/vector.h \
	$(top_srcdir)/include/core/containers/list.h \
	$(top_srcdir)/include/core/containers/map.h \
	$(top_srcdir)/include/core/containers/wrappers/vector.h \
	$(top_srcdir)/include/core/containers/wrappers/list.h \
	$(top_srcdir)/include/core/containers/wrappers/map.h \
	$(top_srcdir)/include/core/containers.h \
	 \
	$(top_srcdir)/source/core/memory/malloc.c \
	$(top_srcdir)/source/core/memory/realloc.c \
	$(top_srcdir)/source/core/memory/free.c \
	$(top_srcdir)/source/core/containers/vector.c \
	$(top_srcdir)/source/core/containers/list.c \
	$(top_srcdir)/source/core/containers/map.c \
	 \
	$(top_srcdir)/source/main.c

# Yarac compiler flags
AM_CFLAGS = \
	-std=gnu11 \
	-Wall \
	-Wextra \
	-Wpedantic \
	-Werror \
	-Wshadow

# Yarac C/C++ preprocessor flags
yairac_CPPFLAGS = \
	-I$(top_srcdir)/include \
	-I$(top_srcdir)/build/include

# Yarac linker flags
yairac_LDFLAGS =
