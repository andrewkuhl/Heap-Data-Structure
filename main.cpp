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
				std::cout << "COMMAND: S" << std::endl;
				return(0);
			case 'c':
				std::cout << "COMMAND: C " << commands->n << std::endl;
				heap = INITIALIZE(commands->n);
				break;
			case 'r':
				std::cout << "COMMAND: R" << std::endl;
				ifile = fopen("HEAPinput.txt", "r");
				if(!ifile){
					std::cout << "Error: cannot open file for reading" << std::endl;
					break;
				}
				fscanf(ifile, "%d", &number);
				if(heap == nullptr || heap->capacity < number){
					std::cout << "Error: heap overflow" << std::endl;
					break;
				}
				heap->size = 0;
				for(int j = 0; j< number; j++){
					int hold;
					fscanf(ifile, "%d", &hold);
					ELEMENT* element;
					element = (ELEMENT*) malloc(sizeof(ELEMENT));
					element ->key = hold;
					heap->H[j] = element;
					heap->size++;
				}
				break;
			case 'p':
				std::cout << "COMMAND: P" << std::endl;
				if (heap == nullptr) {
					std::cout << "Error: heap is NULL" << std::endl;
					break;
				}
				else {
					PRINT_HEAP(heap);
					break;
				}
			case 'w':
				std::cout << "COMMAND: W" << std::endl;
				if(heap == nullptr){
					std::cout << "Error: heap is NULL" << std::endl;
					break;
				}
				ofile = fopen("HEAPoutput.txt", "w");
				if(!ofile){
					std::cout << "Error: cannot open file for writing" << std::endl;
					break;
				}
				fprintf(ofile, "%d\n", heap->size);
				for(int j = 0; j<heap->size; j++)
					fprintf(ofile, "%d\n" , heap->H[j]->key);
				fclose(ofile);
				break;
			case 'x':
				break;
		}
	}


	return(0);
}
