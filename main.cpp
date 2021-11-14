#include "Player.h"
#include "Card.h"
#include "Game.h"
#include "Menulib.h"
void chulryeok(string a, int b = 50);//문자열을 받아서 멋있게 출력하는 함수
void honjaseonolgi();//혼자서 놀기
void duliseonolgi();//여럿이서 놀기
void init();
vector<Card> cardlist;//카드패
vector<Card> usecard;
int attack;


int main()
{
	init();

	
	
		
	cout << "Made by Sayori1576"<<endl;


	cout << "Onecard Game"<<endl;
	Menu Start( {{ "혼자서 놀기", honjaseonolgi }, {"둘이서 놀기",duliseonolgi} });
	Start.run();
	   
		clrscr();
	
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
	clrscr();
	cout << "개발 중입니다" << endl;
}
void duliseonolgi()//여럿이서 놀기 함수
{
	clrscr();
	cout << "몇 명이서 할 건가요?" << endl;
	int num;//플레이어 수
	while (1)
	{

		cin >> num;//입력 받기
		if (!cin)
		{
			cinnum();

		}
		else if ((num >=7)||(num<=1))
		{
			cout << "7명 이상은 이 게임을 할 수 없어요." << endl;
		}
		else
		{
			break;
		}
	}
	vector<string> name(num);//이름 목록
	for (int i = 0; i < num; i++)
	{
		cout << "이름을 입력해 주세요" << endl;
		string temp;//이름
		cin >> temp;//입력 받기
		name[i] = temp;//목록에 추가
	}
	clrscr();
	Game newgame(name);//새로운 게임 생성
		newgame.start();//게임 시작
	/*Player a(cardlist, usecard, "Player1", attack);
	Player b(cardlist, usecard, "Player2", attack);
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
	
	}*/
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