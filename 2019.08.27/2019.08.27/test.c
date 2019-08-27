#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main(){
	int n = 2019;
	int sum1 = 0, sum2 = 0;
	int len1 = 0, len2 = 0;
	int count = 1;
	int i;
	for (i = n; i; i >>= 1){
		if (count & 1){
			sum1 |= (i & 1) << len1;
			len1++;
		}
		else{
			sum2 |= (i & 1) << len2;
			len2++;
		}
		count++;
	}
	for (i = len1 - 1; i >= 0; i--){
		printf("%d", sum1 >> i & 1);
	}
	putchar('\n');
	for (i = len2 - 1; i >= 0; i--){
		printf("%d", sum2 >> i & 1);
	}
	putchar('\n');
	/*printf("%d %d\n", sum1, sum2);
	printf("%d %d\n", len1, len2);*/
	return 0;
}
