#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int count_one_bits(int n){
	int count = 0;
	while (n != 0){
		n = n&n - 1;
		count++;
	}
	return count;
}
void show_odd_even_bits(int n){
	int i = 0,j = 0;
	printf("偶数位：");
	for (i = 31; i >=1; i -= 2){
		printf("%d ", (n>>i) & 1);
	}
	printf("\n");
	printf("奇数位：");
	for (j = 30; j >= 0; j -= 2){
		printf("%d ", (n>>j) & 1);
	}	
	printf("\n");
}
void show_integral_number_bit(int n){
	int i = 0;
	for (i = n; i; i /= 10){
		printf("%d ", i % 10);
	}
	printf("\n");
}
int different_bits(int m,int n){
	int x = m^n;
	return count_one_bits(x);
}
int main(){
	int ret2 = different_bits(1999,2299);
	printf("%d\n", ret2);
	show_integral_number_bit(546);
	show_odd_even_bits(11);
	int ret = count_one_bits(-1);
	printf("%d\n", ret);
	return 0;
}