/*************************************************************************
	> File Name: lottery.h
	> Author: Liang Bo
	> Mail: cs-b@163.com 
	> Function: 
	> Created Time: 2016年08月14日 星期日 11时50分17秒
 ************************************************************************/
#ifndef LOTTERY_H
#define LOTTERY_H
struct lottery
{
	int id;  //发行期数
	float price;  //单价
	int status;   //开奖状态
	int number[7];   //当期中奖号码
	int count;    //购买总数
	double jackpot;   //当期奖池金额
	double totalJackpot;  //总奖池
	char issueTime[40];   //发行时间
	char awardTime[40];   //开奖时间
};

struct lotteryLink
{	
	struct lottery data;
	struct lotteryLink* next;
};

//创建节点
struct lotteryLink* createLotteryNode(struct lottery data);  

//后向插入
void insertAfterLottery(struct lotteryLink* lotteryHead,struct lottery data);

//查询函数
struct lotteryLink* selectLotteryLink(struct lotteryLink* lotteryHead,int id);

//加载文件
void loadLottery(struct lotteryLink* lotteryHead);

//保存文件
void saveLottery(struct lotteryLink* lotteryHead);

//查看彩票发行记录
void printLotteryLink(struct lotteryLink* lotteryHead);

//
void issueLottery(struct lotteryLink* lotteryHead);




#endif 


