#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
int main(void)
{
	for(int i = 0;;i++)
	{
		printf("%d",i);
		
		fflush(stdout);
		usleep(100);
		system("clear");
	}
	
	return 0;
}
