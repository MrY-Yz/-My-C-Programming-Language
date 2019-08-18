#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define ROW 3
#define COL 3
void adjust_array(int* arr,int len){
	int i = 0;
	int sub = len - 1;//下标
	for (i = 0; i <= sub; i++){
		if (arr[i] % 2 == 0){
			int tmp = arr[i];
			arr[i] = arr[sub];
			arr[sub] = tmp;
			sub = sub - 1;
			i = i - 1;
		}
	}
}
void show_array(int* arr,int len){
	int i = 0;
	for (i = 0; i < len; i++){
		printf("%d ",arr[i]);
	}
}
int YangArray(int arr[ROW][COL], int num) {
	int i = 0;
	int j = COL - 1;
	int tmp = arr[i][j];
	while (1) {
		if (num == tmp) {
			return 1;
		}
		else if (num > tmp && i < ROW - 1) {
			tmp = arr[i++][j];
		}
		else if (num < tmp && j > 0) {
			tmp = arr[i][j--];
		}
		else {
			return 0;
		}
	}
}
int main(){
	int arr[10] = { 1, 4, 3, 7, 10, 55, 23, 48, 21, 16 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int arr2[3][3] = { { 1, 2, 3 }, { 2, 3, 4 }, { 3, 4, 5 } };
	int num = 9;
	if (YangArray(arr2, num) == 1) {
		printf("这个数存在\n");
	}
	else {
		printf("这个数不存在\n");
	}
	adjust_array(arr, len);
	show_array(arr, len);
	printf("\n");
	return 0;
}