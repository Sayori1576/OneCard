#include "Card.h"
Card::Card(const string& k, int n, tp t, int im, int at)
: kind(k), num(n), type(t), importance(im), attackval(at)//������ �Լ�
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
Card::Card(const string& na, tp t, int im, int at)
:type(t), importance(im), attackval(at)//������ �Լ�
{
	name = na;
	kind=na.substr(0,2);//���� ����
	int temp = na[2] - '0';//�Ϲ����� ��� �׳� ��
	if (na[2] == 'A')
	{
		temp = 1;
	}
	else if (na[2] == 'J')
	{
		temp = 11;
	}
	else if (na[2] == 'Q')
	{
		temp = 12;
	}
	else if (na[2] == 'K')
	{
		temp = 13;
	}
	
	num = temp;//���� ����
}