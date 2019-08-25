#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int DigitSum(int n){
	int sum = 0;
	if (n == 0){
		return 0;
	}
	else{
		return (n % 10) + DigitSum(n / 10);
	}
}
int main(){
	int ret=DigitSum(1259);
	printf("%d\n", ret);
	return 0;
}
#if 0
int DigitSum(int n){
	int i = 0;
	int sum = 0;
	int tmp = 0;
	for (i = n; i>0;i = i / 10){
		tmp = i % 10;
		sum += tmp;
	}
	return sum;
}
int main(){
	int ret=DigitSum(1357);
	printf("%d\n", ret);
	return 0;
}
#endif