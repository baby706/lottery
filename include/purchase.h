#ifndef PURCHASE_H
#define PURCHASE_H

#include "base.h"
#include "lottery.h"
#include "userBottomFunction.h"

struct purchase
{
	int ticketNumber;     //票号
	int id;   			  //购买彩票期数
	int number[7];        //兑奖号码
	int unit;     		  //购买注数
	int money;            //金额
	int status;           //兑奖状态
	char purchaseTime[40];   //购买时间
	char admin;           //操作员	
};

struct purchaseLink
{
	struct purchase data;
	struct purchaseLink* next;
	
};

//加载文件
void loadPurchase(struct userLink* pre,struct purchaseLink* purchaseHead);

void purchaseLottery(struct userLink* pre,struct userLink* userHead,struct lotteryLink* lotteryHead,struct purchaseLink* purchaseHead);

//创建节点
struct purchaseLink* createPurchaseNode(struct purchase data);

//后向插入，将创建的节点插入purchaseLink链表尾部
void insertAfterPurchase(struct purchaseLink* purchaseHead,struct purchase data);


//查询函数
struct purchaseLink* selectPurchaseLink(struct purchaseLink* purchaseHead,char* id);



void savePurchase(struct userLink* pre,struct purchaseLink* purchaseHead);


void printPurchaseLink(struct purchaseLink* purchaseHead);


void deletePurchaseLink(struct purchaseLink* pre);


#endif
