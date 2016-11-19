#include "base.h"
#include <termios.h>
#include <unistd.h>

void cfmakeraw(struct termios *termios_p);

int getch(void)    //定义getch函数
{
     struct termios tm, tm_old;
     int fd= 0, ch; 
     if (tcgetattr(fd, &tm) < 0) //保存现在的终端设置
	 {
          return -1;
     } 
     tm_old = tm;
     cfmakeraw(&tm);//更改终端设置为原始模式，该模式下所有的输入数据以字节为单位被处理
     if (tcsetattr(fd, TCSANOW, &tm) < 0) //设置上更改之后的设置
	 {
          return -1;
     } 
     ch = getchar();
     if (tcsetattr(fd, TCSANOW, &tm_old) < 0) //更改设置为最初的样子
	 {
          return -1;
     }   
     return ch;
}


void hidePasswd(char* passwd)   //定义隐藏密码函数
{
	int i=0;
	while(1)
	{
		char ch=getch();
		if(ch==127)
		{
			if(i==0)
			{
				continue;
			}else
			{
 	   			printf("\b \b");
				passwd[i-1]='\0';
				i--;
				continue;
	 		}
		}
		else
			if(ch=='\r')
			{
				passwd[i] = '\0';
				break;
			}
			else
			{
  	 		 	passwd[i]=ch;
				printf("*");
				i++;
			}
	} 
}




