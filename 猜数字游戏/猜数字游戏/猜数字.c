#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
void Menu()
{
	printf("*************************\n");
	printf("*******1.play************\n");
	printf("*******0.exit************\n");
	printf("*************************\n");
}
void game()
{

	int randnum = rand() % 100 + 1;//[1,101)
	printf("开始游戏\n");
	//RAND_MAX;
	while (1)//
	{
		int num = 0;
		printf("老铁，请输入你要猜的数字:->");
		scanf("%d", &num);
		if (num == randnum)
		{
			printf("您猜对了\n");
			break;
		}
		else if (num > randnum)
		{
			printf("猜大了\n");
		}
		else if (num < randnum)
		{
			printf("猜小了\n");
		}
	}
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));//设置随机种子
	do
	{
		Menu();
		printf("请老铁输入你的操作：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("游戏退出\n");
			break;
		default:
			printf("老铁擦亮眼睛，输入正确的数字\n");
			break;
		}

	} while (input);
	return 0;
}