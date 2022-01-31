#include "Game.h"
#include "Menulib.h"
#include "textglinoutput.h"
void honjaseonolgi(); //혼자서 놀기
void duliseonolgi();  //여럿이서 놀기
void init();
std::unique_ptr<Glinoutputbase> inout;
int main()
{
	init();
	inout = std::make_unique<TextGlInOutput>();
	inout->startment();
	Menu Start({{"혼자서 놀기", honjaseonolgi}, {"둘이서 놀기", duliseonolgi}});
	while (1)
	{
		Start.run();

		if (inout->quitment())
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
	int num = inout->inputplayernum();
	std::vector<std::string> name(num); //이름 목록
	for (int i = 0; i < num; i++)
	{
		std::string temp = inout->inputplayername();
		name[i] = temp; //목록에 추가
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