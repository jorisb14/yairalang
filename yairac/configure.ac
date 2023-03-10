
# Init autoconf
AC_INIT([yairac], [0.1.0], [https://github.com/jorisb14/yairalang/issues], [yairac], [https://github.com/jorisb14/yairalang])

# Minimum accepted autoconf version
AC_PREREQ([2.71])

# Source directory (with sanity check file)
AC_CONFIG_SRCDIR([./source/main.c])

# Tests directory (with sanity check file)
# NOTE: not using autotools for the tests!
#       There is a script in scripts directory
#       that will run the tests suite.
# AC_CONFIG_TESTDIR([./tests/test.c]) # NOTE: Not needed...

# Condifguration header for the project
# NOTE: Haven't solved the issue with config.h file yet!
# AC_CONFIG_HEADERS([./include/config.h])

# Auxiliary files directory
AC_CONFIG_AUX_DIR([./aux])

# Initializing automake tool
AM_INIT_AUTOMAKE([1.9 -Wall -Werror -Wno-portability foreign subdir-objects])

# Setup output targets
AC_CONFIG_FILES([Makefile])

# Defaulting CFLAGS to debug configuration
# TODO: need to make flags for building debug and release with GCC and CLANG
# Clang does not have -O0 flag which is not handled here!
${CFLAGS="-O0 -g -DYAIRAC_DEBUG=1"}

# Find C compiler
AC_PROG_CC([gcc cc])

# Set language to C
AC_LANG(C)

# Checks for header files.
AC_CHECK_HEADERS([
	assert.h
	stdlib.h
	stddef.h
	stdarg.h
	stdint.h
	string.h
	limits.h
	float.h
	stdio.h
	ctype.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_STRINGIZE
AC_C_INLINE
AC_C_CONST

# Checks for library functions.
AC_CHECK_FUNCS([
	malloc
	realloc
	free
	fprintf
	printf
	vfprintf
	sscanf
	memcpy
	memcmp
	strncmp
	strlen
	isalpha
	isdigit
	fopen
	fclose
	fgetc
	fgets
	fseek])

# Generate output
AC_OUTPUT

# Printing options
echo ""

echo "Configuration Parameters:"
echo "target............... ${with_target}"
echo "AR_FLAGS............. ${AR_FLAGS}"
echo "abs_top_builddir..... ${abs_top_builddir}"
echo "top_builddir......... ${top_builddir}"
echo "abs_top_srcdir....... ${abs_top_srcdir}"
echo "top_srcdir........... ${top_srcdir}"
echo "builddir............. ${builddir}"
echo "srcdir............... ${srcdir}"
echo "CC................... ${CC}"
echo "CFLAGS............... ${CFLAGS}"
echo "CPPFLAGS............. ${CPPFLAGS}"
echo "HOST................. ${HOST}"
echo "HOSTNAME............. ${HOSTNAME}"
echo "LDFLAGS.............. ${LDFLAGS}"
echo "host................. ${host}"
echo "install prefix ...... ${prefix}"
