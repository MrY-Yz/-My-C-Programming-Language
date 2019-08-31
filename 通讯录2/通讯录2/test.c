#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<string.h>

#define NAME_MAX_SIZE 1024
#define PHONE_MAX_SIZE 100

typedef struct PersonInfo{
	char name[NAME_MAX_SIZE];
	char phone[PHONE_MAX_SIZE];
}PersonInfo;

typedef struct AddrBook{
	PersonInfo *persons;
	int size;
	int capacity;
}AddrBook;

void Init(AddrBook* addr_book){
	assert(addr_book != NULL);
	addr_book->size = 0;
	addr_book->capacity = 10;
	addr_book->persons = (PersonInfo*)malloc(sizeof(PersonInfo)*addr_book->capacity);
	for (int i = 0; i < addr_book->capacity; ++i){
		memset(addr_book->persons[i].name, 0, NAME_MAX_SIZE);
		memset(addr_book->persons[i].phone, 0, PHONE_MAX_SIZE);
	}
}
void Add(AddrBook* addr_book){
	assert(addr_book != NULL);
	printf("新增联系人\n");
	if (addr_book->size >= addr_book->capacity){
		addr_book->capacity += 10;
		addr_book->persons = (PersonInfo*)realloc(addr_book->persons, addr_book->capacity);
	}
	printf("请输入新联系人姓名：");
	scanf("%s", (&addr_book->persons[addr_book->size])->name);
	printf("请输入新增联系人电话：");
	scanf("%s", (&addr_book->persons[addr_book->size])->phone);
	++addr_book->size;
	printf("新增成功！\n");
}
void Remove(AddrBook* addr_book){
	assert(addr_book != NULL);
	printf("删除通讯录联系人\n");
	if (addr_book->size == 0){
		printf("通讯录为空！\n");
		return;
	}
	printf("请输入要删除的联系人序号：");
	int index = 0;
	scanf("%d", &index);
	if (index < 0 || index > addr_book->size){
		printf("您的输入有误！[0-%d]\n", addr_book->size - 1);
		return;
	}
	if (index == addr_book->size - 1){
		--addr_book->size;
	}
	else{
		PersonInfo* mid = &addr_book->persons[index];
		PersonInfo* last = &addr_book->persons[addr_book->size - 1];
		strcpy(mid->name, last->name);
		strcpy(mid->phone, last->phone);
		--addr_book->size;
	}
	printf("删除成功，当前还剩%d条记录。\n", addr_book->size);
}
void Update(AddrBook* addr_book){
	assert(addr_book != NULL);
	printf("修改联系人记录\n");
	if (addr_book->size == 0){
		printf("当前通讯录为空，不可修改！\n");
		return;
	}
	printf("请输入要修改的联系人序号：");
	int index = 0;
	scanf("%d", &index);
	if (index < 0 || index > addr_book->size){
		printf("您的输入有误！[0-%d]\n", addr_book->size - 1);
		return;
	}
	PersonInfo* p = &addr_book->persons[index];
	printf("当前姓名为：%s\n请输入修改之后的姓名（*表示该字段不修改）：", p->name);
	char name[NAME_MAX_SIZE] = { 0 };
	scanf("%s", name);
	if (strcmp(name, "*") != 0){
		strcpy(p->name, name);
	}
	printf("当前电话为：%s\n请输入修改之后的电话（*表示该字段不修改）：", p->phone);
	char phone[PHONE_MAX_SIZE] = { 0 };
	scanf("%s", phone);
	if (strcmp(phone, "*") != 0){
		strcpy(p->phone, phone);
	}
	printf("修改成功！\n");
}
void PrintAll(AddrBook* addr_book){
	assert(addr_book != NULL);
	printf("------------------\n");
	for (int i = 0; i < addr_book->size; ++i){
		PersonInfo *p = &addr_book->persons[i];
		printf("[%d] %s: %s\n", i, p->name, p->phone);
	}
	printf("当前共有%d条记录\n", addr_book->size);
	printf("------------------\n");
}
int Menu(){
	printf("------------------\n");
	printf(" 欢迎使用通讯录\n");
	printf("1.显示所有联系人\n");
	printf("2.新增联系人\n");
	printf("3.修改联系人\n");
	printf("4.删除联系人\n");
	printf("0.退出通讯录\n");
	printf("------------------\n");
	printf("请输入您的选择：");
	int choice;
	scanf("%d", &choice);
	return choice;
}
AddrBook addr_book;
typedef void(*Func)(AddrBook*);
int main(){
	Init(&addr_book);
	Func func_table[] = {
		NULL,
		PrintAll,
		Add,
		Update,
		Remove,
	};
	while (1){
		int choice = Menu();
		if (choice<0 || choice>4){
			printf("您的输入有误，请重新输入！\n");
			continue;
		}
		if (choice == 0){
			printf("Goodbye!\n");
			break;
		}
		system("cls");
		func_table[choice](&addr_book);

	}
	return 0;
}