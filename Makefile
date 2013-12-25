ifndef DEST
DEST = /usr
endif
ifeq ($(CC),cc)
CC = gcc
endif

CFLAGS += -O1 -Wall
OBJS = \
	main.o \
	mstring.o

first:	libmstr.a

libmstr.a:	$(OBJS)
	$(AR) r $@ $(OBJS)

install:	libmstr.a mstring.h
	cp libmstr.a $(DEST)/lib/
	cp mstring.h $(DEST)/include/

clean:
	rm -f $(OBJS) libmstr.a
