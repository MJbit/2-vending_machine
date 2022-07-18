
#include<stdio.h>
#include<stdlib.h> //여기에 random함수 있음 (rand)
#include<time.h> // rand 난수값 실행마다 변경하기 위함. srand(time(0)) 선언해서 rand()의 seed값 변경
//#include<string.h> //strcpy함수가 선언된 헤더 파일인데.. 구조체 변수 선언과 동시에 초기화하면 필요 없나..?

struct Beverage { //구조체 연습해보기!
	char name[20];
	int price;
};

int CashCheck(int cash, int price); // 돈 부족한지 확인 //charge값 return

int main()
{
	int cash_input; //cash_input없이 하니까 반복될 때 입력되는 값을 그냥 cash에 덮어서 이전 거래 잔액이 사라졌음. 그래서 cash_input 따로 만듦
	int cash = 0;
	int charge = 0;
	int choice; //선택한 음료의 번호
	int anything_else;
	struct Beverage b[3];
	 b[0] = {"밀크티",800};
	 b[1] = {"핫초코",1000};
	 b[2] = {"말차라떼",1300};
	 srand((unsigned int)time(NULL)); //난수의 시드 초기화  srand(time(0));이거였는데 자꾸c4244경고떠서 바꿈

	printf("환영합니다! \n");
	do
	{
		printf("[메뉴]  ");
		for (int i = 0; i < 3; i++) printf("%s:%d원 ", b[i].name, b[i].price); //아싸!! 간소화 성공!!
		printf("\n자판기에 얼마를 넣으시겠나요? > "); //\n으로 시작하는 거 별로 좋은 선택은 아닌듯..
		scanf_s(" %d", &cash_input);
		cash += cash_input;
		if (0 > cash) { printf("....도둑!! \n"); exit(0); }
		else printf(" %d원 받았습니다. (잔액:%d원) \n\n", cash_input, cash);
		

		//메뉴 보여주고 돈 넣기 (完)

		printf("메뉴를 골라주세요.(선택지 이외의 숫자를 입력하시면 가능한 가격 내에서 랜덤으로 음료가 나옵니다.)\n");
		for (int i = 0; i < 3; i++) printf("%d.%s:%d원 ", i + 1, b[i].name, b[i].price);
		printf("\n입력하신 숫자 \n>"); //1이상 3이하의 자연수가 아닌 유리수 고르는 거 방지하고 싶음(그리고 그건 선택지 이외의 숫자를 입력했음에도 랜덤으로 안 돌아가잖아)
		scanf_s(" %d", &choice);
		if (!((0 < choice) && (choice < 4))) choice = (rand() % 3) + 1; //1,2,3내의 선택지로 다 끌어옴 / rand범위 제대로 돌아가는지 확인!!
		printf("선택하신 음료는 %s(%d원)입니다.\n\n", b[choice - 1].name, b[choice - 1].price); //이걸 원했어!! :D

		// 메뉴 보여주고 음료 선택 (完)

		int chosenprice = b[choice - 1].price;
		charge = CashCheck(cash, chosenprice); // 돈 부족인지 확인 -> 추가로 돈 넣기 or 주문 취소 -> 거스름돈 return
		printf("주문하신 %s가 나왔습니다! (잔액: %d원)\n\n", b[choice - 1].name, charge);
		cash = charge; // 현재 남은 cash가 결국은 charge (거스름돈)이니까 ___ charge 변수 없앨까?

		//주문 출력 (完)

		printf("더 주문하시겠다면 1번을, 더이상 필요하신 게 없으시다면 그 외의 버튼을 눌러주세요 \n");
		scanf_s("%d", &anything_else);
		
	} while (anything_else == 1);

	printf("더 필요하신 게 없으시군요! \n거스름돈은 %d원입니다. 잊지 말고 잘 챙겨가세요! 좋은 하루 보내세요!! :) \n", charge);
	
	return 0;
}

int CashCheck(int cash, int price)  // (完)
{
	int charge;

	if (cash < price)
	{
		int a, addedcash;
		printf("%d원이 부족합니다. 돈을 더 넣으시겠습니까? \n 1.Yes 2.No \n> ", price - cash); //돈 부족
		scanf_s("%d", &a);
		if (a == 1)
		{
			printf("얼마를 넣으시겠나요? > ");
			scanf_s(" %d", &addedcash);
			cash += addedcash;
			printf("추가 이후 잔액: % d원 \n\n", cash);
			CashCheck(cash, price);
		}

		else if (a == 2)
		{
			printf("결제를 취소하겠습니다. 거스름돈: %d원 \n", cash);
			exit(0);
		}
		else
		{
			printf("의도를 알 수 없습니다. 다시 선택해주세요 \n\n");
			CashCheck(cash, price);
		}
	}

	else
		return cash - price; //주문 취소 외에는 돌고 돌아서 다 여기로 옴 > 거스름돈 값 return
}


