#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
unsigned int reverse_bit(unsigned int value){
	int arr[32] = { 0 };
	unsigned int sum = 0;
	for (int i = 0; i < 32; i++)
	{
		arr[i] = value & 1;
		value = value >> 1;
	}
	for (int i = 0; i < 32; i++)
	{
		sum = sum + arr[i] * pow(2, 32 - 1 - i);
	}
	return sum;
}
void average(int a,int b){
	printf("%d\n", (a&b) + ((a^b) >> 1));
}
int main(){
	int arr[9] = { 2, 5, 7, 4, 4, 2, 1, 7, 1 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int i = 0, ret1 = 0;
	for (i = 0; i < len; i++){
		ret1 = ret1^arr[i];
	}
	printf("���������ǣ�%d\n",ret1);
	int ret=reverse_bit(25);
	printf("��ת��%u\n", ret);
	average(10, 20);
	return 0;
}