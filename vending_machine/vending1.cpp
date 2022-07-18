
#include<stdio.h>
#include<stdlib.h> //���⿡ random�Լ� ���� (rand)
#include<time.h> // rand ������ ���ึ�� �����ϱ� ����. srand(time(0)) �����ؼ� rand()�� seed�� ����
//#include<string.h> //strcpy�Լ��� ����� ��� �����ε�.. ����ü ���� ����� ���ÿ� �ʱ�ȭ�ϸ� �ʿ� ����..?

struct Beverage { //����ü �����غ���!
	char name[20];
	int price;
};

int CashCheck(int cash, int price); // �� �������� Ȯ�� //charge�� return

int main()
{
	int cash_input; //cash_input���� �ϴϱ� �ݺ��� �� �ԷµǴ� ���� �׳� cash�� ��� ���� �ŷ� �ܾ��� �������. �׷��� cash_input ���� ����
	int cash = 0;
	int charge = 0;
	int choice; //������ ������ ��ȣ
	int anything_else;
	struct Beverage b[3];
	 b[0] = {"��ũƼ",800};
	 b[1] = {"������",1000};
	 b[2] = {"������",1300};
	 srand((unsigned int)time(NULL)); //������ �õ� �ʱ�ȭ  srand(time(0));�̰ſ��µ� �ڲ�c4244����� �ٲ�

	printf("ȯ���մϴ�! \n");
	do
	{
		printf("[�޴�]  ");
		for (int i = 0; i < 3; i++) printf("%s:%d�� ", b[i].name, b[i].price); //�ƽ�!! ����ȭ ����!!
		printf("\n���Ǳ⿡ �󸶸� �����ðڳ���? > "); //\n���� �����ϴ� �� ���� ���� ������ �ƴѵ�..
		scanf_s(" %d", &cash_input);
		cash += cash_input;
		if (0 > cash) { printf("....����!! \n"); exit(0); }
		else printf(" %d�� �޾ҽ��ϴ�. (�ܾ�:%d��) \n\n", cash_input, cash);
		

		//�޴� �����ְ� �� �ֱ� (��)

		printf("�޴��� ����ּ���.(������ �̿��� ���ڸ� �Է��Ͻø� ������ ���� ������ �������� ���ᰡ ���ɴϴ�.)\n");
		for (int i = 0; i < 3; i++) printf("%d.%s:%d�� ", i + 1, b[i].name, b[i].price);
		printf("\n�Է��Ͻ� ���� \n>"); //1�̻� 3������ �ڿ����� �ƴ� ������ ���� �� �����ϰ� ����(�׸��� �װ� ������ �̿��� ���ڸ� �Է��������� �������� �� ���ư��ݾ�)
		scanf_s(" %d", &choice);
		if (!((0 < choice) && (choice < 4))) choice = (rand() % 3) + 1; //1,2,3���� �������� �� ����� / rand���� ����� ���ư����� Ȯ��!!
		printf("�����Ͻ� ����� %s(%d��)�Դϴ�.\n\n", b[choice - 1].name, b[choice - 1].price); //�̰� ���߾�!! :D

		// �޴� �����ְ� ���� ���� (��)

		int chosenprice = b[choice - 1].price;
		charge = CashCheck(cash, chosenprice); // �� �������� Ȯ�� -> �߰��� �� �ֱ� or �ֹ� ��� -> �Ž����� return
		printf("�ֹ��Ͻ� %s�� ���Խ��ϴ�! (�ܾ�: %d��)\n\n", b[choice - 1].name, charge);
		cash = charge; // ���� ���� cash�� �ᱹ�� charge (�Ž�����)�̴ϱ� ___ charge ���� ���ٱ�?

		//�ֹ� ��� (��)

		printf("�� �ֹ��Ͻðڴٸ� 1����, ���̻� �ʿ��Ͻ� �� �����ôٸ� �� ���� ��ư�� �����ּ��� \n");
		scanf_s("%d", &anything_else);
		
	} while (anything_else == 1);

	printf("�� �ʿ��Ͻ� �� �����ñ���! \n�Ž������� %d���Դϴ�. ���� ���� �� ì�ܰ�����! ���� �Ϸ� ��������!! :) \n", charge);
	
	return 0;
}

int CashCheck(int cash, int price)  // (��)
{
	int charge;

	if (cash < price)
	{
		int a, addedcash;
		printf("%d���� �����մϴ�. ���� �� �����ðڽ��ϱ�? \n 1.Yes 2.No \n> ", price - cash); //�� ����
		scanf_s("%d", &a);
		if (a == 1)
		{
			printf("�󸶸� �����ðڳ���? > ");
			scanf_s(" %d", &addedcash);
			cash += addedcash;
			printf("�߰� ���� �ܾ�: % d�� \n\n", cash);
			CashCheck(cash, price);
		}

		else if (a == 2)
		{
			printf("������ ����ϰڽ��ϴ�. �Ž�����: %d�� \n", cash);
			exit(0);
		}
		else
		{
			printf("�ǵ��� �� �� �����ϴ�. �ٽ� �������ּ��� \n\n");
			CashCheck(cash, price);
		}
	}

	else
		return cash - price; //�ֹ� ��� �ܿ��� ���� ���Ƽ� �� ����� �� > �Ž����� �� return
}


