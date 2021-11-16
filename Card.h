#pragma once
#include "Default.h"

enum tp{NOMAL,ATTACK,JUMP,REVERSE,DEFENSE,CCHANGE,ONEMORE,TEMP,CANCEL};//���� ������
struct Card //ī�� ����ü
{
	Card(const string& k, int num, tp t = NOMAL,int im=0, int at=0);//����, ���ڸ� �޾� �ʱ�ȭ�ϴ� ������
	Card(const string& na, tp t = NOMAL, int im = 0, int at = 0);//ī�� �̸��� �޾� �ʱ�ȭ�ϴ� ������
	string kind;//���� ����
	int num;//����
	tp type;//ī�� ����
	string name;//ī���� �̸�
	int importance;//�߿䵵(�������� ����)
	int attackval;//���ݰ�
	bool operator<(const Card& rhs)//�� ������
	{
		if (kind != rhs.kind)
		{
			return kind < rhs.kind;
		}
		else
		{
			return num < rhs.num;
		}
	}
};