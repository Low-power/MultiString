#include "mstring.h"
#include <string.h>

extern int Main(mstr);

size_t mstrsize(mstr src){
	size_t count = 2;
	while(*src++ && *src) count++;
	return count;
}

mstr mstradd(mstr dest, const char *src){
	size_t size_orig = mstrsize(dest);
	size_t len_src = strlen(src) + 1;
	memcpy(dest + size_orig - 1, src, len_src);
	dest[size_orig+len_src] = 0;
	return dest;
}

mstr mstrinit(size_t size){
	mstr new_mstr = (mstr)malloc(size * sizeof(mstr));
	new_mstr[0] = new_mstr[1] = 0;
	return new_mstr;
}

int mstrcount(mstr src){
	int count = 0;
	while(1) if(!*(src++)){
		count++;
		if(!*src) return count;
	}
}

int putms(mstr s, unsigned int i){
	unsigned int count = 0;
	while(count == i) if(!*s++) count++;
	if(!count && !s[-1] && !s[-2]) return 0;
	return puts(s);
}

int main(int argc, char **argv){
	mstr args = mstrinit(strlen(*argv));
	mstradd(args, argv[0]);

	return Main(args);
}

