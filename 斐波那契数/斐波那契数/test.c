#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int Fibonacci1(int n){
	if (n == 1 || n == 2){
		return 1;
	}
	else {
		return Fibonacci(n - 2) + Fibonacci(n - 1);
	}
}
int Fibonacci(int n){
	int a1 = 1, a2 = 1, a3 = 0, i;
	if (n == 1 || n == 2){
		return 1;
	}
	else {
		for (i = 3; i <= n; i++){
			a3 = a1 + a2;
			a1 = a2;
			a2 = a3;
		}
		return a3;
	}
}
int main(){
	int n = 6;
	int ret1 = Fibonacci1(n);
	int ret=Fibonacci(n);
	printf("%d\n", ret);
	printf("%d\n", ret1);
	return 0;
}
