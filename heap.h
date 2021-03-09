
#ifndef _HEAP_H
#define _HEAP_H

struct ELEMENT{
	int key;
};


struct HEAP{
	int capacity;
	int size;
	ELEMENT** H;
};

HEAP* INITIALIZE(int n);
void PRINT_HEAP(HEAP* heap);

#endif
