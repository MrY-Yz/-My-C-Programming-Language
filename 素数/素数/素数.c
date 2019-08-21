#include<stdio.h>
int main(){
	int a = 1000;
	for (; a <= 2000; a++){
		if (a % 4 == 0 && a % 100 != 0){
			printf("%d\n", a);
		}
		else if (a % 400 == 0){
			printf("%d\n", a);
		}
	}
	return 0;
}

