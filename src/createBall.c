#include "base.h"
#include "createBall.h"
#define REDMAX 33	//红球最大值
#define BLUEMAX 16	//蓝球最大值

int* createBall(int* num,int n)
{
	int i = 0;
	int redball = 0;
	int seed = 0;				//随机种子
	seed = (int)time(0);		//系统时间作为种子,不能在多次循环里包含srand和rand函数，因为计算机速度非常快，而time的周期大概55ms
	srand( seed );				//初始化随机数发生器

	for (i=0; i<n; i++)
	{
		while ( 1 )				//循环产生合法并且不重复的红球
		{
			seed = rand();		//产生随机数
			redball = seed % REDMAX + 1;
			if ( !IsInArray(num, n, redball) )
			{
				break;
			}
			srand( seed );		//初始化随机数发生器，产生了相同的数后初始化随机种子
		}
		num[i] = redball;		//红球不重复
		srand( seed );			//初始化随机数发生器，产生了不同的数之后初始化随机种子
	}
	num[6] = rand() % BLUEMAX + 1;	//随机产生蓝球
	BubbleSortASC(num, n);	//给红球排序
	i = 0;
	return num;
}	
//判断红球是否已经存在

int IsInArray(int* array, int n, int e)

{

	int bReturn = 0;
	int i;
	for (i=0; i<n; i++)
	{
		if (array[i] == e)
		{
			bReturn = 1;
			break;
		}
	}

	return bReturn;
}

//升序排列红球
void BubbleSortASC(int* array, int n)
{

	int i, j, t;
	for (i=0; i<n-1; i++)
	{
		for (j=i+1; j<n; j++)
		{
			if (array[i] > array[j])
			{
				t = array[i];
				array[i] = array[j];
				array[j] = t;
			}
		}
	}
}


