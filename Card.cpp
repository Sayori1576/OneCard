#include "Card.h"
Card::Card(const string& k, int n) : kind(k), num(n)//������ �Լ�
{
	string temp = to_string(n);//�Ϲ����� ��� ���ڴ� �״�� ǥ��
	switch (n)
	{
	case 1://ī���� ���ڰ� 1�̶�� A�� ǥ��
		temp = 'A';
		break;
	case 11:
		temp = 'J';//ī���� ���ڰ� 11�̶�� J�� ǥ��
		break;
	case 12:
		temp = 'Q';//ī���� ���ڰ� 12��� Q�� ǥ��
		break;
	case 13:
		temp = 'K';//ī���� ���ڰ� 13�̶�� K�� ǥ��
		break;

	}
	name = k + temp;//�̸� ����

}
Card::Card(const string& na)//������ �Լ�
{
	name = na;
	kind = na[0];//���� ����
	int temp = na[1] - '0';//�Ϲ����� ��� �׳� ��
	if (temp == 'A')
	{
		temp = 1;
	}
	else if (temp == 'J')
	{
		temp = 11;
	}
	else if (temp == 'Q')
	{
		temp = 12;
	}
	else if (temp == 'K')
	{
		temp = 13;
	}
	
	num = temp;//���� ����
}