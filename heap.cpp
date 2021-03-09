#include <iostream>
#include "heap.h"
#include <stdlib.h>

HEAP* INITIALIZE(int n){
	HEAP* heap = (HEAP*) calloc(1,sizeof(HEAP));
	heap->size = 0; heap->capacity = n;
	heap->H = (ELEMENT**) calloc(n+1,sizeof(ELEMENT*));
	return heap;
}

void PRINT_HEAP(HEAP* heap){
	 std::cout <<"capacity=" << heap->capacity <<", size=" << heap->size << std::endl;
	 bool isFirst = true;
	 if(heap->size != 0) {
		 for (int i = 0; i < heap->size; i++) {
			 if (isFirst) {
				 isFirst = false;
			 } else {
				 std::cout << ", ";
			 }
			 std::cout << heap->H[i]->key;
		 }
		 std::cout << std::endl;
	 }
}



