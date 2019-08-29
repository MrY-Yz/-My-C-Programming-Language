#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main(){
	int i = 0;
	int k = 0;
	for (i = 1; i <= 100; i++){
		if (i % 10 == 9 ){
			k++;
		}
		if (i / 10 == 9){
			k++;
		}
	}
	printf("%d\n", k);
	return 0;
}