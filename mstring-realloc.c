#include "mstring.h"
#include <string.h>

mstr mstradd_r(mstr *dest, const char *src){
	size_t new_size = mstrsize(*dest) + strlen(src) + 1;
	mstr new_mstr = realloc(*dest, new_size);
	if(!new_mstr) return NULL;
	*dest = new_mstr;
	return mstradd(*dest, src);
}
