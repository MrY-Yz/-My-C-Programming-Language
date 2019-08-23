#include<stdio.h>
int main(){
	int arr[10] = {0,3,2,4,1,9,5,6,7,8,};
	int max = 0;
	int i = 0;
	for (i = 0; i < 10; i++){
		if (max < arr[i]){
			max = arr[i];
		}
	}
	printf("%d\n", max);
	return 0;
}
/*
int main(){
	int arr[10] = { 8, 4, 7, 0, -1, 9, 2, -3, 3, 1 };
	int max = 0x80000000;
	int sec = 0x80000000;
	int i;
	for (i = 0; i < 10; i++){
		if (max < arr[i]){
			sec = max;
			max = arr[i];
		}
		else if (sec < arr[i]){
			sec = arr[i];
		}
	}
	printf("%d", sec);
	return 0;
	}*/