#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Զ�����ˮ�����ʵ�֡�
int Buysoda(int M){
	static int flag = 0;//flag��Ϊһ���жϣ����ڱ��ζһ�֮ǰ�Ķһ����Ƿ��ж����һ��ƿ��
	if (2 * M + flag < 2){//�ж��ܷ�����ˮ
		return 0;
	}
	if (M % 2 == 0){//Mƿ��ˮ��ƿ����ż�������ζһ��պû���
		return M + Buysoda(M / 2);
	}
	else if (M % 2 == 1 && flag == 0){//Mƿ��ˮ��ƿ������������û�ж����ƿ�ǣ�����һ��ƿ�ǣ�ʣ�µ�ȫ���һ�
		flag = 1;//��ʾ���ζһ�ʣ��һ��ƿ�ǣ��ṩ�´ζһ�
		return M + Buysoda(M / 2);
	}
	else if (M % 2 == 1 && flag == 1){//Mƿ��ˮ��ƿ�������������ж����ƿ�ǣ��������ƿ��һ��һ�
		flag = 0;//֮ǰ��ƿ���ѱ��õ�
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
	printf("������ %d ƿ��ˮ\n", Buysoda(money));*/
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

