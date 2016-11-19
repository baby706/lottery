#include <stdio.h>
#include <malloc.h>

int main(void)
{
	int *p = malloc(sizeof(int));
	free(p);
	
	p = NULL;
	 
	return 0;
}
