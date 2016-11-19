/*************************************************************************
	> File Name: include/base.h
	> Author: Liang Bo
	> Mail: cs-b@163.com 
	> Function: 
	> Created Time: 2016年08月12日 星期五 11时36分02秒
 ************************************************************************/
#ifndef BASH_H
#define BASH_H

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <termio.h>
#include <unistd.h>
#include <termios.h>
       


struct user
{
	char id[20];     	//帐号
	char name[20];   	//昵称
	double balance;   	//余额
	int level;       	//级别
	char passwd[20]; 	//密码
	int payMethod[3];	//支付方式
	char payPasswd[20]; //支付密码
	
};

struct userLink
{
	struct user data;
	struct userLink* next;
	struct userLink* previous;
};



#endif 



