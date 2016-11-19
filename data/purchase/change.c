#include <stdio.h>
#include "purchase.h"
#include <malloc.h>

int main(void)
{
	FILE* fp = open("a","r");
	struct purchase data;  //创建一个临时变量用来保存从文件中读取的数据
	while(1)
	{
		int res = fread(&data,sizeof(struct purchase),1,fp);  //将数据存到临时变量中，并返回读取的字节数
		if(res<1)
		{
			break;
		}
		printf("%d ",data.id);
		
	}
	fclose(fp);
	fp == NULL ;
}
