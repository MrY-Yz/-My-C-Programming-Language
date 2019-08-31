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
	printf("������ϵ��\n");
	if (addr_book->size >= addr_book->capacity){
		addr_book->capacity += 10;
		addr_book->persons = (PersonInfo*)realloc(addr_book->persons, addr_book->capacity);
	}
	printf("����������ϵ��������");
	scanf("%s", (&addr_book->persons[addr_book->size])->name);
	printf("������������ϵ�˵绰��");
	scanf("%s", (&addr_book->persons[addr_book->size])->phone);
	++addr_book->size;
	printf("�����ɹ���\n");
}
void Remove(AddrBook* addr_book){
	assert(addr_book != NULL);
	printf("ɾ��ͨѶ¼��ϵ��\n");
	if (addr_book->size == 0){
		printf("ͨѶ¼Ϊ�գ�\n");
		return;
	}
	printf("������Ҫɾ������ϵ����ţ�");
	int index = 0;
	scanf("%d", &index);
	if (index < 0 || index > addr_book->size){
		printf("������������[0-%d]\n", addr_book->size - 1);
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
	printf("ɾ���ɹ�����ǰ��ʣ%d����¼��\n", addr_book->size);
}
void Update(AddrBook* addr_book){
	assert(addr_book != NULL);
	printf("�޸���ϵ�˼�¼\n");
	if (addr_book->size == 0){
		printf("��ǰͨѶ¼Ϊ�գ������޸ģ�\n");
		return;
	}
	printf("������Ҫ�޸ĵ���ϵ����ţ�");
	int index = 0;
	scanf("%d", &index);
	if (index < 0 || index > addr_book->size){
		printf("������������[0-%d]\n", addr_book->size - 1);
		return;
	}
	PersonInfo* p = &addr_book->persons[index];
	printf("��ǰ����Ϊ��%s\n�������޸�֮���������*��ʾ���ֶβ��޸ģ���", p->name);
	char name[NAME_MAX_SIZE] = { 0 };
	scanf("%s", name);
	if (strcmp(name, "*") != 0){
		strcpy(p->name, name);
	}
	printf("��ǰ�绰Ϊ��%s\n�������޸�֮��ĵ绰��*��ʾ���ֶβ��޸ģ���", p->phone);
	char phone[PHONE_MAX_SIZE] = { 0 };
	scanf("%s", phone);
	if (strcmp(phone, "*") != 0){
		strcpy(p->phone, phone);
	}
	printf("�޸ĳɹ���\n");
}
void PrintAll(AddrBook* addr_book){
	assert(addr_book != NULL);
	printf("------------------\n");
	for (int i = 0; i < addr_book->size; ++i){
		PersonInfo *p = &addr_book->persons[i];
		printf("[%d] %s: %s\n", i, p->name, p->phone);
	}
	printf("��ǰ����%d����¼\n", addr_book->size);
	printf("------------------\n");
}
int Menu(){
	printf("------------------\n");
	printf(" ��ӭʹ��ͨѶ¼\n");
	printf("1.��ʾ������ϵ��\n");
	printf("2.������ϵ��\n");
	printf("3.�޸���ϵ��\n");
	printf("4.ɾ����ϵ��\n");
	printf("0.�˳�ͨѶ¼\n");
	printf("------------------\n");
	printf("����������ѡ��");
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
			printf("���������������������룡\n");
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