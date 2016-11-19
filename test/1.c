#include <stdio.h>

int main(void)
{
	int i = 0;
	int j = 0;
	int k = 0;
	for( i = 0;i<6;i++)
	{
		for(j = 5-i;j>0;j--)
		{
			printf(" ");
		}
		for( k =2*( i+1)-1;k>0;k--)
		{
			printf("*");
		}
		printf("\n");
	
	}

	printf("\n\n");
	return 0;
}
