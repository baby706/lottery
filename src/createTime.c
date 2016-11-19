#include <stdio.h>
#include <time.h>
#include <malloc.h>
char* createTime()
{
	char *p1 = (char*)calloc(37,sizeof(char));
	//char *wday[]={"星期天","星期一","星期二","星期三","星期四","星期五","星期六"};/*指针字符数组*/ 
	time_t t; 
	struct tm *p; 
	t=time(NULL);    //获取从1970年1月1日零时到现在的秒数，保存到变量t中
	p=gmtime(&t);   //变量t的值转换为实际日期时间的表示格式,gmtime的返回值是一个tm结构体
	sprintf(p1,"%d/%02d/%02d %02d:%02d:%02d",(1900+p->tm_year), (1+p->tm_mon),p->tm_mday, p->tm_hour+8, p->tm_min, p->tm_sec);
	p1[36] = '\0';
	return p1;
}
