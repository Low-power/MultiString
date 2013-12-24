#include "mstring.h"
#include <string.h>
#include <stdio.h>

size_t mstrsize(mstr src){
	size_t count = 2;
	while(*src++ || *src) count++;
	return count;
}

mstr mstradd(mstr dest, const char *src){
	size_t size_orig = mstrsize(dest);
	size_t len_src = strlen(src) + 1;
	memcpy(dest + size_orig - 1, src, len_src);
	dest[size_orig+len_src] = 0;
	return dest;
}

mstr mstrinit(const char *src, size_t size){
	if(!size) size = strlen(src) + 2;
	mstr new_mstr = (mstr)malloc(size * sizeof(char));
	strncpy(new_mstr, src, size);
	new_mstr[size-2] = new_mstr[size-1] = 0;
	return new_mstr;
}

int mstrcount(mstr src){
	int count = 0;
	while(1) if(!*(src++)){
		count++;
		if(!*src) return count;
	}
}

char *mstrindex(mstr s, unsigned int i){
	unsigned int count = 1;
	while(count != i) if(!*s++) count++;
	if(count != 1 && !s[-1] && !s[-2]) return NULL;
	return s;
}

int putmss(mstr s, unsigned int i){
	if(!i) return 0;
	return puts(mstrindex(s, i));
}

int putms(mstr s){
	int i, r = 0, t = mstrcount(s);
	for(i=1; i<=t; i++) r += putmss(s, i);
	return r;
}
