NATIVETOOLSDIR := ../WindowsNT-NativeTools/
include $(NATIVETOOLSDIR)rules.mk

CFLAGS += -Wall -O1
LDFLAGS += -L.
LDFLAGS_LIB = --shared -e _DllMainCRTStartup -L$(NATIVETOOLSDIR)nativelibc
LIBS_LIB := $(LIBS)
LIBS += -lmstr

include objects.mk
OBJS += $(NATIVETOOLSDIR)nativelibc/dllcrt.o

first:	mstr.dll

mstr.dll:	$(OBJS)
	$(LD) $(LDFLAGS_LIB) $(OBJS) -o $@ $(LIBS_LIB)

clean:
	rm -f *.o *.dll

include main.mk
