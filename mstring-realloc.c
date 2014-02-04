/*	Multi String Library
	Copyright 2007-2014 PC GO Ld.

	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.

	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
*/

#include "mstring.h"
#include <string.h>

mstr mstradd_r(mstr *dest, const char *src) {
	size_t new_size = mstrsize(*dest) + strlen(src) + 1;
	mstr new_mstr = realloc(*dest, new_size);
	if(!new_mstr) return NULL;
	*dest = new_mstr;
	return mstradd(*dest, src);
}
