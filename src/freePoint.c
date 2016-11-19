#include "base.h"
#include "userBottomFunction.h"
#include "lottery.h"
#include "purchase.h"

void freeUserPoint(struct userLink* userHead)
{
	if(userHead == NULL)
	{	
		printf("头节点为空\n");
		return ;
	}
	//struct userLink* next = userHead->next;     //保存要被释放的节点的下一个节点
	
	while( userHead != NULL)
	{
		struct userLink* next = userHead->next;
		free(userHead);
		userHead = next;
	}
	userHead = NULL;
}

void freeLotteryPoint(struct lotteryLink* lotteryHead)
{
	if(lotteryHead == NULL)
	{	
		printf("头节点为空\n");
		return ;
	}
	//struct lotteryLink* next = lotteryHead->next;     //保存要被释放的节点的下一个节点
	
	while( lotteryHead != NULL)
	{
		struct lotteryLink* next = lotteryHead->next;
		free(lotteryHead);
		lotteryHead = next;
	}
	lotteryHead = NULL;
}

void freePurchasePoint(struct purchaseLink* purchaseHead)
{
	if(purchaseHead == NULL)
	{	
		printf("头节点为空\n");
		return ;
	}
	//struct purchaeLink* next = purchaeHead->next;     //保存要被释放的节点的下一个节点
	
	while( purchaseHead != NULL)
	{
		struct purchaseLink* next = purchaseHead->next;
		free(purchaseHead);
		purchaseHead = next;
	}
	purchaseHead = NULL;
}
