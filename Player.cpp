#include "Player.h"
void Player::info()
{
	Card uc = usecard[usecard.size() - 1];
	cout << "현재 " << name << "의 카드 개수는 " << mycard.size() << "개입니다." << endl;
	cout << uc.name << "이 카드패의 맨 위에 있습니다."<<endl;
	for (int i = 0; i < mycard.size(); i++)
	{
		cout << mycard[i].name << " ";
	}
	cout << endl;
	if (attack != 0)
	{
		cout << "현재 누적된 먹어야 할 카드 수는 " << attack << "개입니다." << endl;
	}
}
void Player::selectcard(int num)
{
	for (int i = 0; i < num; i++)
	{
		fillcard();
		randomize();
		int a = random(cardlist.size());//랜덤 번호 뽑기
		mycard.push_back(cardlist[a]);//추가하기
		cardlist.erase(cardlist.begin() + a);//삭제하기
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
		 if (mycard[a[n]].kind == "♠" && mycard[a[n]].num == 1)
	{
	attack += 5;
	cout << name << " 은" << mycard[a[n]].name << " 으로 공격" << endl;;
	cout << "먹어야 할 카드 5개 누적" << endl;
	}
		 else if (mycard[a[n]].kind == "J" && mycard[a[n]].num == 1)
		 {
			 attack += 5;
			 cout << name << " 은" << mycard[a[n]].name << " 으로 공격" << endl;
			 cout << "먹어야 할 카드 5개 누적" << endl;
		 }
		 else if (mycard[a[n]].kind == "J" && mycard[a[n]].num == 2)
		 {
			 attack += 7;
			 cout << name << " 은" << mycard[a[n]].name << " 으로 공격" << endl;;
			 cout << "먹어야 할 카드 7개 누적" << endl;
		 }
	else if (mycard[a[n]].num == 2)
	{
		attack += 2;
		cout << name << " 은" << mycard[a[n]].name << " 으로 공격" << endl;;
		cout << "먹어야 할 카드 2개 누적" << endl;
	}

	else if (mycard[a[n]].num == 1)
	{
		attack += 3;
		cout << name << " 은" << mycard[a[n]].name << " 으로 공격" << endl;;
		cout << "먹어야 할 카드 3개 누적" << endl;
	}
	else if (mycard[a[n]].num == 3)
		 {
			 if (attack != 0)
			 {
				 cout << name << " 은 공격을 막아냈다!" << endl;
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
	}// 뽑을 수 있는 카드 찾기
	endwork(a);
}
void Player::cardattack(Card uc)
{
		cout << "상대방의 공격 감지" << endl;
		vector<int> a;
		for (int i = 0; i < mycard.size(); i++)
		{
			if(mycard[i].kind == uc.kind || mycard[i].num == uc.num||mycard[i].kind==uc.kind)
			{
			if (uc.num == 1 && uc.kind == "♠")
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
			
		}// 뽑을 수 있는 카드 찾기
		endwork(a);
}
void Player::endwork(vector<int> &a)
{
	cout << "뽑을 수 있는 카드" << endl;
	int i;
	for (i = 0; i < a.size(); i++)
	{
		cout << i << "." << mycard[a[i]].name << "  ";
		if (i % 7 == 0&&i!=0)
		{
			cout << endl;
		}
	}//뽑을 수 있는 카드들 출력
	if (a.size() == 0)
	{
		cout << "낼 수 있는 카드가 없습니다." << endl;
		if (attack != 0)
		{
			cout << "카드 " << attack << " 장을 먹습니다." << endl;
			selectcard(attack);
			attack = 0;
		}
		else
		{
			selectcard(1);
		}
		cout << "현재 " << name << "의 카드 개수는 " << mycard.size() << "개입니다." << endl<<endl;
		Sleep(2000);
		clrscr();
		
		return;
	}
	cout << "번호 입력" << endl;
	int n;
	while(1)
	{
	
		cin >> n;//번호 입력받기
		if (n < 0 || n >= a.size())
		{
			cout << "잘못 입력하셨습니다" << endl;
		}
		else
		{
			break;
		}
	}
	attackplus(a, n);
	usecard.push_back(mycard[a[n]]);
	mycard.erase(mycard.begin() + a[n]);//추가 후 삭제
	cout << "현재 " << name << "의 카드 개수는 " << mycard.size() << "개입니다." << endl<<endl;
	Sleep(2000);
	clrscr();
	
	return;

}