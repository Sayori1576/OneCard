#include "Game.h"
void Game::init()//��ü ī���� �ʱ�ȭ �Լ�
{
	for (int i = 1; i < 14; i++)
	{
		cardlist.push_back({ "��",i });
	}//ī���п� �����̵� ī�� �߰�
	for (int i = 1; i < 14; i++)
	{
		cardlist.push_back({ "��",i });
	}//ī���п� ��Ʈ ī�� �߰�
	for (int i = 1; i < 14; i++)
	{
		cardlist.push_back({ "��",i });
	}//ī���п� ���̾Ƹ�� ī�� �߰�
	for (int i = 1; i < 14; i++)
	{
		cardlist.push_back({ "��",i });
	}//ī���п� Ŭ�� ī�� �߰�
	cardlist.push_back({ "J",1 });
	cardlist.push_back({ "J",2 });//ī���п� ��Ŀ �߰�
	randomize();
	//ī���п� ī�� �ϳ� �ø���
	int a = random(cardlist.size());//���� ��ȣ �̱�
	usecard.push_back(cardlist[a]);//�߰��ϱ�
	cardlist.erase(cardlist.begin() + a);//�����ϱ�
//	cout << "ī�� ���� " << cardlist.size();
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