/**
 * @file stdlib.h
 * 
 * $Id: stdlib.h 227 2007-07-12 01:23:06Z mschul $
 */
/* Embedded XINU, Copyright (C) 2007.  All rights reserved. */

#ifndef _STDLIB_H_
#define _STDLIB_H_

int abs(int);
int atoi(char *);
long atol(char *);
void bzero(void *, int);
void qsort(char *, unsigned, int, int (*)(void));
ulong rand(void);
void srand(unsigned long);

#endif /* __STDLIB_H__ */
