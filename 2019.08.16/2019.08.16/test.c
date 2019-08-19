#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
void reverse(char* left, char* right){
	while (left < right){
		int tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
void left_remove(char *arr,int n,int len){
	reverse(arr, arr + n - 1);
	reverse(arr + n, arr + len - 1);
	reverse(arr, arr + len - 1);
}
int Compare(char* str,char* sub,int len){
	char *arr[11] = { 0 };
	strcpy(arr, str);
	strcat(arr, str);
	if (strstr(arr, sub) == NULL)//strstr()����������Ϊ�����ַ����������ַ���ѭ���Ƚϣ����p�в�����sub�ַ������򷵻�NULL
		return 0;
	return 1;
}
int main(){
	char arr[] = "ABCDE";
	int n = 2;
	int len = strlen(arr);
	printf("����ǰ��%s\n", arr);
	left_remove(arr,2,len);
	printf("������%s\n", arr);
	char arr1[] = "AABCD";
	char arr2[] = "BCDAA";
	int ret = Compare(arr1, arr2, len);
	printf("%d\n",ret);
	return 0;
}