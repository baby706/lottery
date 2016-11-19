#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct ElemType
{
	int id;	
}ElemType;


typedef struct DuLNode
{
	ElemType data;
	struct DuLNode *prior,*next;
}DuLNode,*DuLinkList;


//带头结点的双向循环链表的基本操作
//初始化头结点
void InitList(DuLinkList L)
{ /* 产生空的双向循环链表L */
	L=(DuLinkList)malloc(sizeof(DuLNode));
	if(L)
		L -> next = L -> prior = L;    //L为头节点
	else
		exit(1);
}


//销毁双向循环链表L
void DestroyList(DuLinkList L)
{
	DuLinkList q,p = L->next; /* p指向第一个结点 */
	while(p!=L) /* p没到表头 */
	{
		q=p->next;
		free(p);
		p=q;
	}
	free(L);
	L=NULL;
}



int main(void)
{
	printf("hello world\n");
	
	return 0;
}










