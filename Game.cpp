#include "Game.h"

void Game::init(size_t t)
{
	cardlist.push_back({ "��", 1, ATTACK, 3, 5 });
	cardlist.push_back({ "��", 1, ATTACK, 2, 3 });
	cardlist.push_back({ "��", 1, ATTACK, 2, 3 });
	cardlist.push_back({ "��", 1, ATTACK, 2, 3 });

	cardlist.push_back({ "��", 2, ATTACK, 1, 2 });
	cardlist.push_back({ "��", 2, ATTACK, 1, 2 });
	cardlist.push_back({ "��", 2, ATTACK, 1, 2 });
	cardlist.push_back({ "��", 2, ATTACK, 1, 2 });

	cardlist.push_back({ "��", 3, DEFENSE });
	cardlist.push_back({ "��", 3, DEFENSE });
	cardlist.push_back({ "��", 3, DEFENSE });
	cardlist.push_back({ "��", 3, DEFENSE });
	for (int i = 4; i < 7; i++)
	{
		cardlist.push_back({ "��", i });
	}
	for (int i = 4; i < 7; i++)
	{
		cardlist.push_back({ "��", i });
	}
	for (int i = 4; i < 7; i++)
	{
		cardlist.push_back({ "��", i });
	}
	for (int i = 4; i < 7; i++)
	{
		cardlist.push_back({ "��", i });
	}
	cardlist.push_back({ "��", 7, CCHANGE });
	cardlist.push_back({ "��", 7, CCHANGE });
	cardlist.push_back({ "��", 7, CCHANGE });
	cardlist.push_back({ "��", 7, CCHANGE });
	for (int i = 8; i < 11; i++)
	{
		cardlist.push_back({ "��", i });
	}
	for (int i = 8; i < 11; i++)
	{
		cardlist.push_back({ "��", i });
	}
	for (int i = 8; i < 11; i++)
	{
		cardlist.push_back({ "��", i });
	}
	for (int i = 8; i < 11; i++)
	{
		cardlist.push_back({ "��", i });
	}
	if (t == 2)
	{
		cardlist.push_back({ "��", 11, ONEMORE });
		cardlist.push_back({ "��", 11, ONEMORE});
		cardlist.push_back({ "��", 11, ONEMORE });
		cardlist.push_back({ "��", 11, ONEMORE });
	}
	else
	{
		cardlist.push_back({ "��", 11, JUMP });
		cardlist.push_back({ "��", 11, JUMP });
		cardlist.push_back({ "��", 11, JUMP });
		cardlist.push_back({ "��", 11, JUMP });
	}
	if (t == 2)
	{
		cardlist.push_back({ "��", 12, ONEMORE });
		cardlist.push_back({ "��", 12, ONEMORE });
		cardlist.push_back({ "��", 12, ONEMORE });
		cardlist.push_back({ "��", 12, ONEMORE });
	}
	else
	{
		cardlist.push_back({ "��", 12, REVERSE });
		cardlist.push_back({ "��", 12, REVERSE });
		cardlist.push_back({ "��", 12, REVERSE });
		cardlist.push_back({ "��", 12, REVERSE });
	}
	cardlist.push_back({ "��", 13, ONEMORE });
	cardlist.push_back({ "��", 13, ONEMORE });
	cardlist.push_back({ "��", 13, ONEMORE });
	cardlist.push_back({ "��", 13, ONEMORE });

	cardlist.push_back({ "J", 1, ATTACK, 4, 5 });
	cardlist.push_back({ "J", 2, ATTACK, 5, 7 });
	randomize();
	cout << "ī�� ���� " << cardlist.size() << endl;
	int a = random(cardlist.size());
	usecard.push_back(cardlist[a]);
	cardlist.erase(cardlist.begin() + a);
}
Game::Game(const vector<string>& a)
{

	init(a.size());
	for (auto i = 0; i < a.size(); i++)
	{
		Players.push_back({ cardlist, usecard, a[i], attack,isjmp,isreverse});
	}

}
void Game::start()
{
	int xi = 0;
	
	while (1)
	{
		cout << "ī�� ����1:" << cardlist.size() << endl;
		cout << "ī�� ����2:" << usecard.size() + cardlist.size() << endl;
		auto iplus = [&]() {	if (isreverse)
		{
			if (xi == 0)
			{
				xi = static_cast<int>(Players.size()) - 1;
			}
			else
			{
				xi--;
			}
		}
		else
		{
			if (xi == static_cast<int>(Players.size()) - 1)
			{
				xi = 0;
			}
			else
			{
				xi++;
			}
		}};
		if (isjmp)
		{
			cout<<Players[xi].getname() << " �����մϴ�" << endl;
			isjmp = 0;
			iplus();
			Sleep(3000);
			clrscr();
			continue;
		}
  		Players[xi].info();
		Players[xi].givecard();
		if (Players[xi].iswin())
		{
			cout << Players[xi].getname() << " �¸�" << endl;
			Sleep(3000);
			break;
		}
		iplus();

	}
}