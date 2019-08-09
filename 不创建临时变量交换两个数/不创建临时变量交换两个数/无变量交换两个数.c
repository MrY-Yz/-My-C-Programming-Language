#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int a = 10;
	int b = 20;
	int tmp = 0;
	printf("a=%d,b=%d\n", a, b);
	tmp = a;
	a = b;
	b = tmp;
	printf("a=%d,b=%d\n", a, b);
	/*int a=1, b=0;
	a = a^b;
	b = a^b;
	a = a^b;
	printf("%d %d\n", a, b);
	return 0;*/
}
//#include<stdio.h>
//int main(){
//	int x = 10, y = 20;
//	x = x + y;
//	y = x - y;
//	x = x - y;
//	printf("x=%d,y=%d",x,y);
//	return 0;
//}