#include "base.h"
#include "purchase.h"
#include "userBottomFunction.h"
#include "color.h"
#include "foundFile.h"

void viewUser()
{
	struct userLink* userHead = (struct userLink*)calloc(1,sizeof(struct userLink));   //创建头节点,并且默认将next初始化为了NULL
	if(userHead == NULL)
	{
		printf("头节点为空!\n");
		return ;
	}
	FILE* fp = fopen("user/user.data","r");
	if(fp == NULL)
	{
		printf("加载文件中...!\n");
		return ;
	}
	struct user data;  //创建一个临时变量用来保存从文件中读取的数据
	while(1)
	{
		int res = fread(&data,sizeof(struct user),1,fp);  //将数据存到临时变量中，并返回读取的字节数
		if(res<1)
		{
			break;
		}
		printf("id is %s,",data.id);  //帐号
		//printf("name is %s ",data.name);
		printf("balance is %.2f,",data.balance);   //余额
		printf("level is %d,",data.level);
		printf("passwd is %s,",data.passwd);
		//printf("payMehtod is %s ",);int payMethod[3];
		printf("payPasswd is %s",data.payPasswd);
		RED
		printf("\n\n************************************************************************************\n\n");
		END
	}
}


void viewLottery()
{
	struct lotteryLink* lotteryHead = (struct lotteryLink*)calloc(1,sizeof(struct lotteryLink));   //创建头节点,并且默认将next初始化为了NULL
	if(lotteryHead == NULL)
	{
		printf("头节点为空!\n");
		return ;
	}
	FILE* fp = fopen("lottery/lottery.data","r");
	if(fp == NULL)
	{
		printf("加载文件中...!\n");
		return ;
	}
	struct lottery data;  //创建一个临时变量用来保存从文件中读取的数据
	while(1)
	{
		int res = fread(&data,sizeof(struct lottery),1,fp);  //将数据存到临时变量中，并返回读取的字节数
		if(res<1)
		{
			break;
		}
		printf("id is %d,",data.id);  //帐号
		//printf("name is %s ",data.name);
		printf("price is %.2f,",data.price);   //余额
		printf("status is %d,",data.status);
		printf("jackpot is %.2f,",data.jackpot);
		printf("issueTime is %s ",data.issueTime);
		printf("awardTime is %s",data.awardTime);
		RED
		printf("\n\n************************************************************************************\n\n");
		END
	}
}

void viewPurchase()
{
	struct purchaseLink* purchaseHead = (struct lotteryLink*)calloc(1,sizeof(struct purchaseLink));   //创建头节点,并且默认将next初始化为了NULL
	if(purchaseHead == NULL)
	{
		printf("头节点为空!\n");
		return ;
	}
	char fileName[40];
	writeFile();
	readFile();
	printf("请输入要查看的文件名:\n");
	scanf("%s",fileName);
	char path[] = "purchase/";
	FILE* fp = fopen(strcat(path,fileName),"r");
	if(fp == NULL)
	{
		printf("加载文件中...!\n");
		return ;
	}
	struct purchase data;  //创建一个临时变量用来保存从文件中读取的数据
	while(1)
	{
		int res = fread(&data,sizeof(struct purchase),1,fp);  //将数据存到临时变量中，并返回读取的字节数
		if(res<1)
		{
			break;
		}
		printf("Name is %s,",fileName);
		printf("ID is %d,",data.id);  //帐号
		printf("unit is %d,",data.unit);
		printf("number:");
		for(int i = 0;i<7;i++)
		{
			printf("%d ",data.number[i]);
		}
		
		/*printf("name is %s ",data.name);
		printf("balance is %.2f,",data.balance);   //余额
		printf("level is %d,",data.level);
		printf("passwd is %s,",data.passwd);
		//printf("payMehtod is %s ",);int payMethod[3];
		printf("payPasswd is %s",data.payPasswd);*/
		RED
		printf("\n\n************************************************************************************\n\n");
		END
	}
}



int main()
{
	
	int choose = -1;
	printf("1.view user\n");
	printf("2.view lottery\n");
	printf("3.view purchase\n");
	scanf("%d",&choose);
	switch(choose)
	{
		case 1:
			viewUser();
			break;
			
		case 2:
			viewLottery();
			break;
		case 3:
			viewPurchase();
			break;
	}
	
	return 0;
}
