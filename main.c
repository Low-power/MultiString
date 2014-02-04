/*	Multi String Library
	Copyright 2007-2014 PC GO Ld.

	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.

	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
*/

#include "mstring.h"
#include <string.h>

extern int Main(mstr);

int main(int argc, char **argv) {
	size_t len = strlen(*argv) + 2;
	mstr args = mstrinit(*argv, len);
	while(*(++argv)) {
		len += strlen(*argv) + 1;
		args = realloc(args, len);
		if(!args) return -1;
		mstradd(args, *argv);
	}
	return Main(args);
}
