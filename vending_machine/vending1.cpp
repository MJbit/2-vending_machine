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

	printf("선택지는 <1.밀크티:%d원 2.핫초코:%d원 3.말차라떼:%d원> 가 있습니다.\n 자판기에 얼마를 넣으시겠나요? \n",p_milk,p_choco,p_matcha); //처음 금액 입력
	scanf_s("%d", &cash);
	
	if (0 > cash) { printf("이거 순 도둑놈이구먼!! \n"); exit(0); }
	
	printf("메뉴를 골라주세요 > 1.밀크티:%d원 2.핫초코:%d원 3.말차라떼:%d월.\n 자판기에 얼마를 넣으시겠나요 ? \n",p_milk,p_choco,p_matcha);
	printf("(위 선택지 이외의 것을 입력하시면 가능한 가격 내에서 랜덤으로 드립니다.) \n"); // 처음 메뉴 선택
	printf("원하시는 메뉴 \n>");
	scanf_s("%d", &choice);

	if (!((0 < choice) && (choice < 4))) choice = (rand() % (3 - 2 + 1) + 1);
	
	int charge = cash -    //거스름돈 (아직 완료 못함)

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
