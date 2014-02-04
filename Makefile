ifndef DEST
DEST = /usr
endif

ifeq ($(CC),cc)
CC = gcc
endif

CFLAGS += -O1 -Wall

ifeq ($(CC), $(filter $(CC), arm-mingw32ce-gcc i586-mingw32msvc-gcc))
DLIB_SUFFIX = .dll
else
DLIB_PREFIX = lib
DLIB_SUFFIX = .so
CFLAGS += -fPIC
endif

include objects.mk

first:	libmstr.a $(DLIB_PREFIX)mstr$(DLIB_SUFFIX)

libmstr.a:	$(OBJS) main.o
	$(AR) r $@ $^

$(DLIB_PREFIX)mstr$(DLIB_SUFFIX):	$(OBJS)
	$(CC) -shared $(OBJS) -o $@

install:	libmstr.a mstring.h
	cp libmstr.a $(DEST)/lib/
	cp mstring.h $(DEST)/include/

clean:
	rm -f *.o *.a *.so *.dll

include main.mk
