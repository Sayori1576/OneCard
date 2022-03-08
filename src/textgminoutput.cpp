#include "textgminoutput.h"
namespace Onecard
{
void TextGmInoutput::jumpment(std::string_view plname)
{
    cout << plname << " 점프합니다" << endl;
}
void TextGmInoutput::winment(std::string_view plname)
{
cout << plname<< " 승리" << endl;
}
bool TextGmInoutput::isretry()
{
                cout << "패자 부활전을 하시겠습니까?" << endl;
				cout << "하고 싶으시다면 r을 누르시오." << endl;
				std::string temp3;
				cin >> temp3;
				if (temp3 == "r" || temp3 == "R")
				{
					return 1;   
				}
				else
				{
					return 0;
				}
}
void TextGmInoutput::printranks(const std::vector<std::pair<std::string, int>>& winlist,std::vector<std::pair<std::string, int>>&players)
{
	cout << "등수 목록" << endl;
	int i = 1;
	for (auto &x : winlist)
	{

		cout << i << ". " << x.first << endl;
		i++;
	}
	std::vector<std::pair<std::string, int>> temp;
	for (auto &x : players)
	{
		temp.push_back(x);
	}
	std::sort(temp.begin(), temp.end(), [](auto &x, auto &y)
			  { return x.second > y.second; });

	for (auto &x : temp)
	{

		cout << i << ". " << x.first << endl;
		i++;
	}
	cout << "점수 목록" << endl;
	for (auto &x : winlist)
	{
		temp.push_back(x);
	}
	std::sort(temp.begin(), temp.end(), [](auto &x, auto &y)
			  { return x.second > y.second; });
	i = 1;
	for (auto &x : temp)
	{

		cout << i << ". " << x.first << "    " << x.second << endl;
		i++;
	}
}
}