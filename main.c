#include "mstring.h"
#include <string.h>

extern int Main(mstr);

int main(int argc, char **argv){
	size_t len = strlen(*argv) + 2;
	mstr args = mstrinit(*argv, len);
	while(*(++argv)){
		len += strlen(*argv) + 1;
		args = realloc(args, len);
		if(!args) return -1;
		mstradd(args, *argv);
	}
	return Main(args);
}
