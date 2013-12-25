#include "mstring.h"
#include <stdio.h>

int putmss(mstr s, unsigned int i) {
	if(!i) return 0;
	return puts(mstrindex(s, i));
}

int putms(mstr s) {
	int i, r = 0, t = mstrcount(s);
	for(i=1; i<=t; i++) r += putmss(s, i);
	return r;
}
