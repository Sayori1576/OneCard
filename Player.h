#include "Default.h"
#include "Card.h"
#pragma once

class Player
{

public:

	Player(vector<Card>& b, vector<Card>& c, const string& n, int& a,bool& ij, bool& ir,bool& o)//������
		:cardlist(b), usecard(c), name(n), attack(a),isjmp(ij),isreverse(ir),one(o)//�ʱ�ȭ
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
	bool& isjmp;//���� ����
	bool& isreverse;//���� ����
	bool attackplus(const Card& C);//���� ī�带 �´ٸ� �����ϴ� �Լ�
	bool& one;
	vector<int> nomal(const Card& uc);//�Ϲ����� ��쿡 ���� �� �ִ� ī�带 ���� �Լ�
	vector<int> cardattack(const Card& uc);//���ݹ޾��� ��� ���� �� �ִ� ī�带 ���� �Լ�
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
	
};
