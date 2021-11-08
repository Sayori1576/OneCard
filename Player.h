#include "Default.h"
#include "Card.h"
#pragma once

class Player
{

public:

	Player(vector<Card>& b, vector<Card>& c, const string& n, int& a, int tw = 2, int A = 3, int Sa = 5, int Bj = 5, int Cj = 7)//������
		:cardlist(b), usecard(c), name(n), attack(a), two(tw), aA(A), spadeA(Sa), blackj(Bj), colorj(Cj)//�ʱ�ȭ
	{
	
		selectcard(7);//7�� �̱�
	}
	void info();//���� ��� �Լ�
	void givecard();//ī�� ���� �Լ�
	void selectcard(int num);//ī�� �������� �Լ�
	size_t size()//ũ�� ��ȯ �Լ�
	{
		return mycard.size();
	}
	string getname()//�̸� ��ȯ �Լ�
	{
		return name;
	}
	bool iswin()//�̰�ٸ� 1, ���ٸ� 0 ��ȯ
	{
		if (mycard.size() == 0)//�� �п� ī�尡 ���ٸ�
		{
			return 1;
		}
		else
		{
			return 0;//�ƴ϶��
		}
	}
private:
	vector<Card> mycard;//�� ī�� ��
	vector<Card>& cardlist;//ī�� �� ��
	vector<Card>& usecard;//ī�� �̴� ��
	string name;//�÷��̾� �̸�
	int& attack;//���ݰ� ����
	void attackplus(Card C);//���� ī�带 �´ٸ� �����ϴ� �Լ�
	vector<int> nomal(Card uc);//�Ϲ����� ��쿡 ���� �� �ִ� ī�带 ���� �Լ�
	vector<int> cardattack(Card uc);//���ݹ޾��� ��� ���� �� �ִ� ī�带 ���� �Լ�
	void endwork(vector<int>& a);//���� �� �ִ� ī�带 ����ϰ� ���� �ϴ� �Լ�
	void fillcard()//ī�� �̴� ���� ī�尡 ���ٸ� �� ������ ������
	{
		if (cardlist.size() == 0)//ī�� �̴� ���� ī�尡 ���ٸ�
		{
			cout << "ī������ ������ ī�带 �ٽ� ä��ϴ�." << endl;
			cardlist = usecard;
			usecard.clear();
			usecard.push_back(cardlist[cardlist.size()-1]);
			cardlist.erase(cardlist.end() - 1);//�� ������ ī�� �Űܿ���
			if (cardlist.size() == 0)//�׷��� ���ٸ�
			{
				cout << "ī���п� ī�尡 �����մϴ�";//���� ���
					exit(1);//����
			}
		}
	}
	int two;//2�� ���ݷ�
	int aA;//A�� ���ݷ�
	int spadeA;//�����̵�A�� ���ݷ�
	int blackj;//�����Ŀ�� ���ݷ�
	int colorj;//Į����Ŀ�� ���ݷ�
};
