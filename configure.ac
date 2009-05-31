AC_INIT([Fart], [0.1], [davidk@openismus.com], [fart])
# AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_SRCDIR([src/fart.cc])
AC_PREREQ([2.57])
AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE([-Wall -Werror dist-bzip2 no-define])

AC_PROG_CXX
AC_PROG_INSTALL

PKG_CHECK_MODULES([FART], [sdl >= 1.2.0])
AC_SUBST(FART_CXXFLAGS)
AC_SUBST(FART_LIBS)

AC_LANG([C++])

DK_ARG_ENABLE_WARNINGS([FART_WARNINGS],
        [-Wall],
        [-Wall -Wextra])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
