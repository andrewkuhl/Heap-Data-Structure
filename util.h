#ifndef _UTIL_H
#define _UTIL_H
#include <cstdio>
#include <iostream>

struct COMMAND{
	char c;
	int n;
	int m;
};

COMMAND* INNIT_COMMAND();
COMMAND* NEXT_COMMAND(COMMAND* commands);

#endif
