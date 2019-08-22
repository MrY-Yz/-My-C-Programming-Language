#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main(){
	int sum = 0;
	int arr[10] = { 1, 2, 3, 2, 4, 6, 1, 8, 3, 4 };
	int i;
	for (i = 0; i < 10; i++){
		sum ^= arr[i];
	}
	int n = -1;
	for (i = 0; i < 32; i++){
		if (sum >> i & 1)
		{
			n = i;
			break;
		}
	}
	int sum1 = 0, sum2 = 0;
	for (i = 0; i < 10; i++){
		if (arr[i] >> n & 1){
			sum1 ^= arr[i];
		}
		else{
			sum2 ^= arr[i];
		}
	}
	printf("%d %d\n", sum1, sum2);
	return 0;
}