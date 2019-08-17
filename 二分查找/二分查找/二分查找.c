#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int binarySearch(int arr[], int len, int key){
	int left = 0;
	int right = len - 1;
	while (left <= right){
		int mid = (left + right) / 2;
		if (arr[mid] > key){
			right = mid - 1;
		}
		else if (arr[mid] < key){
			left = mid + 1;
		}
		else{
			return mid;
		}
	}
	return -1;
}
int main(){
	int arr[10] = { 2, 5, 7, 8, 9, 10, 24, 27, 29, 41 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int ret = binarySearch(arr, len, 24);
	if (ret == -1){
		printf("not fount !\n");
	}
	else{
		printf("%d\n", ret);
	}
	return 0;
}