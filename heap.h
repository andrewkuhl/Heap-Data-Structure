
#ifndef _HEAP_H
#define _HEAP_H

struct ELEMENT{
	int key;
};


struct HEAP{
	int capacity;
	int size;
	ELEMENT** H;
	int minheapifycalls;
};

HEAP* INITIALIZE(int n);
void PRINT_HEAP(HEAP* heap);
void swap(int a, int b, HEAP* heap);
void BUILD_HEAP(HEAP* heap);
void MIN_HEAPIFY(HEAP* heap, int loopNum);
void DELETE_MIN(HEAP* heap);
void INSERT(HEAP* heap, int value);
#endif
