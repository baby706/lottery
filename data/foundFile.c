#include <sys/types.h>
#include <dirent.h> //windows开发工具没有这个头文件
#include <unistd.h>
#include <string.h>
#include <stdio.h>
void writeFile()   //将读到的文件名写入filelist.txt中
{
	FILE* fp = fopen("filelist.txt","w");
    DIR * dir;
    struct dirent * ptr;
    int i=0;
    dir = opendir("purchase"); //打开一个目录
    while((ptr = readdir(dir)) != NULL) //循环读取目录数据
    {	if(strcmp(ptr->d_name,".") == 0 || strcmp(ptr->d_name,"..") == 0 )
    		continue;
    	fprintf(fp,ptr->d_name);
    	fprintf(fp,"\n");
     //   printf("d_name : %s\n", ptr->d_name); //输出文件名
    }
    closedir(dir);//关闭目录指针
    fclose(fp);
}
   
void readFile()
{
	char s[40];
	FILE* fp = fopen("filelist.txt","r");
	while(fscanf(fp,"%s",s)!=EOF)
	
	printf("%s\n",s);
	fclose(fp);

}









