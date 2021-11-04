#include "Player.h"
void Player::info()
{
	Card uc = usecard[usecard.size() - 1];
	cout << "���� " << name << "�� ī�� ������ " << mycard.size() << "���Դϴ�." << endl;
	cout << uc.name << "�� ī������ �� ���� �ֽ��ϴ�."<<endl;
	for (int i = 0; i < mycard.size(); i++)
	{
		cout << mycard[i].name << " ";
	}
	cout << endl;
	if (attack != 0)
	{
		cout << "���� ������ �Ծ�� �� ī�� ���� " << attack << "���Դϴ�." << endl;
	}
}
void Player::selectcard(int num)
{
	for (int i = 0; i < num; i++)
	{
		fillcard();
		randomize();
		int a = random(cardlist.size());//���� ��ȣ �̱�
		mycard.push_back(cardlist[a]);//�߰��ϱ�
		cardlist.erase(cardlist.begin() + a);//�����ϱ�
	}
}
void Player::givecard()
{
	Card uc = usecard[usecard.size() - 1];
	if ((uc.num == 2|| uc.num == 1||uc.kind=="J") && attack != 0)
	{
		cardattack(uc);
	}
	else
	{
		nomal(uc);
	}
}
void Player::attackplus(vector<int>& a,int n)
{
		 if (mycard[a[n]].kind == "��" && mycard[a[n]].num == 1)
	{
	attack += 5;
	cout << name << " ��" << mycard[a[n]].name << " ���� ����" << endl;;
	cout << "�Ծ�� �� ī�� 5�� ����" << endl;
	}
		 else if (mycard[a[n]].kind == "J" && mycard[a[n]].num == 1)
		 {
			 attack += 5;
			 cout << name << " ��" << mycard[a[n]].name << " ���� ����" << endl;
			 cout << "�Ծ�� �� ī�� 5�� ����" << endl;
		 }
		 else if (mycard[a[n]].kind == "J" && mycard[a[n]].num == 2)
		 {
			 attack += 7;
			 cout << name << " ��" << mycard[a[n]].name << " ���� ����" << endl;;
			 cout << "�Ծ�� �� ī�� 7�� ����" << endl;
		 }
	else if (mycard[a[n]].num == 2)
	{
		attack += 2;
		cout << name << " ��" << mycard[a[n]].name << " ���� ����" << endl;;
		cout << "�Ծ�� �� ī�� 2�� ����" << endl;
	}

	else if (mycard[a[n]].num == 1)
	{
		attack += 3;
		cout << name << " ��" << mycard[a[n]].name << " ���� ����" << endl;;
		cout << "�Ծ�� �� ī�� 3�� ����" << endl;
	}
	else if (mycard[a[n]].num == 3)
		 {
			 if (attack != 0)
			 {
				 cout << name << " �� ������ ���Ƴ´�!" << endl;
				 attack = 0;
			 }
		 }
	
}
void Player::nomal(Card uc)
{
	vector<int> a;
	for (int i = 0; i < mycard.size(); i++)
	{
		if (uc.kind == "J")
		{
			a.push_back(i);
		}
		else if (mycard[i].kind == uc.kind || mycard[i].num == uc.num || mycard[i].kind == "J")
		{
			a.push_back(i);
		}
	}// ���� �� �ִ� ī�� ã��
	endwork(a);
}
void Player::cardattack(Card uc)
{
		cout << "������ ���� ����" << endl;
		vector<int> a;
		for (int i = 0; i < mycard.size(); i++)
		{
			if(mycard[i].kind == uc.kind || mycard[i].num == uc.num||mycard[i].kind==uc.kind)
			{
			if (uc.num == 1 && uc.kind == "��")
			{
				if ((mycard[i].num == 3 || mycard[i].kind == "J"))
				{

					a.push_back(i);

				}
			}
			else if (uc.num == 1 && uc.kind == "J")
			{
				if ((mycard[i].num == 3) || (mycard[i].kind == "J"&&mycard[i].num==2))
				{

					a.push_back(i);
					

				}
			}
			else if (uc.num == 2 && uc.kind == "J")
			{
			
			}
			else if (uc.num == 1)
			{
				if (mycard[i].num == 3 || mycard[i].num == 1 || mycard[i].kind == "J")
				{

					a.push_back(i);

				}
			}
			else if (uc.num == 2)
			{
				if ((mycard[i].num == 2 || mycard[i].num == 3 || mycard[i].num == 1 || mycard[i].kind == "J"))
				{

					a.push_back(i);

				}
			}
		}
			
		}// ���� �� �ִ� ī�� ã��
		endwork(a);
}
void Player::endwork(vector<int> &a)
{
	cout << "���� �� �ִ� ī��" << endl;
	int i;
	for (i = 0; i < a.size(); i++)
	{
		cout << i << "." << mycard[a[i]].name << "  ";
		if (i % 7 == 0&&i!=0)
		{
			cout << endl;
		}
	}//���� �� �ִ� ī��� ���
	if (a.size() == 0)
	{
		cout << "�� �� �ִ� ī�尡 �����ϴ�." << endl;
		if (attack != 0)
		{
			cout << "ī�� " << attack << " ���� �Խ��ϴ�." << endl;
			selectcard(attack);
			attack = 0;
		}
		else
		{
			selectcard(1);
		}
		cout << "���� " << name << "�� ī�� ������ " << mycard.size() << "���Դϴ�." << endl<<endl;
		Sleep(2000);
		clrscr();
		
		return;
	}
	cout << "��ȣ �Է�" << endl;
	int n;
	while(1)
	{
	
		cin >> n;//��ȣ �Է¹ޱ�
		if (n < 0 || n >= a.size())
		{
			cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
		}
		else
		{
			break;
		}
	}
	attackplus(a, n);
	usecard.push_back(mycard[a[n]]);
	mycard.erase(mycard.begin() + a[n]);//�߰� �� ����
	cout << "���� " << name << "�� ī�� ������ " << mycard.size() << "���Դϴ�." << endl<<endl;
	Sleep(2000);
	clrscr();
	
	return;

}