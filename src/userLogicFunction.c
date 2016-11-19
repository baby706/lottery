/*************************************************************************
	> File Name: userLogicFunction.c
	> Author: Liang Bo
	> Mail: cs-b@163.com 
	> Function: 
	> Created Time: 2016年08月12日 星期五 15时26分04秒
 ************************************************************************/

#include "base.h"
#include "userBottomFunction.h"
#include "lottery.h"
#include "menu.h"
#include "userLogicFunction.h"
#include "notary.h"
#include "function.h"
#include "color.h"
#include "purchase.h"

//用户登陆
void loginUser(struct userLink* userHead,struct lotteryLink* lotteryHead,struct purchaseLink* purchaseHead)
{
	
	
		char id[20];
		char passwd[20];
		printf("请输入用户名:");
		scanf("%s",id);
		printf("请输入密码:");
		while(getchar()!='\n');
		hidePasswd(passwd);
		if(strcmp(id,"admin") == 0 && strcmp(passwd,"admin") == 0)
		{
			YELLOW;
			printf("\n管理员登陆成功!\n");
			END;
			usleep(1500000);
			menuAdmin(userHead,lotteryHead,purchaseHead);
			return ;
		}
		else
		{
			if(strcmp(id,"gzy") == 0 && strcmp(passwd,"gzy") == 0)
			{
				YELLOW;
				printf("\n公证员登陆成功!\n");
				END;
				usleep(1500000);
				menuNotary(lotteryHead);
				return ;
			}
		}
		struct userLink* pre = selectUserLink(userHead,id);
		if(pre == NULL)
		{
			
			RED;
			printf("\n用户名或密码错误，请重试！\n");
			END;
			usleep(1000000);
			
			
		}
		else
		{
			if(strcmp(passwd,pre->next->data.passwd) == 0)
			{
				YELLOW;
				printf("\n恭喜您，登陆成功!\n");
				END;
				usleep(1500000);   //系统保留1.5秒
				if(purchaseHead->next == NULL)
				{
					loadPurchase(pre,purchaseHead);
				}
				menu2(pre,userHead,lotteryHead,purchaseHead);
			}
			else
			{
				RED;
				printf("\n用户名或密码错误，请重试!\n");
				END;
				usleep(1000000);
				
			}
		}
	
	
}

//用户注册
void registerUser(struct userLink* userHead)
{
	if(userHead == NULL)
	{	
		printf("头节点为空!\n");
		return ;
	}
	struct user data;
	printf("请输入你的用户名:\n");
	scanf("%s",data.id);
	struct userLink* pre = selectUserLink(userHead,data.id);
	if(pre != NULL)
	{
		printf("用户已存在，请重试！\n");
		sleep(1);
		return ;
	}
	printf("请输入你的密码:\n");
	while(getchar() != '\n');
	hidePasswd(data.passwd);
	//scanf("%s",data.passwd);
	
	data.balance = 50;   //初始余额
	data.payMethod[0] = 0;   //支付方式默认未选择
	data.payMethod[1] = 0;
	data.payMethod[2] = 0;
	insertAfterUser(userHead,data);
	RED;
	printf("\n恭喜%s，您已注册成功！\n",data.id);
	END;
	usleep(1500000);
}

//修改密码
void changeUserPasswd(struct userLink* pre)
{
	char oldPasswd[20];
	while(getchar() != '\n');
	printf("请输入您的旧密码:");
	hidePasswd(oldPasswd);
	//scanf("%s",oldPasswd);
	if(strcmp(oldPasswd,pre->next->data.passwd) == 0)
	{	
	 	printf("\n密码验证成功!\n");
		printf("请输入您的新密码:");
		char new1Passwd[20];
		char new2Passwd[20];
		hidePasswd(new1Passwd);
		/* 添加验证算法 */
		printf("\n请再输入一次:");
		hidePasswd(new2Passwd);
		while(getchar()!='\n');
		if(strcmp(new1Passwd,new2Passwd) == 0)
		{
			strcpy(pre->next->data.passwd,new1Passwd);
			printf("密码修改成功！返回 Y/N");
			
			char confirm = getchar();
			if(confirm == 'Y' || confirm == 'y')
			{
				system("clear");
				return ;
			}
			
		}	
		else
		{
			printf("两次密码输入不一致，请重试!\n");
			return ;
		}
	}
	else
	{
		printf("密码验证失败，将返回上级菜单！\n");
		return ;
	}
	
}

//查看用户信息
void printUser(struct userLink* pre)
{
	system("clear");
	printf("您目前的账户信息为:\n");
	printf("用户名:%s     余额：%.2f     \n\n",pre->next->data.id,pre->next->data.balance);
	menu3(pre);
}

//余额充值
void chargeUserBalance(struct userLink* pre)
{
	int i = 3;
	int choose = -1;
	float charge;
	char payPasswd[6];
	printf("请选择支付方式:\n");
	printf("1.银行卡支付\n");
	printf("2.支付宝支付\n");
	printf("3.微信支付\n");
	scanf("%d",&choose);
	if(pre->next->data.payMethod[0] == 0)
	{
		printf("您暂未绑定银行卡，请先绑定银行卡.\n");
		bindingBankCard(pre);
	}
	else
	{
		
	}
	system("clear");
	printf("请输入你要充值的金额：");
	scanf("%f",&charge);
	if(charge < 0)
	{
		printf("您输入的金额不正确，请重新输入！\n");
		usleep(1000000);
		system("clear");
		return ;
	}
	while(i)
	{	
		
		while(getchar() != '\n');
		printf("您即将向您的账户充值%.2f元，请输入支付密码:",charge);
		
		hidePasswd(payPasswd);
		if(strcmp(payPasswd,pre->next->data.payPasswd) == 0)
		{
			pre->next->data.balance = pre->next->data.balance + charge;
			printf("\n支付成功，当前余额%.2f\n",pre->next->data.balance);
			break;
		}
		else
		{
			printf("密码错误!\n");
			usleep(1000000);
			i--;
		}
	}
	if(!i)
	{
		printf("密码出错次数达到上限，请24小时后重试!\n");
		usleep(1000000);
			system("clear");
		return ;	
	}
}

//绑定银行卡
void bindingBankCard(struct userLink* pre)
{
	char payPasswd[20];
	printf("请输入您的银行卡卡号:\n");
	//int 
	//scanf("")
	while(getchar() != '\n');
	printf("请输入您的支付密码:");
	hidePasswd(payPasswd);
	//scanf("%s",payPasswd);
	strcpy(pre->next->data.payPasswd,payPasswd);
	pre->next->data.payMethod[0] = 1;
	RED;
	printf("\n绑定银行卡成功!\n");
	END;
	usleep(1000000);
}

//注销用户
void deleteUser(struct userLink* pre)
{
	char choose;
	while(getchar() != '\n');
	printf("是否注销？  [Y/N]    ");
	choose = getchar();
	if(choose == 'Y' || choose == 'y')
	{
		deleteUserLink(pre);
		printf("用户注销成功!即将返回登陆界面\n");
		usleep(1500000);
	}
	else
		if( choose == 'N' || choose == 'n')
		{
			return ;
		}
}























