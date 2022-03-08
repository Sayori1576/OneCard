#include "Game.h"
namespace Onecard
{
void Game::init(size_t t)
{
	cardlist.push_back({"♠", 1, ATTACK, 3, 5});
	cardlist.push_back({"♥", 1, ATTACK, 2, 3});
	cardlist.push_back({"◆", 1, ATTACK, 2, 3});
	cardlist.push_back({"♣", 1, ATTACK, 2, 3});

	cardlist.push_back({"♠", 2, ATTACK, 1, 2});
	cardlist.push_back({"♥", 2, ATTACK, 1, 2});
	cardlist.push_back({"◆", 2, ATTACK, 1, 2});
	cardlist.push_back({"♣", 2, ATTACK, 1, 2});

	cardlist.push_back({"♠", 3, DEFENSE});
	cardlist.push_back({"♥", 3, DEFENSE});
	cardlist.push_back({"◆", 3, DEFENSE});
	cardlist.push_back({"♣", 3, DEFENSE});
	for (int i = 4; i < 7; i++)
	{
		cardlist.push_back({"♠", i});
	}
	for (int i = 4; i < 7; i++)
	{
		cardlist.push_back({"♥", i});
	}
	for (int i = 4; i < 7; i++)
	{
		cardlist.push_back({"◆", i});
	}
	for (int i = 4; i < 7; i++)
	{
		cardlist.push_back({"♣", i});
	}
	cardlist.push_back({"♠", 7, CCHANGE});
	cardlist.push_back({"♥", 7, CCHANGE});
	cardlist.push_back({"◆", 7, CCHANGE});
	cardlist.push_back({"♣", 7, CCHANGE});
	for (int i = 8; i < 11; i++)
	{
		cardlist.push_back({"♠", i});
	}
	for (int i = 8; i < 11; i++)
	{
		cardlist.push_back({"♥", i});
	}
	for (int i = 8; i < 11; i++)
	{
		cardlist.push_back({"◆", i});
	}
	for (int i = 8; i < 11; i++)
	{
		cardlist.push_back({"♣", i});
	}
	if (t == 2)
	{
		cardlist.push_back({"♠", 11, ONEMORE});
		cardlist.push_back({"♥", 11, ONEMORE});
		cardlist.push_back({"◆", 11, ONEMORE});
		cardlist.push_back({"♣", 11, ONEMORE});
	}
	else
	{
		cardlist.push_back({"♠", 11, JUMP});
		cardlist.push_back({"♥", 11, JUMP});
		cardlist.push_back({"◆", 11, JUMP});
		cardlist.push_back({"♣", 11, JUMP});
	}
	if (t == 2)
	{
		cardlist.push_back({"♠", 12, ONEMORE});
		cardlist.push_back({"♥", 12, ONEMORE});
		cardlist.push_back({"◆", 12, ONEMORE});
		cardlist.push_back({"♣", 12, ONEMORE});
	}
	else
	{
		cardlist.push_back({"♠", 12, REVERSE});
		cardlist.push_back({"♥", 12, REVERSE});
		cardlist.push_back({"◆", 12, REVERSE});
		cardlist.push_back({"♣", 12, REVERSE});
	}
	cardlist.push_back({"♠", 13, ONEMORE});
	cardlist.push_back({"♥", 13, ONEMORE});
	cardlist.push_back({"◆", 13, ONEMORE});
	cardlist.push_back({"♣", 13, ONEMORE});

	cardlist.push_back({"J", 1, ATTACK, 4, 5});
	cardlist.push_back({"J", 2, ATTACK, 5, 7});
	randomize();
	cout << "카드 개수 " << cardlist.size() << endl;
	int a = random(cardlist.size());
	usecard.push_back(cardlist[a]);
	cardlist.erase(cardlist.begin() + a);
}
Game::Game(const std::vector<std::string> &a, std::unique_ptr<GmInoutputbase> &&i) : attack(0), isjmp(0), isreverse(0), inout(std::move(i))
{

	init(a.size());
	for (std::vector<std::string>::size_type i = 0; i < a.size(); i++)
	{
		Players.push_back({cardlist, usecard, a[i], attack, isjmp, isreverse});
	}
}
void Game::start()
{
	int xi = 0;

	while (1)
	{
		cout << "카드 개수1:" << cardlist.size() << endl;
		cout << "카드 개수2:" << usecard.size() + cardlist.size() << endl;
		auto iplus = [&]()
		{	if (isreverse)
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
		} };
		for (size_t i = 0; i < Players.size(); i++)
		{

			Players[i].simpleinfo();
			if (i != Players.size() - 1)
			{
				cout << ", ";
			}
		}
		cout << endl;
		if (isjmp)
		{
			inout->jumpment(Players[xi].getname());
				isjmp = 0;
			iplus();
			Default::Sleep(Default::sleeptime);
			Default::clrscr();
			continue;
		}

		Players[xi].sort();
		Players[xi].info();
		Players[xi].givecard();
		if (Players[xi].iswin())
		{
			inout->winment(Players[xi].getname());
			double temp4 = (Players.size() + winlist.size());
			Players[xi].plusscore(500 * (Players.size() / temp4));
			winlist.push_back({Players[xi].getname(), Players[xi].getscore()});
			Players.erase(Players.begin() + xi);
			std::vector<std::pair<std::string, int>> temp;
			for (auto &x : Players)
			{
				temp.push_back({x.getname(), x.getscore()});
			}
			inout->printranks(winlist,temp);
			if (Players.size() > 1)
			{
				if (inout->isretry())
				{
					Default::clrscr();
					attack=0;
					xi=0;
					//카드 개수가 2일 경우 JQK의 종류를 번경하는 코드, 상태를 없에는 코드가 필요
				}
				else
				{
					break;
				}
			}
			else
			{
				break;
			}
		}
		else
		{
		iplus();
		}
	}
}
void Game::printranks()
{
	
}
}