#include "Game.h"

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
Game::Game(const vector<string> &a) : attack(0), isjmp(0), isreverse(0)
{

	init(a.size());
	for (vector<string>::size_type i = 0; i < a.size(); i++)
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
		if (isjmp)
		{
			cout << Players[xi].getname() << " 점프합니다" << endl;
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
			cout << Players[xi].getname() << " 승리" << endl;
			winlist.push_back({Players[xi].getname(), Players[xi].getscore()});
			Players.erase(Players.begin() + xi);
			cout << "등수 목록" << endl;
			for (auto &x : winlist)
			{
				cout << x.first << "    " << x.second << endl;
			}
			vector<pair<string, int>> temp1;
			for (auto &x : Players)
			{
				temp1.push_back({x.getname(), x.getscore()});
			}
			sort(temp1.begin(), temp1.end(), [](auto &x, auto &y)
				 { return x.second > y.second; });
			for (auto &x : temp1)
			{
				cout << x.first << "    " << x.second << endl;
			}
			cout << "점수 목록" << endl;
			vector<pair<string, int>> temp;
			for (auto &x : Players)
			{
				temp.push_back({x.getname(), x.getscore()});
			}
			for (auto &x : winlist)
			{
				temp.push_back(x);
			}
			sort(temp.begin(), temp.end(), [](auto &x, auto &y)
				 { return x.second > y.second; });
			for (auto &x : temp)
			{
				cout << x.first << "    " << x.second << endl;
			}
			Sleep(3000);
			cout << "패자 부활전을 하시겠습니까?" << endl;
			cout << "하고 싶으시다면 r을 누르시오." << endl;
			string temp3;
			cin >> temp3;
			if (temp3 == "r" || temp3 == "R")
			{
			}
			else
			{
				break;
			}
		}
		iplus();
	}
}