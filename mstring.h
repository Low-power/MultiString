#ifndef _MULTI_STRING_H
#define _MULTI_STRING_H

#include <stddef.h>

typedef char *mstr;
typedef mstr MultiString;

size_t mstrsize(mstr);
mstr mstradd(mstr, const char *);
mstr mstradd_r(mstr *, const char *);
mstr mstrinit(const char *, size_t);
int mstrcount(mstr);
char *mstrindex(mstr, unsigned int);
mstr mstrcpy(mstr, mstr);
mstr mstrdup(mstr);

int putmss(mstr, unsigned int);
int putms(mstr);

mstr mkmstrl(const char *, ...);
mstr mkmstrv(char **);

void *malloc(size_t);
void *realloc(void *, size_t);
void free(void *);

#endif
