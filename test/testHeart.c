#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
int n;
void draw(int n)
{
	int i,j;
	for (i=1-(n>>1);i<=n;i++)
	{   
		//printf("%d",i);
		if (i>=0)
		{ 
			for (j=0;j<i;j++) 
				printf("  ");
			for (j=1;j<=2*(n-i)+1;j++)
				printf("\033[31m *\033[0m");
			printf("\n"); 
		}
		else 
		{ 
			for (j=i;j<0;j++)
			{
				printf("   ");
				if( j == -2)
					printf("\b");
				if( i == -1)
					printf("\b");
			}
			for (j=1;j<=n+2*i+1;j++) 
				printf("\033[31m *\033[0m");
			for (j=1;j<=-1-2*i;j++) 
			{
				if( j == 1)
					printf(" ");
				printf(" ");
			}
			for (j=1;j<=n+2*i+1;j++)
				printf("\033[31m *\033[0m"); 
			printf("\n"); 
		}
	}
}

int main() 
{ 
	
	
	for(n=6;n<=15;n++)
	{
		//printf("请输入尺寸大小(n至少为4):");
		//scanf("%d",&n); 
		draw(n);
		usleep(100000); //沉睡使其显示
		system("clear"); //清屏
		usleep(50000); //沉睡与下一次形成时间产差 产生闪烁效果
	}
	for(n=15;n>=4;n--)
	{   draw(n);
		usleep(100000);
		system("clear");
		usleep(50000);
	}
	usleep(100000);
	//扩大与缩小显示之间静止时间
	
	
	return 0;
}




        









