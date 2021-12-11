#pragma once
#include <iostream>
#include <vector>
#include <functional>
#include <string>
using namespace std;
struct menuItem //메뉴 아이템
{
	string text;											 //텍스트
	function<void(void)> func;								 //고를 때 작동되는 함수
	menuItem(const string &t, const function<void(void)> &f) //생성자
		: text(t), func(f)
	{
	}
};
class Menu //메뉴
{
public:
	Menu(const vector<menuItem> &i) //생성자
		: items(i)
	{
	}
	void run() //작동 함수
	{
		for (vector<menuItem>::size_type i = 0; i < items.size(); i++)
		{
			cout << i + 1 << "." << items[i].text << endl;
		}
		while (1)
		{

			int num;
			cin >> num;
			if (num < 0 || static_cast<vector<menuItem>::size_type>(num) > items.size())
			{
				cout << "잘못 입력하셨습니다." << endl;
			}
			else if (!cin)
			{
				cinnum();
			}
			else
			{
				items[num - 1].func();
				break;
			}
		}
	}

private:
	vector<menuItem> items;
};