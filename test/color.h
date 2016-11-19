#ifndef __COLOR_H__
#define __COLOR_H__

#include <stdio.h>

//前景色
#define BLACK      printf("\033[30;1m");
#define RED        printf("\033[31;1m");
#define GREEN      printf("\033[32;1m");
#define YELLOW     printf("\033[33;1m)";
#define BLUE       printf("\033[34;1m");
#define PURPLE     printf("\033[35;1m");
#define DEEPGREEN  printf("\033[36;1m");
#define WHITE      printf("\033[37;1m");

//背景色
#define bBLACK      printf("\033[40;1m");
#define bRED        printf("\033[41;1m");
#define bGREEN      printf("\033[42;1m");
#define bYELLOW     printf("\033[43;1m)";
#define bBLUE       printf("\033[44;1m");
#define bPURPLE     printf("\033[45;1m");
#define bDEEPGREEN  printf("\033[46;1m");
#define bWHITE      printf("\033[47;1m");

//ANSI控制码
#define UNDERLINE   printf("\033[4m");
#define FLUSH       printf("\033[5m");
#define REVERSE     printf("\033[7m");
#define HIDE        printf("\033[8m");
#define CLEAR       printf("\033[2J");
#define UP2         printf("\033[2A");

#define END printf("\033[0m");


#endif















