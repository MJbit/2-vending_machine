#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Beverage {
	char name[20];
	int price;
};

int main(void)
{
	int cash;
	struct Beverage c1;

	int p_milk = 800; int p_choco = 1000; int p_matcha = 1300;
	int choice;

	printf("�������� <1.��ũƼ:%d�� 2.������:%d�� 3.������:%d��> �� �ֽ��ϴ�.\n ���Ǳ⿡ �󸶸� �����ðڳ���? \n",p_milk,p_choco,p_matcha); //ó�� �ݾ� �Է�
	scanf_s("%d", &cash);
	
	if (0 > cash) { printf("�̰� �� ���ϳ��̱���!! \n"); exit(0); }
	
	printf("�޴��� ����ּ��� > 1.��ũƼ:%d�� 2.������:%d�� 3.������:%d��.\n ���Ǳ⿡ �󸶸� �����ðڳ��� ? \n",p_milk,p_choco,p_matcha);
	printf("(�� ������ �̿��� ���� �Է��Ͻø� ������ ���� ������ �������� �帳�ϴ�.) \n"); // ó�� �޴� ����
	printf("���Ͻô� �޴� \n>");
	scanf_s("%d", &choice);

	if (!((0 < choice) && (choice < 4))) choice = (rand() % (3 - 2 + 1) + 1);
	
	int charge = cash -    //�Ž����� (���� �Ϸ� ����)

	switch (c1)
	{
	case 1:


	case 2:

	case 3:
	
	defaulf:
		break;
	}

	return 0;
}
