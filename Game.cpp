#include "Game.h"
void Game::init()//��ü ī���� �ʱ�ȭ �Լ�
{
	cardlist.push_back({ "��",1,ATTACK,3,5 });
	cardlist.push_back({ "��",1,ATTACK,2,3 });
	cardlist.push_back({ "��",1,ATTACK,2,3 });
	cardlist.push_back({ "��",1,ATTACK,2,3 });

	cardlist.push_back({ "��",2,ATTACK,1,2 });
	cardlist.push_back({ "��",2,ATTACK,1,2 });
	cardlist.push_back({ "��",2,ATTACK,1,2 });
	cardlist.push_back({ "��",2,ATTACK,1,2 });

	cardlist.push_back({ "��",3,DEFENSE});
	cardlist.push_back({ "��",3,DEFENSE });
	cardlist.push_back({ "��",3,DEFENSE });
	cardlist.push_back({ "��",3,DEFENSE });
	for (int i = 4; i < 7; i++)
	{
		cardlist.push_back({ "��",i });
	}//ī���п� �����̵� ī�� �߰�
	for (int i = 4; i < 7; i++)
	{
		cardlist.push_back({ "��",i });
	}//ī���п� ��Ʈ ī�� �߰�
	for (int i = 4; i < 7; i++)
	{
		cardlist.push_back({ "��",i });
	}//ī���п� ���̾Ƹ�� ī�� �߰�
	for (int i = 4; i < 7; i++)
	{
		cardlist.push_back({ "��",i });
	}//ī���п� Ŭ�� ī�� �߰�
	cardlist.push_back({ "��",7,CCHANGE });
	cardlist.push_back({ "��",7,CCHANGE });
	cardlist.push_back({ "��",7,CCHANGE });
	cardlist.push_back({ "��",7,CCHANGE });
	for (int i = 8; i < 11; i++)
	{
		cardlist.push_back({ "��",i });
	}//ī���п� �����̵� ī�� �߰�
	for (int i = 8; i < 11; i++)
	{
		cardlist.push_back({ "��",i });
	}//ī���п� ��Ʈ ī�� �߰�
	for (int i = 8; i < 11; i++)
	{
		cardlist.push_back({ "��",i });
	}//ī���п� ���̾Ƹ�� ī�� �߰�
	for (int i = 8; i < 11; i++)
	{
		cardlist.push_back({ "��",i });
	}//ī���п� Ŭ�� ī�� �߰�
	cardlist.push_back({ "��",11,JUMP });
	cardlist.push_back({ "��",11,JUMP });
	cardlist.push_back({ "��",11,JUMP });
	cardlist.push_back({ "��",11,JUMP });

	cardlist.push_back({ "��",12,REVERSE });
	cardlist.push_back({ "��",12,REVERSE });
	cardlist.push_back({ "��",12,REVERSE });
	cardlist.push_back({ "��",12,REVERSE });

	cardlist.push_back({ "��",13,ONEMORE });
	cardlist.push_back({ "��",13,ONEMORE});
	cardlist.push_back({ "��",13,ONEMORE });
	cardlist.push_back({ "��",13,ONEMORE });

	cardlist.push_back({ "J",1,ATTACK,4,5});
	cardlist.push_back({ "J",2,ATTACK,5,7 });//ī���п� ��Ŀ �߰�
	randomize();
	//ī���п� ī�� �ϳ� �ø���
	cout << "ī�� ���� " << cardlist.size();
	int a = random(cardlist.size());//���� ��ȣ �̱�
	usecard.push_back(cardlist[a]);//�߰��ϱ�
	cardlist.erase(cardlist.begin() + a);//�����ϱ�

}
Game::Game(const vector<string>& a)//�÷��̾� �̸����� �޴� ������
{

	init();//ī���� �ʱ�ȭ
	for (auto i = 0; i < a.size(); i++)
	{
		Players.push_back({ cardlist, usecard, a[i], attack});
	}//�÷��̾�� �߰�
}
void Game::start()//������ �ϴ� �Լ�
{
	int i = 0;//1�� �����ϴ� ��
	while (1)
	{
		int xi = i % Players.size();//���� �÷��̾��� ��ȣ
		Players[xi].info();//���� �÷��̾��� ���� ���
		Players[xi].givecard();//���� �÷��̾ ī�带 ���� ��
		if (Players[xi].iswin())//�̰�ٸ�
		{
			cout << Players[xi].getname() << " �¸�" << endl;//�̰�ٰ� ���
			break;
		}
		i++;//1�� ����
		/*cout << "ī�� ����1:" << cardlist.size();
		cout << "ī�� ����2:" << Players[0].size() + Players[1].size() + Players[2].size() + usecard.size() + cardlist.size();*/
	}
}