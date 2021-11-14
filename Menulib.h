#pragma once
#include <iostream>
#include <vector>
#include <functional>
#include <string>
using namespace std;
struct menuItem//�޴� ������
{
	string text;//�ؽ�Ʈ
	function<void(void)> func;//�� �� �۵��Ǵ� �Լ�
	menuItem(const string& t, const function<void(void)>& f)//������
		:text(t),func(f)
	{

	}
};
class Menu//�޴�
{
public:
	Menu(const vector<menuItem>& i)//������
		:items(i)
	{
		
	}
	void run()//�۵� �Լ�
	{
		for (int i = 0; i < items.size(); i++)
		{
			cout << i+1 << "." << items[i].text << endl;
		}
		while (1)
		{
			
			int num;
			cin >> num;
			if (num < 0 || num > items.size())
			{
				cout << "�߸� �Է��ϼ̽��ϴ�." << endl;

			}
			else if (!cin)
			{
				cinnum();
			}
			else
			{
				items[num-1].func();
				break;
			}
		}
	}
private:
		vector<menuItem> items;


};