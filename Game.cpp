#include "Game.h"

void Game::init()
{
	cardlist.push_back({ "♠", 1, ATTACK, 3, 5 });
	cardlist.push_back({ "♥", 1, ATTACK, 2, 3 });
	cardlist.push_back({ "◆", 1, ATTACK, 2, 3 });
	cardlist.push_back({ "♣", 1, ATTACK, 2, 3 });

	cardlist.push_back({ "♠", 2, ATTACK, 1, 2 });
	cardlist.push_back({ "♥", 2, ATTACK, 1, 2 });
	cardlist.push_back({ "◆", 2, ATTACK, 1, 2 });
	cardlist.push_back({ "♣", 2, ATTACK, 1, 2 });

	cardlist.push_back({ "♠", 3, DEFENSE });
	cardlist.push_back({ "♥", 3, DEFENSE });
	cardlist.push_back({ "◆", 3, DEFENSE });
	cardlist.push_back({ "♣", 3, DEFENSE });
	for (int i = 4; i < 7; i++)
	{
		cardlist.push_back({ "♠", i });
	}
	for (int i = 4; i < 7; i++)
	{
		cardlist.push_back({ "♥", i });
	}
	for (int i = 4; i < 7; i++)
	{
		cardlist.push_back({ "◆", i });
	}
	for (int i = 4; i < 7; i++)
	{
		cardlist.push_back({ "♣", i });
	}
	cardlist.push_back({ "♠", 7, CCHANGE });
	cardlist.push_back({ "♥", 7, CCHANGE });
	cardlist.push_back({ "◆", 7, CCHANGE });
	cardlist.push_back({ "♣", 7, CCHANGE });
	for (int i = 8; i < 11; i++)
	{
		cardlist.push_back({ "♠", i });
	}
	for (int i = 8; i < 11; i++)
	{
		cardlist.push_back({ "♥", i });
	}
	for (int i = 8; i < 11; i++)
	{
		cardlist.push_back({ "◆", i });
	}
	for (int i = 8; i < 11; i++)
	{
		cardlist.push_back({ "♣", i });
	}
	cardlist.push_back({ "♠", 11, JUMP });
	cardlist.push_back({ "♥", 11, JUMP });
	cardlist.push_back({ "◆", 11, JUMP });
	cardlist.push_back({ "♣", 11, JUMP });

	cardlist.push_back({ "♠", 12, REVERSE });
	cardlist.push_back({ "♥", 12, REVERSE });
	cardlist.push_back({ "◆", 12, REVERSE });
	cardlist.push_back({ "♣", 12, REVERSE });

	cardlist.push_back({ "♠", 13, ONEMORE });
	cardlist.push_back({ "♥", 13, ONEMORE });
	cardlist.push_back({ "◆", 13, ONEMORE });
	cardlist.push_back({ "♣", 13, ONEMORE });

	cardlist.push_back({ "J", 1, ATTACK, 4, 5 });
	cardlist.push_back({ "J", 2, ATTACK, 5, 7 });
	randomize();
	cout << "카드 개수 " << cardlist.size() << endl;
	int a = random(cardlist.size());
	usecard.push_back(cardlist[a]);
	cardlist.erase(cardlist.begin() + a);
}
Game::Game(const vector<string>& a)
{

	init();
	for (auto i = 0; i < a.size(); i++)
	{
		Players.push_back({ cardlist, usecard, a[i], attack,isjmp,isreverse});
	}
}
void Game::start()
{
	int i = 0;
	while (1)
	{
		if (isjmp)
		{
			cout << "점프합니다" << endl;
			isjmp = 0;
			i++;
			Sleep(3000);
			clrscr();
			continue;
		}
		int xi;
		if (isreverse)
		{
			int s = static_cast<int>(Players.size());
			xi = abs(((i % s)-(s+1)));
		}
		else
		{
			 xi= i % Players.size();
		}
		Players[xi].info();
		Players[xi].givecard();
		if (Players[xi].iswin())
		{
			cout << Players[xi].getname() << " 승리" << endl;
			Sleep(3000);
			break;
		}
		i++;
		cout << "카드 개수1:" << cardlist.size() << endl;
		cout << "카드 개수2:" << usecard.size() + cardlist.size() << endl;
	}
}