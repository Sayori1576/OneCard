#pragma once
#include "Default.h"

enum tp{NOMAL,ATTACK,JUMP,REVERSE};
struct Card //ī�� ����ü
{
	Card(const string& k, int num, tp t = NOMAL,int im=0, int at=0);//����, ���ڸ� �޾� �ʱ�ȭ�ϴ� ������
	Card(const string& na, tp t = NOMAL, int im = 0, int at = 0);//ī�� �̸��� �޾� �ʱ�ȭ�ϴ� ������
	string kind;//����
	int num;//����
	int type;
	string name;//ī���� �̸�
	int importance;
	int attackval;
};