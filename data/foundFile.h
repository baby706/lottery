#ifndef FOUNDFILE_H
#define FOUNDFILE_H


#include <sys/types.h>
#include <dirent.h> //windows开发工具没有这个头文件
#include <unistd.h>
#include <string.h>
#include <stdio.h>


void writeFile();

void readFile();

#endif
