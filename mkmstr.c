#include "mstring.h"
#include <stdarg.h>

mstr mkmstrl(const char *first, ...){
	//size_t size = strlen(first) + 2;
	mstr new_mstr = mstrinit(first, 0);
	va_list ap;
	va_start(ap, first);
	char *next = va_arg(ap, char *);
	while(next){
		if(!mstradd_r(&new_mstr, next)) return NULL;
		next = va_arg(ap, char *);
	}
	return new_mstr;
}
