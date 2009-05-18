AUTOMAKE_OPTIONS = subdir-objects
ACLOCAL_AMFLAGS = -I m4
DISTCHECK_CONFIGURE_FLAGS = --enable-warnings=fatal

bin_PROGRAMS = src/fart
src_fart_SOURCES = src/main.cc src/fart.cc src/fart.h
src_fart_LDADD = $(FART_LIBS)

AM_CPPFLAGS = $(FART_CFLAGS) $(FART_WARNINGS)
