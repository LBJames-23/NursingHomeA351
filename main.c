#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define H 7

struct customer {
	int num;//ס�����
	int age;//ס������
	char gender;//M for male,F for famale
	int house;//��ס���ݱ��
	struct customer* next;
};
typedef struct customer client;//�ͻ��ṹ��
struct workers {
	int num;//Ա������
	char area;//��������
	int serviceNum;//������������
	struct workers* next;
};
typedef struct workers staff;//Ա���ṹ��

struct department {
	int number;//���ݱ��
	int situation;//��ס״̬
	int capacity;//����ס����
}dp[H] = { {1,0,2},{1,0,2},{1,0,2},{1,0,2},{1,0,1},{1,0,1},{1,0,1} };//��Ԣ�ṹ��

struct VIP {
	int ID;//��Ա���
	int age;//����
	int houseNum;//����ס���ݱ��
	struct VIP* next;
};
typedef struct VIP vip;//��Ա�ṹ��

void house_init(void);
void mainMenu(void);
void menuSelect(void);
int search(void);
client* create(int);
client* clientOrder(client*,client*);

int main(void)
{
	house_init();
	menuSelect();//ϵͳ����ѡ��
	return 0;
}

void house_init(void) {
	dp[0].number = 1; dp[0].situation = 0; dp[0].capacity = 2;
	dp[1].number = 2; dp[1].situation = 0; dp[1].capacity = 2;
	dp[2].number = 3; dp[2].situation = 0; dp[2].capacity = 2;
	dp[3].number = 4; dp[3].situation = 0; dp[3].capacity = 2;
	dp[4].number = 5; dp[4].situation = 0; dp[4].capacity = 1;
	dp[5].number = 6; dp[5].situation = 0; dp[5].capacity = 1;
	dp[6].number = 7; dp[6].situation = 0; dp[6].capacity = 1;
}//��Ԣ���ݳ�ʼ��
void mainMenu() {
	printf("********************************\n");
	printf("Elderly community service system\n");
	printf("********************************\n");
	printf("1.Client management\n2.Department management\n3.VIP management\n4.Staff management\n5.Exit\n");
	printf("Please choose the function:");
}
void menuSelect(void) {
	client* head;
	head = NULL;
	int choose,result;
	int i = 1;
	system("cls");
	do {
		mainMenu();
		scanf("%d", &choose);
		switch (choose) {
		case 1:
			result = search();
			if (result == 1)
				printf("This person can check in room %d.\n", result);
			else
				break;
			head = clientOrder(head, create(result));
			break;//�ͻ�����ģ��
		}
	} while (i);
}//ϵͳ����ѡ��
int search(void) {
	int customNum;
	customNum = 0;
	int i;
	int MaxCapacity = 5;
	printf("Please enter the number of the client:\n");
	scanf("%d", &customNum);
	if (MaxCapacity < customNum) {
		printf("Sorry,there is no room for %d people!\n", customNum);
		return -1;
	}
	while (customNum <= MaxCapacity) {
		for (i = 0; i < H; i++) {
			if (dp[i].situation == 0)
				return (dp[i].number);
		}
		printf("Sorry,no room avilable now.");
	}
	return -1;
}//������Ԣ
client* create(int result) {
	client* p;
	p = (client*)malloc(sizeof(client));
	int i, num, age, house;
	char gender;
	if (result != -1) {
		p->house = result;
		dp[result - 1].situation = 1;
		printf("Please input the client's number,age and gender(M for male/F for famale).\n");
		scanf("%d%d%c", &num, &age, gender);
		p->num = num;
		p->age = age;
		p->gender = gender;
	}
	putchar('\n');
	p->next = NULL;
	return p;
}
client* clientOrder(client* head, client* p) {
	client* pnew;
	pnew = head;
	if (head != NULL) {
		if (p != NULL) {
			while (pnew->next != NULL)
				pnew = pnew->next;
			pnew->next = p;
			printf("Check in!\n");
		}
		else
			printf("Error!");
	}
	else {
		if (p != NULL)
			head = p;
	}
	return head;
}
