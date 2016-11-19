#include "base.h"
#include "lottery.h"
#include "createTime.h"
#include "menu.h"
#include "color.h"
#include <unistd.h>

int usleep(unsigned int );
//发行彩票
void issueLottery(struct lotteryLink* lotteryHead)
{
	
	struct lottery data;
	if(lotteryHead == NULL)
	{
		printf("头节点为空!\n");
		return ;
	}

	while(lotteryHead->next != NULL)
	{
		lotteryHead = lotteryHead->next;	
	}
	if(!(lotteryHead->data.status))
	{
		RED;
		printf("当期彩票暂未开奖，请开奖后再发行新的彩票!\n");
		END;
		usleep(1000000);
		return ;
	}
	printf("请输入单价:");
	scanf("%f",&data.price);
	data.id = lotteryHead->data.id + 1;
	strcpy(data.issueTime,createTime());
	data.jackpot = 50000000;
	data.totalJackpot = 50000000;
	data.status = 0;
	data.count = 0;
	
	insertAfterLottery(lotteryHead,data);
	printf("第%d期彩票发行成功!\n",data.id);
	saveLottery(lotteryHead);
	while(getchar() != '\n');
	printf("返回请按\033[31;1mENTER键\033[0m\n");
	while(getchar() == '\n')
	{
		return ;
	}
}



//底层函数
//创建节点，将新的数据块存入lotteryLink结构体
struct lotteryLink* createLotteryNode(struct lottery data)
{
	struct lotteryLink* new = (struct lotteryLink*)calloc(1,sizeof(struct lotteryLink));
	new->data = data;
	new->next = NULL;

	return new;
}

//后向插入，将创建的节点插入lotteryLink链表尾部
void insertAfterLottery(struct lotteryLink* lotteryHead,struct lottery data)
{
	if(lotteryHead == NULL)
	{
		printf("头节点为空!\n");
		return ;
	}
	while(lotteryHead->next != NULL)
	{
		lotteryHead = lotteryHead->next;
	}
	struct lotteryLink* new = createLotteryNode(data);
	lotteryHead->next = new;
}

//查询函数
struct lotteryLink* selectlotteryLink(struct lotteryLink* lotteryHead,int id)
{
	if(lotteryHead == NULL)
	{
		printf("头节点为空!\n");
		return NULL;
	}
	
	lotteryHead = lotteryHead->next;   //跳过头节点
	while(lotteryHead != NULL)
	{
		if(lotteryHead->data.id == id)
		{
			return lotteryHead;
		}
		lotteryHead = lotteryHead->next;
	}
	return NULL;
}

//加载文件
void loadLottery(struct lotteryLink* lotteryHead)
{
	if(lotteryHead == NULL)
	{
		printf("头节点为空!\n");
		return ;
	}
	FILE* fp = fopen("data/lottery/lottery.data","r");
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
		insertAfterLottery(lotteryHead,data);
		
	}
	fclose(fp);
	fp = NULL ;
}

//保存文件
void saveLottery(struct lotteryLink* lotteryHead)
{
	if(lotteryHead == NULL)
	{
		printf("头节点为空!\n");
		return ;
	}
	FILE* fp = fopen("data/lottery/lottery.data","w");
	if(fp == NULL)
	{
		printf("写入文件失败!\n");
		return ;
	}
	lotteryHead = lotteryHead->next;   //跳过头节点
	while(lotteryHead != NULL)
	{
		fwrite(&lotteryHead->data,sizeof(struct lottery),1,fp);
		lotteryHead = lotteryHead->next;
	}
	fclose(fp);
	fp = NULL;
}

//查看发行记录
void printLotteryLink(struct lotteryLink* lotteryHead)
{
	char status[20] = "\0";
	struct lotteryLink* saveLotteryHead = lotteryHead;
	if(lotteryHead == NULL)
	{	
		printf("头节点为空!\n");
		return ;
	}
	
	if(lotteryHead -> next ==  NULL)
	{	
		RED;
		printf("抱歉，暂未发行彩票!\n");
		END;
		usleep(1500000);
		return ;
	}
	lotteryHead = lotteryHead -> next;    //跳过头节点
	saveLotteryHead = saveLotteryHead -> next;
	while(saveLotteryHead->next != NULL)
	{
		saveLotteryHead = saveLotteryHead->next;
	}
	system("clear");
	printf("%d年共发行了%d期彩票\n",saveLotteryHead->data.id / 1000,saveLotteryHead->data.id % 1000);
	PURPLE;
	printf("期号       状态       单价      发行时间               累计奖池      购买总数\n");
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
		printf("%d    %s     %.2f      %s    ",lotteryHead->data.id,status,lotteryHead->data.price,lotteryHead->data.issueTime);
		if(lotteryHead->data.status)
		{
			printf("%.2f    ",lotteryHead->data.totalJackpot);
		}
		else
		{
			printf("%.2f    ",lotteryHead->data.jackpot);
		}
		printf("%d\n",lotteryHead->data.count);
		lotteryHead = lotteryHead->next;
	}
	while(getchar() != '\n');	
	printf("\n\n返回请按\033[31;1mENTER键！\n");
	END;
	while(getchar() == '\n')
	{
		return ;
	}
}
















