#pragma once
#include "Player.h"
#include "Card.h"
class Game//���� Ŭ����
{
public:
	Game(const vector<string>& a);//������
	void start();//���� ����
private:
    
	vector<Card> cardlist;//��ü ī����
	vector<Card> usecard;//�� ī����
	int attack;//���ݰ�
	vector<Player> Players;//�÷��̾��
	void init(size_t t);//��ü ī���и� �ʱ�ȭ�ϴ� �Լ�
	bool isjmp;//���� ����
	bool isreverse;//���� ����

};