#include <stdio.h>

void b()
{
	printf("this is b\n");
	return ;
	printf("this is return\n");
}

void a()
{
	b();
	printf("this is a\n");
	
}



int main(void)
{
	printf("this is a debug\n");
	int i = -10;
	while(1)
	{
		printf("break ");
		while(1)
			{	
				i++;
				if(i)
				{
					break;
				}
			}
	}
	return 0;
}
