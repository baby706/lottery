#include "base.h"
#include "lottery.h"
#include "createBall.h"
#include "notary.h"
#include "color.h"
#include "createTime.h"
#include <unistd.h>


void menuNotary(struct lotteryLink* lotteryHead)
{
	while(1)
	{
		system("clear");
		int choose = -1;
		printf("\t\t\t\t*****************************************\n");
		printf("\t\t\t\t*\t\t\t\t\t*\n");
		printf("\t\t\t\t*\t\t1.现在开奖\t\t*\n");
		printf("\t\t\t\t*\t\t2.手动开奖\t\t*\n");
		printf("\t\t\t\t*\t\t3.查看信息\t\t*\n");
		printf("\t\t\t\t*\t\t4.返回上级\t\t*\n");
		printf("\t\t\t\t*\t\t\t\t\t*\n");
		printf("\t\t\t\t*****************************************\n\n");
		printf("\t\t\t\t请选择:");
		scanf("%d",&choose);
		switch(choose)
		{
			case 1:
				drawLottery2(lotteryHead);
				break;
			case 2:
				drawLottery(lotteryHead);
				break;
			case 3:
				viewLottery(lotteryHead);
				break;
			case 4:
				return ;
			default:
				break;
		}
	}
}

//开奖函数
void drawLottery(struct lotteryLink* lotteryHead)
{
	
	if(lotteryHead == NULL)
	{
		printf("头节点为空\n");
		return ;
	}
	
	if(lotteryHead -> next == NULL)
	{
		RED;
		printf("暂未发行新的彩票,请联系管理员先发行彩票！\n");
		END;
		usleep(1500000);
		return ;
	}
	
	while(lotteryHead->next != NULL)
	{
		lotteryHead = lotteryHead -> next;	
	}
	
	if(lotteryHead->data.status)
	{
		RED;
		printf("暂未发行新的彩票,请联系管理员先发行彩票！\n");
		END;
		usleep(1500000);
		return ;
	}
	else
	{
		
		lotteryHead->data.status = 1;
		//createBall(lotteryHead->data.number,6);
		for(int i = 0;i<7;i++)
		{
			lotteryHead->data.number[i] = i + 1;
		}
		strcpy(lotteryHead->data.awardTime,createTime());
		system("clear");
		printf("第%d期双色球开奖结果:",lotteryHead->data.id);
		printf("红色球为:");
		for(int i = 0;i<6;i++)
		{
			printf("\033[31;1m%d ",lotteryHead->data.number[i]);
		}
		END;
		lotteryHead->data.totalJackpot = lotteryHead->data.jackpot;
		printf("蓝色球为:\033[34;1m%d\033[0m\n",lotteryHead->data.number[6]);
		printf("本次开奖成功!\n");
		while(getchar() != '\n');
		printf("返回请按\033[31;1mENTER\033[0m键!\n");
		while(getchar() == '\n')
		{
			return ;
		}
	}
	saveLottery(lotteryHead);
	
}

void drawLottery2(struct lotteryLink* lotteryHead)
{
	
	if(lotteryHead == NULL)
	{
		printf("头节点为空\n");
		return ;
	}
	
	if(lotteryHead -> next == NULL)
	{
		RED;
		printf("暂未发行新的彩票,请联系管理员先发行彩票！\n");
		END;
		usleep(1500000);
		return ;
	}
	
	while(lotteryHead->next != NULL)
	{
		lotteryHead = lotteryHead -> next;	
	}
	
	if(lotteryHead->data.status)
	{
		RED;
		printf("暂未发行新的彩票,请联系管理员先发行彩票！\n");
		END;
		usleep(1500000);
		return ;
	}
	else
	{
		
		lotteryHead->data.status = 1;
		createBall(lotteryHead->data.number,6);
		strcpy(lotteryHead->data.awardTime,createTime());
		system("clear");
		printf("第%d期双色球开奖结果:",lotteryHead->data.id);
		printf("红色球为:");
		for(int i = 0;i<6;i++)
		{
			printf("\033[31;1m%d ",lotteryHead->data.number[i]);
		}
		END;
		lotteryHead->data.totalJackpot = lotteryHead->data.jackpot;
		printf("蓝色球为:\033[34;1m%d\033[0m\n",lotteryHead->data.number[6]);
		printf("本次开奖成功!\n");
		while(getchar() != '\n');
		printf("返回请按\033[31;1mENTER\033[0m键!\n");
		while(getchar() == '\n')
		{
			return ;
		}
	}
	saveLottery(lotteryHead);
	
}

//查看信息
void viewLottery(struct lotteryLink* lotteryHead)
{
	char status[20] = "";
	if(lotteryHead == NULL)
	{	
		printf("头节点为空!\n");
		return ;
	}
	lotteryHead = lotteryHead -> next;    //跳过头节点
	system("clear");
	PURPLE;
	printf("期号      单价    状态       发行时间                 开奖时间                中奖号码         发行总数\n");
	END;
	while(lotteryHead != NULL)
	{
		if(lotteryHead->data.status)
		{
			strcpy(status,"已开奖");
		}
		else
		{
			strcpy(status,"未开奖");
		}
		printf("%d   %.2f    %s     %s      ",lotteryHead->data.id,lotteryHead->data.price,status,lotteryHead->data.issueTime);
		if(lotteryHead->data.status)
		{
			printf("%s     ",lotteryHead->data.awardTime);
			for(int i = 0;i<6;i++)
			{
				RED;
				printf("%d ",lotteryHead->data.number[i]);
				END
			}
			BLUE;
			printf("%d",lotteryHead->data.number[6]);
			END;
			printf("\t10000000\n");
		}
		lotteryHead = lotteryHead->next;
	}
	printf("\n\n");
	
	while(getchar() != '\n');
	printf("返回请按\033[31;1mENTER键\033[0m\n");
	while(getchar() == '\n')
	{
		return ;
	}
}




















