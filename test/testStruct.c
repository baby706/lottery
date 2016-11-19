#include<stdio.h>
#include<malloc.h>

int main(void)
{
	typedef struct user
	{
		char name[20];
		int age;
	}USER,*a;
	
	a c;
	c = (a)malloc(sizeof(USER));
	
	USER lb;
	a b;
	
	lb.age = 20;
	printf("%d\n",sizeof(*c));
	printf("%d\n",c->age);
	printf("%d\n",lb.age);
	
	return ;
}
