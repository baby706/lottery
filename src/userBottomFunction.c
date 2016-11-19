/*************************************************************************
	> File Name: src/user.c
	> Author: Liang Bo
	> Mail: cs-b@163.com 
	> Function: 
	> Created Time: 2016年08月12日 星期五 12时05分20秒
 ************************************************************************/

#include "base.h"
#include "userBottomFunction.h"




//底层函数
//创建节点，将新的数据块存入userLink结构体
struct userLink* createUserNode(struct user data)
{
	struct userLink* new = (struct userLink*)calloc(1,sizeof(struct userLink));
	new->data = data;
	new->next = NULL;

	return new;
}

//后向插入，将创建的节点插入userLink链表尾部
void insertAfterUser(struct userLink* userHead,struct user data)
{
	if(userHead == NULL)
	{
		printf("头节点为空!\n");
		return ;
	}
	while(userHead->next != NULL)
	{
		userHead = userHead->next;
	}
	struct userLink* new = createUserNode(data);
	userHead->next = new;
}

//查询函数
struct userLink* selectUserLink(struct userLink* userHead,char *id)
{
	if(userHead == NULL)
	{
		printf("头节点为空!\n");
		return NULL;
	}
	
	struct userLink* pre = userHead;   //保留当前查询到的id的上一个节点
	userHead = userHead->next;   //跳过头节点
	while(userHead != NULL)
	{
		if(strcmp(userHead->data.id,id) == 0)
		{
			return pre;
		}
		pre = userHead;
		userHead = userHead->next;
	}
	return NULL;
}

//加载文件
void loadUser(struct userLink* userHead)
{
	if(userHead == NULL)
	{
		printf("头节点为空!\n");
		return ;
	}
	FILE* fp = fopen("data/user/user.data","r");
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
		insertAfterUser(userHead,data);
		
	}
	fclose(fp);
	fp = NULL ;
}

//保存用户链表
void saveUser(struct userLink* userHead)
{
	if(userHead == NULL)
	{
		printf("头节点为空!\n");
		return ;
	}
	FILE* fp = fopen("data/user/user.data","w");
	if(fp == NULL)
	{
		printf("写入文件失败!\n");
		return ;
	}
	userHead = userHead->next;   //跳过头节点
	while(userHead != NULL)
	{
		fwrite(&userHead->data,sizeof(struct user),1,fp);
		userHead = userHead->next;
	}
	fclose(fp);
	fp = NULL;
}

//查看用户链表
void printUserLink(struct userLink* userHead)
{
	if(userHead == NULL)
	{	
		printf("头节点为空!\n");
		return ;
	}
	userHead = userHead -> next;
	while(userHead != NULL)
	{
		printf("用户名:%s    密码：***   余额:%.2f\n",userHead->data.id,userHead->data.balance);
		userHead = userHead->next;
	}
	while(getchar() != '\n');
	printf("继续请按\033[31;1mENTER\033[0m键\n");
	while(getchar() == '\n')
	{
		system("clear");
		return ;
	}
}

void deleteUserLink(struct userLink* pre)
{
	struct userLink* save = pre->next;
	pre->next = save->next;
	free(save);
	save = NULL;

}




















