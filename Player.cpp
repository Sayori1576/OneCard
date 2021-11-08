#include "Player.h"
void Player::info()//���� ��� �Լ�
{
	Card uc = usecard[usecard.size() - 1];//�� ī���� �� ���� �ִ� ī��
	cout << "���� " << name << "�� ī�� ������ " << mycard.size() << "���Դϴ�." << endl;//ī�� ���� ���
	cout << uc.name << "�� ī������ �� ���� �ֽ��ϴ�."<<endl;//ī���� �� ���� �ִ� ī�� ���
	cout << "���� ī����:";
	for (int i = 0; i < mycard.size(); i++)
	{
		cout << mycard[i].name << " ";
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
	if ((uc.num == 2|| uc.num == 1||uc.kind=="J") && attack != 0)//���ݹް� �ִٸ�
	{
		a=cardattack(uc);//���ݹ޾��� �� ���� �� �ִ� ī�� ����
	}
	else//�ƴϸ�
	{
		a=nomal(uc);//���� �� �ִ� ī�� ����
	}
	endwork(a);
}
void Player::attackplus(vector<int>& a,int n)//���� ī�带 �´ٸ� �����ϴ� �Լ�
{
		 if (mycard[a[n]].kind == "��" && mycard[a[n]].num == 1)//�����̵� A�� �´ٸ�
	{
	attack += spadeA;//���� ���ݰ��� �����̵� A�� ���ݷ� �߰�
	cout << name << " ��" << mycard[a[n]].name << " ���� ����" << endl;;
	cout << "�Ծ�� �� ī�� "<<spadeA<<"�� ����" << endl;//���� ���
	}
		 else if (mycard[a[n]].kind == "J" && mycard[a[n]].num == 1)//�Ϲ� ��Ŀ�� �´ٸ�
		 {
			 attack += blackj;//�Ϲ� ��Ŀ�� ���ݷ� �߰�
			 cout << name << " ��" << mycard[a[n]].name << " ���� ����" << endl;
			 cout << "�Ծ�� �� ī�� "<<blackj<<"�� ����" << endl;//���� ���
		 }
		 else if (mycard[a[n]].kind == "J" && mycard[a[n]].num == 2)//Į�� ��Ŀ�� �´ٸ�
		 {
			 attack += colorj;//Į�� ��Ŀ�� ���ݷ� �߰�
			 cout << name << " ��" << mycard[a[n]].name << " ���� ����" << endl;;
			 cout << "�Ծ�� �� ī�� "<<colorj<<"�� ����" << endl;//���� ���
		 }
	else if (mycard[a[n]].num == 2)//2�� �´ٸ�
	{
		attack += two;//2�� ���ݷ� �߰�
		cout << name << " ��" << mycard[a[n]].name << " ���� ����" << endl;;
		cout << "�Ծ�� �� ī�� "<<two<<"�� ����" << endl;//���� ���
	}

	else if (mycard[a[n]].num == 1)//A�� �´ٸ�
	{
		attack += aA;//A�� ���ݷ� �߰�
		cout << name << " ��" << mycard[a[n]].name << " ���� ����" << endl;
		cout << "�Ծ�� �� ī�� "<<aA<<"�� ����" << endl;//���� ���
	}
	else if (mycard[a[n]].num == 3)//��� ī�带 �´ٸ�
		 {
			 if (attack != 0)//���� ���� ���̶��
			 {
				 cout << name << " �� ������ ���Ƴ´�!" << endl;//���� ���
				 attack = 0;//���� ���ݰ� 0���� �����
			 }
		 }
	
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
			if(mycard[i].kind == uc.kind || mycard[i].num == uc.num||mycard[i].kind==uc.kind)//������ ���ڰ� ������
			{
			if (uc.num == 1 && uc.kind == "��")//�� ī���� �� ���� �����̵� A�� �ִٸ�
			{
				if ((mycard[i].num == 3 || mycard[i].kind == "J"))//��� ī�峪 ��Ŀ�϶���
				{

					a.push_back(i);//ī�� �߰�

				}
			}
			else if (uc.num == 1 && uc.kind == "J")//��� ��Ŀ�� �´ٸ�
			{
				if ((mycard[i].num == 3) || (mycard[i].kind == "J"&&mycard[i].num==2))//��� ī�峪 Į�� ��Ŀ�϶���
				{

					a.push_back(i);//ī�� �߰�
					

				}
			}
			else if (uc.num == 2 && uc.kind == "J")//Į�� ��Ŀ�� �´ٸ�
			{
				if ((mycard[i].num == 3))//��� ī���϶���
				{

					a.push_back(i);//ī�� �߰�


				}
			}
			else if (uc.num == 1)//A�� �´ٸ�
			{
				if (mycard[i].num == 3 || mycard[i].num == 1 || mycard[i].kind == "J")//���� A�̰ų� ��� ī��ų� ��Ŀ�� ����
				{

					a.push_back(i);//ī�� �߰�

				}
			}
			else if (uc.num == 2)//2�� �´ٸ�
			{
				if ((mycard[i].num == 2 || mycard[i].num == 3 || mycard[i].num == 1 || mycard[i].kind == "J"))//���� 2�̰ų� ��� ī��ų� A�ų� ��Ŀ�� ����
				{

					a.push_back(i);//ī�� �߰�

				}
			}
		}
			
		}// ���� �� �ִ� ī�� ã��
		return a;
}
void Player::endwork(vector<int> &a)//���� �� �ִ� ī�带 ����ϰ� ���� �ϴ� �Լ�
{
	cout << "���� �� �ִ� ī��" << endl;//
	int i;
	for (i = 0; i < a.size(); i++)
	{
		cout << i << "." << mycard[a[i]].name << "  ";
		if (i % 7 == 0&&i!=0)
		{
			cout << endl;
		}
	}//���� �� �ִ� ī��� ���
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
		cout << "���� " << name << "�� ī�� ������ " << mycard.size() << "���Դϴ�." << endl<<endl;//���� ���
		Sleep(2000);//��� ��ٸ���
		clrscr();//ȭ�� �ʱ�ȭ
		
		return;
	}
	cout << "��ȣ �Է�" << endl;
	int n;
	while(1)
	{
	
		cin >> n;//��ȣ �Է¹ޱ�
		if (n < 0 || n >= a.size())//�߸� �Է��ߴٸ�
		{
			cout << "�߸� �Է��ϼ̽��ϴ�" << endl;//�߸� �Է��ߴٰ� ���
		}
		else
		{
			break;
		}
	}
	attackplus(a, n);//�� ī�尡 Ư�� ī���� ��� ó��
	usecard.push_back(mycard[a[n]]);
	mycard.erase(mycard.begin() + a[n]);//ī�带 ����.
	cout << "���� " << name << "�� ī�� ������ " << mycard.size() << "���Դϴ�." << endl<<endl;//���� ���
	Sleep(2000);//��ٸ���
	clrscr();//ȭ�� �ʱ�ȭ
	
	return;

}