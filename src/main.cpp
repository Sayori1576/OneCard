#include "Player.h"
#include "Card.h"
#include "Game.h"
#include "Menulib.h"
void honjaseonolgi(); //혼자서 놀기
void duliseonolgi();  //여럿이서 놀기
void init();

int main()
{
	init();

	cout << "Made by Sayori1576" << endl;

	cout << "Onecard Game" << endl;
	Menu Start({{"혼자서 놀기", honjaseonolgi}, {"둘이서 놀기", duliseonolgi}});
	while (1)
	{
		Start.run();
		cout << "게임을 끝내고 싶으시다면 Q를 누르시오. 아니라면 아무 키나 누르시오." << endl;
		std::string temp;
		cin >> temp;
		if (temp == "q" || temp == "Q")
		{
			cout << "게임을 나갑니다." << endl;
			Sleep(sleeptime);
			break;
		}
		clrscr();
	}
	clrscr();
}

void honjaseonolgi()
{
	clrscr();
	cout << "개발 중입니다" << endl;
}
void duliseonolgi() //여럿이서 놀기 함수
{
	clrscr();
	cout << "몇 명이서 할 건가요?" << endl;
	int num; //플레이어 수
	while (1)
	{

		cin >> num; //입력 받기
		if (!cin)
		{
			cinnum();
		}
		else if ((num >= 7) || (num <= 1))
		{
			cout << "7명 이상은 이 게임을 할 수 없어요." << endl;
		}
		else
		{
			break;
		}
	}
	std::vector<std::string> name(num); //이름 목록
	for (int i = 0; i < num; i++)
	{
		cout << "이름을 입력해 주세요" << endl;
		std::string temp; //이름
		cin >> temp;	  //입력 받기
		name[i] = temp;	  //목록에 추가
	}
	clrscr();
	Game newgame(name); //새로운 게임 생성
	newgame.start();	//게임 시작
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
}