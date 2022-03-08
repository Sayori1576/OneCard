#pragma once
#include <climits>
#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <cstdlib>
using std::cout;
using std::cin;
using std::endl;
namespace Menu
{
inline void cinnum()
{

	cin.clear();

	cin.ignore(INT_MAX, '\n');

	cout << "잘못된 값을 입력하셨습니다. 숫자만 입력해주세요.\n";
}

struct menuItem //메뉴 아이템
{
	std::string text;											 //텍스트
	std::function<void(void)> func;								 //고를 때 작동되는 함수
	menuItem(const std::string &t, const std::function<void(void)> &f) //생성자
		: text(t), func(f)
	{
	}
};
class Menu //메뉴
{
public:
	Menu(const std::vector<menuItem> &i) //생성자
		: items(i)
	{
	}
	void run() //작동 함수
	{
		for (std::vector<menuItem>::size_type i = 0; i < items.size(); i++)
		{
			cout << i + 1 << "." << items[i].text << endl;
		}
		while (1)
		{

			int num;
			cin >> num;
			if (num < 0 || static_cast<std::vector<menuItem>::size_type>(num) > items.size())
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
	std::vector<menuItem> items;
};
}