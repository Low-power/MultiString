ifndef DEST
DEST = /usr
endif

ifeq ($(CC),cc)
CC = gcc
endif

CFLAGS += -O1 -Wall

#ifeq ($(CC)_$(CC), arm-mingw32ce-gcc_i586-mingw32msvc-gcc)
ifeq ($(CC), $(filter $(CC), arm-mingw32ce-gcc i586-mingw32msvc-gcc))
DLIB_SUFFIX = .dll
else
DLIB_PREFIX = lib
DLIB_SUFFIX = .so
CFLAGS += -fPIC
endif

OBJS = \
	mkmstr.o \
	mstring.o \
	mstring-realloc.o \
	putms.o

first:	libmstr.a

libmstr.a:	$(OBJS) main.o
	$(AR) r $@ $^

$(DLIB_PREFIX)mstr$(DLIB_SUFFIX):	$(OBJS)
	$(CC) -shared $(OBJS) -o $@

install:	libmstr.a mstring.h
	cp libmstr.a $(DEST)/lib/
	cp mstring.h $(DEST)/include/

clean:
	rm -f *.o *.a *.so *.dll
