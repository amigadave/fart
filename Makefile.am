AUTOMAKE_OPTIONS = subdir-objects
ACLOCAL_AMFLAGS = -I m4 ${ACLOCAL_FLAGS}
DISTCHECK_CONFIGURE_FLAGS = --enable-warnings=fatal

bin_PROGRAMS = src/fart
src_fart_SOURCES = src/main.cc \
                   src/fart.cc src/fart.h \
                   src/timer.cc src/timer.h \
                   src/player.cc src/player.h \
                   src/velocity.cc src/velocity.h \
                   src/utils.cc src/utils.h

src_fart_LDADD = $(FART_LIBS)

AM_CXXFLAGS = $(FART_CFLAGS) $(FART_WARNINGS)

imagedir = $(datadir)

dist_image_DATA = data/background.bmp \
                  data/rocket_off.bmp \
                  data/rocket_on.bmp \
                  data/rocket_broken.bmp
