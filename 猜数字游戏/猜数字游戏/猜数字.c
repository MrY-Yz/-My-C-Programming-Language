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
	printf("��ʼ��Ϸ\n");
	//RAND_MAX;
	while (1)//
	{
		int num = 0;
		printf("��������������Ҫ�µ�����:->");
		scanf("%d", &num);
		if (num == randnum)
		{
			printf("���¶���\n");
			break;
		}
		else if (num > randnum)
		{
			printf("�´���\n");
		}
		else if (num < randnum)
		{
			printf("��С��\n");
		}
	}
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));//�����������
	do
	{
		Menu();
		printf("������������Ĳ�����");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("��Ϸ�˳�\n");
			break;
		default:
			printf("���������۾���������ȷ������\n");
			break;
		}

	} while (input);
	return 0;
}