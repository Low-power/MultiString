/*	Multi String Library
	Copyright 2007-2014 PC GO Ld.

	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.

	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
*/

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
