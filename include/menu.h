/*************************************************************************
	> File Name: include/menu.h
	> Author: Liang Bo
	> Mail: cs-b@163.com 
	> Function: 
	> Created Time: 2016年08月12日 星期五 11时42分51秒
 ************************************************************************/
#ifndef MENU_H
#define MENU_H

#include "base.h"
#include "userLogicFunction.h"
#include "purchase.h"
#include "userBottomFunction.h"


//一级菜单
void menuMain(struct userLink* userHead,struct lotteryLink* lotteryHead,struct purchaseLink* purchaseHead);

//二级用户菜单
void menu2(struct userLink* pre,struct userLink* userHead,struct lotteryLink* lotteryHead,struct purchaseLink* purchaseHead);

//用户中心
void menu3(struct userLink* pre);

//管理员菜单
void menuAdmin(struct userLink* userHead,struct lotteryLink* lotteryHead,struct purchaseLink* purchaseHead);

//察看购买记录
void purchaseLotteryHistory(struct purchaseLink* purchaseHead);

//查询中奖
void checkLottery(struct userLink* pre,struct lotteryLink *lotteryHead,struct purchaseLink *purchaseHead);

void checkUser(struct userLink* userHead,struct purchaseLink* purchaseHead);

void checkName(struct userLink* userHead,char id[]);


//按余额区间查看信息
void checkBalance(struct userLink* userHead);

void sortByBalance(struct userLink* userHead);

	
void sortByName(struct userLink* userHead);






















#endif 


