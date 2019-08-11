#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int myStrlen(const char * str)
{
	if (*str == '\0')
	{
		return 0;
	}
	return 1 + myStrlen(str + 1);
}
void reverse_string(char * str)
{
	if (*str)
	{
		int tmp;
		int end = strlen(str) - 1;

		tmp = *str;
		*str = str[end];
		str[end] = '\0';
		reverse_string(str + 1);
		str[end] = tmp;
	}
}
void SwitchNum(int n, int m)
{
	if (n == 0)
	{
		return;
	}
	SwitchNum(n / m, m);
	putchar("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[n % m]);
}
int main(){
	SwitchNum(10, 2);
	printf("\n");
	char str[] = "abcdef";
	reverse_string(str);
	printf("%s\n",str);
	return 0;
}