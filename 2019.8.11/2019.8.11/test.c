#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main(){
	int a = 0, b = 0, c = 0, d = 0, e = 0, i = 0;
	for (a = 1; a <= 5; a++){
		for (b = 1; b <= 5; b++){
			for (c = 1; c <= 5; c++){
				for (d = 1; d <= 5; d++){
					for (e = 1; e <= 5; e++){
						if ((b == 2 && a != 3) || (b != 2 && a == 3)){
							if ((b == 2 && e != 4) || (b != 2 && e == 4)){
								if ((c == 1 && d != 2) || (c != 1 && d == 2)){
									if ((c == 5 && d != 3) || (c != 5 && d == 3)){
										if ((e == 4 && a != 1) || (e != 4 && a == 1)){
											if (a*b*c*d*e==120){
												printf("a=%d,b=%d,c=%d,d=%d,e=%d\n", a, b, c, d, e);
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return 0;
}
//int main(){
//	char killer;
//	for (killer = 'A'; killer <= 'D'; killer++){
//		if (((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D')) == 3){
//			printf("%c是凶手\n", killer);
//			break;
//		}
//	}
//	return 0;
//}
/*
void YangHui(int h){
	int s = 0;
	int i, j;
	printf("1\n");
	for (i = 2; i <= h; s = 1, i++)
	{
		printf("1 ");
		for (j = 1; j <= i - 2; j++)
			printf("%d ", (s = (i - j) * s / j));
		printf("1\n");
	}
}
int main()
{
	int h;
	printf("请输入层数：");
	scanf("%d", &h);                 
	YangHui(9);
	return 0;
}
*/