#include "util.h"

COMMAND* INNIT_COMMAND(){
	COMMAND* commands = (COMMAND*) calloc(1,sizeof(COMMAND));
	commands->c = ' ';
	commands->n = 0;
	return commands;
}

COMMAND* NEXT_COMMAND(COMMAND* commands){
	char c = ' ';
	int n = 0;
	int m = 0;

	while(true){
		scanf("%c", &c);
		while(c == '\n' || c == ' ' || c == '\t' )
			scanf("%c", &c);

		if (c == 'S' || c == 's') {
			commands->c = 's';
			return commands;
		}
		else if (c == 'C' || c == 'c') {
			commands->c = 'c';
			scanf("%d", &n);
			if(n <= 0) {
				std::cout << "Warning in nextCommand: read in int " << n << std::endl;
				commands->c = 'x';
				return commands;
			}
			commands->n = n;
			return commands;
		}
		else if (c == 'R' || c == 'r') {
			commands->c = 'r';
			scanf("%d", &n);
			commands->n = n;
			return commands;
		}
		else if (c == 'P' || c == 'p') {
			commands->c = 'p';
			return commands;
		}
		else if (c == 'W' || c == 'w') {
			commands->c = 'w';
			return commands;
		}
		else if (c == 'D' || c == 'd') {
			commands->c = 'd';
			scanf("%d", &n);
			commands->n = n;
			return commands;
		}
		else if (c == 'I' || c == 'i') {
			commands->c = 'i';
			scanf("%d", &n);
			commands->n = n;
			return commands;
		}
		else if (c == 'K' || c == 'k') {
			commands->c = 'k';
			scanf("%d", &n);
			scanf("%d", &m);
			commands->n = n;
			commands->m = m;
			return commands;
		}
		else{
			std::cout << "Warning in nextCommand: invalid input " << c << std::endl;
			commands->c = 'x';
			return commands;
		}
	}
}