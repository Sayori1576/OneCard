#include "Game.h"
void Game::init()//전체 카드패 초기화 함수
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
	randomize();
	//카드패에 카드 하나 올리기
	int a = random(cardlist.size());//랜덤 번호 뽑기
	usecard.push_back(cardlist[a]);//추가하기
	cardlist.erase(cardlist.begin() + a);//삭제하기
//	cout << "카드 개수 " << cardlist.size();
}
Game::Game(const vector<string>& a)//플레이어 이름들을 받는 생성자
{

	init();//카드패 초기화
	for (auto i = 0; i < a.size(); i++)
	{
		Players.push_back({ cardlist, usecard, a[i], attack});
	}//플레이어들 추가
}
void Game::start()//게임을 하는 함수
{
	int i = 0;//1씩 증가하는 값
	while (1)
	{
		int xi = i % Players.size();//현재 플레이어의 번호
		Players[xi].info();//현재 플레이어의 정보 출력
		Players[xi].givecard();//현재 플레이어가 카드를 내게 함
		if (Players[xi].iswin())//이겼다면
		{
			cout << Players[xi].getname() << " 승리" << endl;//이겼다고 출력
			break;
		}
		i++;//1씩 증가
		/*cout << "카드 개수1:" << cardlist.size();
		cout << "카드 개수2:" << Players[0].size() + Players[1].size() + Players[2].size() + usecard.size() + cardlist.size();*/
	}
}