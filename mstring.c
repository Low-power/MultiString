#include "mstring.h"
#include <string.h>

size_t mstrsize(mstr src) {
	size_t count = 2;
	while(*src++ || *src) count++;
	return count;
}

mstr mstradd(mstr dest, const char *src) {
	size_t size_orig = mstrsize(dest) - 1;
	size_t len_src = strlen(src) + 1;
	memcpy(dest + size_orig, src, len_src);
	dest[size_orig+len_src] = 0;
	return dest;
}

mstr mstrinit(const char *src, size_t size) {
	if(!size) size = strlen(src) + 2;
	mstr new_mstr = (mstr)malloc(size * sizeof(char));
	strncpy(new_mstr, src, size);
	new_mstr[size-2] = new_mstr[size-1] = 0;
	return new_mstr;
}

int mstrcount(mstr src) {
	int count = 0;
	while(1) if(!*(src++)) {
		count++;
		if(!*src) return count;
	}
}

char *mstrindex(mstr s, unsigned int i) {
	unsigned int count = 1;
	while(count != i) if(!*s++) count++;
	if(count != 1 && !s[-1] && !s[-2]) return NULL;
	return s;
}

mstr mstrcpy(mstr dest, mstr src) {
	return memcpy(dest, src, mstrsize(src));
}

mstr mstrdup(mstr s) {
	size_t size = mstrsize(s);
	mstr new_mstr = (mstr)malloc(size * sizeof(char));
	return memcpy(new_mstr, s, size);
}
