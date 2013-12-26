NATIVETOOLSDIR := ../WindowsNT-NativeTools/
include $(NATIVETOOLSDIR)rules.mk

CFLAGS += -Wall -O1
LDFLAGS = --shared -e _DllMainCRTStartup -L$(NATIVETOOLSDIR)nativelibc

include objects.mk
OBJS += $(NATIVETOOLSDIR)nativelibc/dllcrt.o

first:	mstr.dll

mstr.dll:	$(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -o $@ $(LIBS)

clean:
	rm -f *.o *.dll
