    /*Exercise 1-1. "Run the ``hello, world'' program on your system. Experiment with leaving out parts of the program, to see what error messages you get.

not coma: /home/vector/Codeblocks/book/main.c|7|error: expected ‘;’ before ‘printf’|

Not "\n" instruction: */
    
#include <stdio.h>

int main()
{
	printf("hello, ");
	printf("world!");

	return 0;
}

