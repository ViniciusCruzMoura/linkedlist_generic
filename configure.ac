AC_INIT([linked_list], [2025.02.1], [name@example.com])
AC_CONFIG_AUX_DIR(build-aux)

AM_INIT_AUTOMAKE([no-define])

AC_PROG_MAKE_SET
AC_PROG_CC

AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_SRCDIR(src/main.c)
AC_CONFIG_HEADERS([src/config.h:src/config.in])

CFLAGS="$CFLAGS -Wall -Wextra --pedantic -s -O2"
LDLIBS="$LDLIBS -lGL -lm -lpthread -ldl -lrt -lX11"
LDFLAGS="$LDFLAGS -L/usr/local/lib $LDLIBS"

AC_CONFIG_FILES([Makefile 
                 src/Makefile])

AC_OUTPUT
