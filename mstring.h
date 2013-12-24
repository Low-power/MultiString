#ifndef _MULTI_STRING_H
#define _MULTI_STRING_H

#include <stddef.h>

typedef char *mstr;

size_t mstrsize(mstr);
mstr mstradd(mstr, const char *);
mstr mstrinit(const char *, size_t);
int mstrcount(mstr);
char *mstrindex(mstr, unsigned int);
int putmss(mstr, unsigned int);
int putms(mstr);
void *malloc(size_t);
void *realloc(void *, size_t);
void free(void *);

#endif
