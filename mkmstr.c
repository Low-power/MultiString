#include "mstring.h"
#include <stdarg.h>

mstr mkmstrl(const char *first, ...){
	mstr new_mstr = mstrinit(first, 0);
	va_list ap;
	va_start(ap, first);
	char *next;
	while(next = va_arg(ap, char *)) if(!mstradd_r(&new_mstr, next)) return NULL;
	va_end(ap);
	return new_mstr;
}

mstr mkmstrv(char **v){
	if(!*v) return NULL;
	mstr new_mstr = mstrinit(*v, 0);
	while(*(++v)) if(!mstradd_r(&new_mstr, *v)) return NULL;
	return new_mstr;
}
