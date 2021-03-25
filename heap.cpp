#include <iostream>
#include "heap.h"
#include <stdlib.h>

HEAP* INITIALIZE(int n){
	HEAP* heap = (HEAP*) calloc(1,sizeof(HEAP));
	heap->minheapifycalls = 0;
	heap->size = 0;
	heap->capacity = n;
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
void swap(int a, int b, HEAP* heap)
{
	int temp = heap->H[a]->key;
	heap->H[a]->key = heap->H[b]->key;
	heap->H[b]->key = temp;
}

void MIN_HEAPIFY(HEAP* heap, int loopNum)
{

	int left = (2 * loopNum) + 1;
	int r = (2 * loopNum) + 2;
	int smallest = loopNum;
	// If left child is larger than rootS
	if (left < heap->size && heap->H[left]->key < heap->H[smallest]->key)
		smallest = left;

	// If right child is larger than largest so far
	if (r < heap->size && heap->H[r]->key < heap->H[smallest]->key)
		smallest = r;

	// If largest is not root
	if (smallest != loopNum) {
		swap(loopNum,smallest, heap);
		heap->minheapifycalls = heap->minheapifycalls + 1;
		MIN_HEAPIFY(heap, smallest);
	}
}
void BUILD_HEAP(HEAP* heap){
	for(int i = (heap->size)/2; i >= 0; i--){
		heap->minheapifycalls = heap->minheapifycalls + 1;
		MIN_HEAPIFY(heap, i);
	}
}

void DELETE_MIN(HEAP* heap){
	std::cout << "Deleted key: " << heap->H[0]->key << std::endl;
	heap->H[0]->key = heap->H[heap->size-1]->key;
	heap->size = heap->size - 1;
}

void INSERT(HEAP* heap, int value){
	heap->size = heap->size + 1;
	ELEMENT* element = (ELEMENT *) malloc(sizeof(ELEMENT));
	element->key = value;
	heap->H[heap->size-1] = element;
}

