#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以多少汽水。编程实现。
int Buysoda(int M){
	static int flag = 0;//flag作为一个判断，看在本次兑换之前的兑换中是否有多余的一个瓶盖
	if (2 * M + flag < 2){//判断能否购买汽水
		return 0;
	}
	if (M % 2 == 0){//M瓶汽水的瓶盖是偶数，本次兑换刚好换完
		return M + Buysoda(M / 2);
	}
	else if (M % 2 == 1 && flag == 0){//M瓶汽水的瓶盖是奇数，且没有多余的瓶盖，留下一个瓶盖，剩下的全部兑换
		flag = 1;//表示本次兑换剩下一个瓶盖，提供下次兑换
		return M + Buysoda(M / 2);
	}
	else if (M % 2 == 1 && flag == 1){//M瓶汽水的瓶盖是奇数，且有多余的瓶盖，加上这个瓶盖一起兑换
		flag = 0;//之前的瓶盖已被用掉
		return M + Buysoda(M / 2 + 1);
	}
}
void MyStrcpy(char str[],char src[]){
	if (src == NULL){
		return -1;
	}
	while ((*str++ = *src++) != '\0'){
		;
	}
}
void MyStrcat(char arr[],char src[]){
	char* ret = arr;
	while (*ret != '\0') {
		ret++;
	}
	while ((*ret++ = *src++) != '\0') {
		;
	}
}
int main(){
	/*int money = 20;
	printf("可以买 %d 瓶汽水\n", Buysoda(money));*/
	/*char src[] = "abcde";
	char arr[6] = { 0 };
	MyStrcpy(arr,src);
	printf("%s\n",arr);*/
	char src[] = "cedf";
	char str[7] = "ab";
	MyStrcat(str, src);
	printf("%s\n", str); 
	return 0;
}

