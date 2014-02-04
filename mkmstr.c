/*	Multi String Library
	Copyright 2007-2014 PC GO Ld.

	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.

	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
*/

#include "mstring.h"
#include <stdarg.h>

mstr mkmstrl(const char *first, ...) {
	mstr new_mstr = mstrinit(first, 0);
	char *next;
	va_list ap;
	va_start(ap, first);
	while((next = va_arg(ap, char *))) if(!mstradd_r(&new_mstr, next)) return NULL;
	va_end(ap);
	return new_mstr;
}

mstr mkmstrv(char **v) {
	if(!*v) return NULL;
	mstr new_mstr = mstrinit(*v, 0);
	while(*(++v)) if(!mstradd_r(&new_mstr, *v)) return NULL;
	return new_mstr;
}
