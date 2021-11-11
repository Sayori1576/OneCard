#include "Player.h"
void Player::info()//���� ��� �Լ�
{
	sort(mycard.begin(), mycard.end());//�����ϱ�
	Card uc = usecard[usecard.size() - 1];//�� ī���� �� ���� �ִ� ī��
	cout << "���� " << name << "�� ī�� ������ " << mycard.size() << "���Դϴ�." << endl;//ī�� ���� ���
	cout << uc.name << "�� ī������ �� ���� �ֽ��ϴ�." << endl;//ī���� �� ���� �ִ� ī�� ���
	cout << "���� ī����:";
	for (int i = 0; i < mycard.size(); i++)
	{
		cout << mycard[i].name;
		if (i != mycard.size() - 1 && mycard[i].kind != mycard[i + 1].kind)//������ �ٸ��ٸ�
		{
			cout << "  ";//�� ���
		}
		else//�ƴ϶��
		{
			cout << " ";//����
		}
	}//���� �� ī���п� �ִ� ī��� ���
	cout << endl;
	if (attack != 0)//���ݹް� �ִٸ� ������ �Ծ�� �� ī�� �� ���
	{
		cout << "���� ������ �Ծ�� �� ī�� ���� " << attack << "���Դϴ�." << endl;
	}
}
void Player::selectcard(int num)//ī�� �̴� �Լ�
{
	for (int i = 0; i < num; i++)
	{
		fillcard();//ī���п� ī�尡 ���ٸ� �̾ƿ�
		randomize();//���� ����
		int a = random(cardlist.size());//���� ��ȣ �̱�
		mycard.push_back(cardlist[a]);//�߰��ϱ�
		cardlist.erase(cardlist.begin() + a);//�����ϱ�
	}
}
void Player::givecard()//ī�� ���� �Լ�
{
	Card uc = usecard[usecard.size() - 1];//���� �� ī���� �� ���� �ִ� ī��
	vector<int> a;
	if ((uc.type == ATTACK) && attack != 0)//���ݹް� �ִٸ�
	{
		a = cardattack(uc);//���ݹ޾��� �� ���� �� �ִ� ī�� ����
	}
	else//�ƴϸ�
	{
		a = nomal(uc);//���� �� �ִ� ī�� ����
	}
	endwork(a);//���� ī�带 ����ϰ� �Է� �ޱ�
}
bool Player::attackplus(Card C)//���� ī�带 �´ٸ� �����ϴ� �Լ�
{
	if (C.type == ATTACK)//���� ī�带 �´ٸ�
	{
		attack += C.attackval;//���ݰ� �߰�
		cout << name << " ��" << C.name << " ���� ����" << endl;
		cout << "�Ծ�� �� ī�� " << C.attackval << "�� ����" << endl;//���� ���
	}
	else if (C.type == DEFENSE)//��� ī�带 �´ٸ�
	{
		if (attack != 0)//���� ���� ���̶��
		{
			cout << name << " �� ������ ���Ƴ´�!" << endl;//���� ���
			attack = 0;//���� ���ݰ� 0���� �����
		}
	}
	else if (C.type == ONEMORE)//�ѹ� �� ���� ī�带 �´ٸ�
	{
		Sleep(3000);
		clrscr();//ȭ�� �ʱ�ȭ
		cout << "ī�带 �� �� �� ���ϴ�." << endl;
		info();//���� ���
		givecard();//�ѹ�  �� ����
		return true;
	}
	else if (C.type == CCHANGE)//���� �ٲٱ� ī�带 �´ٸ�
	{
		cout << "ī���� ������ �ٲߴϴ�." << endl;
		cout << "0.�� 1.�� 2.�� 3.��" << endl;//���� ���
		while (1)
		{
			int num;
			cin >> num;//�Է¹ޱ�
			if (num == 0)
			{
				usecard.push_back({ "��0",TEMP,0,0 });
				break;
			}
			else if (num == 1)
			{
				usecard.push_back({ "��0",TEMP,0,0 });
				break;
			}
			else if (num == 2)
			{
				usecard.push_back({ "��0",TEMP,0,0 });
				break;
			}
			else if (num == 3)
			{
				usecard.push_back({ "��0",TEMP,0,0 });
				break;
			}//��쿡 ���� ������ ó��
			else if (!cin)//�߸��� �Է��� �����Ǿ��ٸ�
			{
				cinnum();
			}
			else//�߸��� �Է��� �����Ǿ��ٸ�
			{
				cout << "�߸� �Է��ϼ̽��ϴ�." << endl;

			}
			
		}
		cout << "������ �ٲߴϴ�" << endl;
	}
	return false;
}
vector<int> Player::nomal(Card uc)//�Ϲ����� ��쿡 ���� �� �ִ� ī�带 ���� �Լ�
{
	vector<int> a;//���� �� �ִ� ��ȣ�� ���
	for (int i = 0; i < mycard.size(); i++)
	{
		if (uc.kind == "J")//������ ��Ŀ�� �´ٸ�
		{
			a.push_back(i);//�׳� �߰�
		}
		else if (uc.type == TEMP && mycard[i].kind == uc.kind)//�� ��ī�尡 �ӽ� ī���, ������ ���ٸ�
		{
			a.push_back(i);//�߰�
		}
		else if (mycard[i].kind == uc.kind || mycard[i].num == uc.num || mycard[i].kind == "J")//�ƴ϶�� ���ڳ� ������ ���� ī�常 �߰�
		{
			a.push_back(i);
		}
	}// ���� �� �ִ� ī�� ã��
	return a;
}
vector<int> Player::cardattack(Card uc)//���ݹ޾��� ��� ���� �� �ִ� ī�带 ���� �Լ�
{
	cout << "������ ���� ����" << endl;//���� ���
	vector<int> a;//���� �� �ִ� ��ȣ�� ���
	for (int i = 0; i < mycard.size(); i++)
	{
		if (mycard[i].kind == uc.kind || mycard[i].num == uc.num || mycard[i].kind == uc.kind)//������ ���ڰ� ������
		{
			if (((mycard[i].type == ATTACK||mycard[i].kind == "J") && mycard[i].importance >= uc.importance) || mycard[i].type == DEFENSE)
				//��� ī���̰ų� ���� ī���̸鼭 �߿䵵�� ���ų� ��Ŀ ī���̶��
			{
				a.push_back(i);
			}

		}

	}// ���� �� �ִ� ī�� ã��
	return a;
}
void Player::endwork(vector<int>& a)//���� �� �ִ� ī�带 ����ϰ� ���� �ϴ� �Լ�
{
	if (a.size() == 0)//�� �� �ִ� ī�尡 ���ٸ�
	{
		cout << "�� �� �ִ� ī�尡 �����ϴ�." << endl;//���� ���
		if (attack != 0)//���ݹް� �ִٸ�
		{
			cout << "ī�� " << attack << " ���� �Խ��ϴ�." << endl;
			selectcard(attack);//ī�� �Ա�
			attack = 0;//���ݰ� 0���� �����
		}
		else//�ƴ϶��
		{
			selectcard(1);//�� �� �̱�
		}
		cout << "���� " << name << "�� ī�� ������ " << mycard.size() << "���Դϴ�." << endl << endl;//���� ���
		Sleep(3000);//��� ��ٸ���
		clrscr();//ȭ�� �ʱ�ȭ  

		return;
	}
	cout << "���� �� �ִ� ī��" << endl;//���� ���
	int i;
	for (i = 0; i < a.size(); i++)
	{
		cout << i << "." << mycard[a[i]].name << "  ";
		if (i % 7 == 0 && i != 0)
		{
			cout << endl;
		}
	}//���� �� �ִ� ī��� ���

	cout << "��ȣ �Է�" << endl;
	int n;
	while (1)
	{

		cin >> n;//��ȣ �Է¹ޱ�
		if (!cin)//�߸��� �Է��̶��
		{
			cinnum();//ó��

		}
		else if (n < 0 || n >= a.size())//�߸� �Է��ߴٸ�
		{
			cout << "�߸� �Է��ϼ̽��ϴ�" << endl;//�߸� �Է��ߴٰ� ���
		}
		else
		{
			break;
		}
	}
	if (usecard[usecard.size() - 1].type== TEMP)//�Խ� ī�尡 �� ���� �ִٸ�
	{
		usecard.erase(usecard.begin() + (usecard.size() - 1));//����
	}
	usecard.push_back(mycard[a[n]]);
	mycard.erase(mycard.begin() + a[n]);//ī�带 ����.
	cout << "���� " << name << "�� ī�� ������ " << mycard.size() << "���Դϴ�." << endl;//���� ���
	bool k = !attackplus(usecard[usecard.size() - 1]);//�� ī�尡 Ư�� ī���� ��� ó��
	if (k)//�ѹ� �� ���� ī�带 ���� �ʾҴٸ�   
	{

		Sleep(3000);//��ٸ���
		clrscr();//ȭ�� �ʱ�ȭ
	}

	return;

}