/*************************************************************************
	> File Name: userLogicFunction.h
	> Author: Liang Bo
	> Mail: cs-b@163.com 
	> Function: 
	> Created Time: 2016年08月12日 星期五 16时45分07秒
 ************************************************************************/
#ifndef USERLOGICFUNCTION_H
#define USERLOGICFUNCTION_H

#include "base.h"
#include "lottery.h"
#include "purchase.h"
#include "userBottomFunction.h"

void registerUser(struct userLink* userHead);

void loginUser(struct userLink* userHead,struct lotteryLink* lotteryHead,struct purchaseLink* purchaseHead);

void bindingBankCard(struct userLink* pre);

void chargeUserBalance(struct userLink* pre);

void deleteUser(struct userLink* pre);

void printUser(struct userLink* pre);

void changeUserPasswd(struct userLink* pre);

#endif 


