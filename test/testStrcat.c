#include <stdio.h>
#include <string.h>
#include <malloc.h>

int main(void)

{	
	//char *p = calloc(30,sizeof(char));
	char path[30] = "./test/strcat/";
	//p = path;
	path = strcat(path,"a.txt");
	FILE* fp = fopen(path,"w");
	
	return 0;
	
}
