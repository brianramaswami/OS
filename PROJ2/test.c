#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	printf("fuck me");
	char* inp = (char*) malloc(32);
	
	free(inp);
	return 0;

}