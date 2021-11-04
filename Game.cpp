#include "Game.h"
void Game::init()
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
Game::Game(const vector<string>& a)
{
	init();
	for (auto i = 0; i < a.size(); i++)
	{
		Players.push_back({ cardlist, usecard, a[i], attack });
	}
}
void Game::start()
{
	int i = 0;
	while (1)
	{
		int xi = i % Players.size();
		Players[xi].info();
		Players[xi].givecard();
		if (Players[xi].iswin())
		{
			cout << Players[xi].getname() << " 승리" << endl;
			break;
		}
		i++;
	//	cout << "카드 개수:" << Players[0].size() + Players[1].size() + Players[2].size() + usecard.size() + cardlist.size();
	}
}