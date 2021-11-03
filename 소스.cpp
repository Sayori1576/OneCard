#include "Playerh.h"
#include "Card.h"
void chulryeok(string a, int b = 50);//문자열을 받아서 멋있게 출력하는 함수
void honjaseonolgi();//혼자서 놀기
void duliseonolgi();//둘이서 놀기
void fillcard();
void init();
vector<Card> cardlist;//카드패
vector<Card> usecard;
int atack;


int main()
{
	init();

	
	for (;;)
	{
		
		chulryeok("made by jellanie", 100);
		Sleep(500);
		clrscr();

		chulryeok("One Card Game ver 0.1 beta", 250);
	Sleep(500);
		
	np3:

		clrscr();
	
		cout << "1.혼자서 놀기" << endl;
		cout << "2.둘이서 놀기" << endl;//매뉴 출력
		char menu;
		cin >> menu;
		cout << menu << endl;
		switch (menu)
		{
		case '1'://1번을 선택했다면
			cout << "혼자서 놀기는 아직 개발 중입니다" << endl;
			break;
		case '2'://2번을 선택했다면
			cout << "둘이서 놀기를 선택하셨습니다." << endl;
			
			clrscr();
			duliseonolgi();

			break;
		default://아니라면
			cout << "선택은 1 또는 2만 가능합니다." << endl;


			Sleep(500);
			goto np3;
			break;
		}
	   
		clrscr();
	}
}

void chulryeok(string a,int b)
{
	for (auto i = 0; i < a.size(); i++)
	{
		cout << a[i];
		Sleep(b);
	}//문자열을 5초마다 끊어서 한 글자씩 출력
	cout << endl;
}
void honjaseonolgi()
{

}
void duliseonolgi()
{
	Player a(cardlist, usecard, "Player1", atack);
	Player b(cardlist, usecard, "Player2", atack);
	for (;;)
	{
		a.info();
		if (a.size() == 0)
		{
			cout << a.getname() << "승리" << endl;
			break;
		}
		a.givecard();
		if (a.size() == 0)
		{
			cout << a.getname() << "승리" << endl;
			break;
		}
		b.info();
		if (b.size() == 0)
		{
			cout << b.getname() << "승리" << endl;
			break;
		}
		b.givecard();
		if (b.size() == 0)
		{
			cout << b.getname() << "승리" << endl;
			break;
		}
	
	}
}

void init()
{
	for (int i = 1; i < 14; i++)
	{
		cardlist.push_back({ "♠",i });
	}//카드패에 스페이드 카드 추가
	for (int i = 1; i < 14; i++)
	{
		cardlist.push_back({ "♥",i });
	}//카드패에 하트 카드 추가
	for (int i = 1; i < 14; i++)
	{
		cardlist.push_back({ "◆",i });
	}//카드패에 다이아몬드 카드 추가
	for (int i = 1; i < 14; i++)
	{
		cardlist.push_back({ "♣",i });
	}//카드패에 클럽 카드 추가
	cardlist.push_back({ "J",1 });
	cardlist.push_back({ "J",2 });//카드패에 조커 추가
	usecard.push_back({ "♣",3 });
}