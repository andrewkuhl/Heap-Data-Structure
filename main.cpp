#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "util.h"
#include "heap.h"

int main() {
	HEAP* heap = nullptr;
	COMMAND* commands = INNIT_COMMAND();
	FILE* ifile = nullptr;
	FILE* ofile = nullptr;
	int number = 0;

	while(true){
		commands = NEXT_COMMAND(commands);
		switch(commands->c){
			case 's':
				return(0);
			case 'c':
				heap = INITIALIZE(commands->n);
				break;
			case 'r':
				{
					ifile = fopen("HEAPinput.txt", "r");
					if (!ifile) {
						std::cout << "Error: cannot open file for reading" << std::endl;
						break;
					}
					fscanf(ifile, "%d", &number);
					if (heap == nullptr || heap->capacity < number) {
						std::cout << "Error: heap overflow" << std::endl;
						break;
					}
					heap->size = 0;
					for (int j = 0; j < number; j++) {
						int hold;
						fscanf(ifile, "%d", &hold);
						ELEMENT *element;
						element = (ELEMENT *) malloc(sizeof(ELEMENT));
						element->key = hold;
						heap->H[j] = element;
						heap->size++;
					}
					heap->minheapifycalls = 0;
					BUILD_HEAP(heap);
					if (commands->n == 1)
						std::cout << "Number of Heapify calls: " << heap->minheapifycalls-1 << std::endl;
				}
				break;

			case 'p':
				if (heap == nullptr) {
					std::cout << "Error: cannot print" << std::endl;
					break;
				}
				else {
					PRINT_HEAP(heap);
					break;
				}
			case 'w':
				if(heap == nullptr){
					std::cout << "Error: cannot write" << std::endl;
					break;
				}
				ofile = fopen("HEAPoutput.txt", "w");
				if(!ofile){
					std::cout << "Error: cannot write" << std::endl;
					break;
				}
				fprintf(ofile, "%d\n", heap->size);
				for(int j = 0; j<heap->size; j++)
					fprintf(ofile, "%d\n" , heap->H[j]->key);
				fclose(ofile);
				break;
			case 'd':
				{
					if (heap == nullptr || heap->size == 0) {
						std::cout << "Error: heap is NULL or empty" << std::endl;
						break;
					}
					heap->minheapifycalls = 0;
					DELETE_MIN(heap);
					BUILD_HEAP(heap);
					if (commands->n == 1)
						std::cout << "Number of Heapify calls: " << heap->minheapifycalls-3<< std::endl;
				}
				break;
			case 'i':
				{
					if (heap->size >= heap->capacity || heap == nullptr) {
						std::cout << "Error: heap is NULL or full" << std::endl;
						break;
					}
					heap->minheapifycalls = 0;
					INSERT(heap, commands->n);
					BUILD_HEAP(heap);
				}
				break;
			case 'k':
				{
					if (heap == nullptr || commands->n < 0 || commands->n > heap->size || commands->m >= heap->H[commands->n]->key) {
						std::cout << "Error: invalid call to DecreaseKey" << std::endl;
						break;
					}
					heap->H[commands->n-1]->key = commands->m;
					BUILD_HEAP(heap);
				}
				break;
			case 'x':
				break;
		}
	}


	return(0);
}
