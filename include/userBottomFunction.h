/*************************************************************************
	> File Name: user.h
	> Author: Liang Bo
	> Mail: cs-b@163.com 
	> Function: 
	> Created Time: 2016年08月12日 星期五 15时15分23秒
 ************************************************************************/
#ifndef USER_H
#define USER_H


//创建节点
struct userLink* createUserNode(struct user data);  

//后向插入
void insertAfterUser(struct userLink* p,struct user data);

//查询函数
struct userLink* selectUserLink(struct userLink* userHead,char *id);

//加载文件
void loadUser(struct userLink* userHead);

//保存文件
void saveUser(struct userLink* userHead);

//查看用户
void printUserLink(struct userLink* userHead);

//注销用户
void deleteUserLink(struct userLink* pre);

#endif 


