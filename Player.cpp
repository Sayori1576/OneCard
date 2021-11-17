#include "Player.h"

void Player::info()
{
	sort(mycard.begin(), mycard.end());
	Card uc = usecard[usecard.size() - 1];
	cout << "현재 " << name << "의 카드 개수는 " << mycard.size() << "개입니다." << endl;
	cout << uc.name << "이 카드패의 맨 위에 있습니다." << endl;
	cout << "현재 카드패:";
	for (int i = 0; i < mycard.size(); i++)
	{
		cout << mycard[i].name;
		if (i != mycard.size() - 1 && mycard[i].kind != mycard[i + 1].kind)
		{
			cout << "  ";
		}
		else
		{
			cout << " ";
		}
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
		int a = random(cardlist.size());
		mycard.push_back(cardlist[a]);
		cardlist.erase(cardlist.begin() + a);
	}
}
void Player::givecard()
{
	Card uc = usecard[usecard.size() - 1];
	pair<vector<int>,bool> a;
	if ((uc.type == ATTACK) && attack != 0)
	{
		a = cardattack(uc);
	}
	else
	{
		a = nomal(uc);
	}
	endwork(a.first,a.second);
}
bool Player::attackplus(const Card& C)
{
	if (C.type == ATTACK)
	{
		attack += C.attackval;
		cout << name << " 은" << C.name << " 으로 공격" << endl;
		cout << "먹어야 할 카드 " << C.attackval << "개 누적" << endl;
	}
	else if (C.type == DEFENSE)
	{
		if (attack != 0)
		{
			cout << name << " 은 공격을 막아냈다!" << endl;
			attack = 0;
		}
	}
	else if (C.type == ONEMORE)
	{
		Sleep(3000);
		clrscr();
		cout << "카드를 한 번 더 냅니다." << endl;
		info();
		givecard();
		return true;
	}
	else if (C.type == CCHANGE)
	{
		cout << "카드의 문양을 바꿉니다." << endl;
		cout << "0.♠ 1.♥ 2.◆ 3.♣" << endl;
		while (1)
		{
			int num;
			cin >> num;
			if (num == 0)
			{
				usecard.push_back({ "♠0", TEMP, 0, 0 });
				break;
			}
			else if (num == 1)
			{
				usecard.push_back({ "♥0", TEMP, 0, 0 });
				break;
			}
			else if (num == 2)
			{
				usecard.push_back({ "◆0", TEMP, 0, 0 });
				break;
			}
			else if (num == 3)
			{
				usecard.push_back({ "♣0", TEMP, 0, 0 });
				break;
			}
			else if (!cin)
			{
				cinnum();
			}
			else
			{
				cout << "잘못 입력하셨습니다." << endl;
			}
		}
		cout << "문양을 바꿉니다" << endl;
	}
	else if (C.type == JUMP)
	{
		isjmp = 1;
	}
	else if (C.type == REVERSE)
	{
		isreverse = !(isreverse);

	}
	return false;
}
pair<vector<int>,bool> Player::nomal(const Card& uc)
{
	vector<int> a;
	bool isint=0;
	for (int i = 0; i < mycard.size(); i++)
	{
		if (uc.kind == "J")
		{
			a.push_back(i);
		}
		else if (uc.type == TEMP && mycard[i].kind == uc.kind)
		{
			a.push_back(i);
		}
		else if (mycard[i].kind == uc.kind || mycard[i].num == uc.num || mycard[i].kind == "J")
		{
			a.push_back(i);

		}
	
	
	}
	auto cnt = [uc=uc](auto& m, tp a) {return (m.type == a&&(m.kind==uc.kind||m.num==uc.num||m.kind=="J")); };
	
	for (int i = 0; i < a.size(); i++)
	{
		cout << cnt(mycard[a[i]], ONEMORE) << " " << cnt(mycard[i], ATTACK)<<" "<<a.size()<<endl;

		if (mycard[a[i]].type == ONEMORE && (static_cast<size_t>(count_if(mycard.begin(), mycard.end(), [&cnt](auto& m) {return cnt(m, ONEMORE); })) == a.size()))
		{
			isint = 1;
		}
	else if (mycard[a[i]].type == ATTACK&& (static_cast<size_t>(count_if(mycard.begin(), mycard.end(), [&cnt](auto&m) {return cnt(m, ATTACK); })) == a.size()))
		{
				
			isint = 1;
		}
	}
	return make_pair(a,isint);
}
pair<vector<int>,bool> Player::cardattack(const Card& uc)
{
	cout << "상대방의 공격 감지" << endl;
	vector<int> a;
	for (int i = 0; i < mycard.size(); i++)
	{
		if (mycard[i].kind == uc.kind || mycard[i].num == uc.num || mycard[i].kind == uc.kind || mycard[i].kind == "J")
		{
			if (((mycard[i].type == ATTACK) && mycard[i].importance >= uc.importance) || mycard[i].type == DEFENSE)
				a.push_back(i);
		}
	}
	return make_pair(a,1);
}
void Player::endwork(vector<int>& a,bool cancel)
{
	auto cardmeokgi = [&]() {if (attack != 0)
	{
		cout << "카드 " << attack << " 장을 먹습니다." << endl;
		selectcard(attack);
		attack = 0;
	}
	else
	{
		selectcard(1);
	}
	cout << "현재 " << name << "의 카드 개수는 " << mycard.size() << "개입니다." << endl << endl;
	Sleep(3000);
	clrscr();
	};
		if (a.size() == 0)
		{

			cout << "낼 수 있는 카드가 없습니다." << endl;
			cardmeokgi();
			return;
		}
	cout << "뽑을 수 있는 카드" << endl;
	int i;
	for (i = 0; i < a.size(); i++)
	{
		cout << i << "." << mycard[a[i]].name << "  ";
		if (i % 7 == 0 && i != 0)
		{
			cout << endl;
		}
	}
	if (cancel)
	{
		cout << i << ".취소" << endl;
	}
	
	cout << "번호 입력" << endl;
	int n;

	while (1)
	{

		cin >> n;
		if (!cin)
		{
			cinnum();
		}
		else if (cancel&& n == a.size())
		{
			cout << "카드 내기를 포기합니다." << endl;
				cardmeokgi();
				return;
		}
		else if (n < 0 || n >= a.size())
		{
			cout << "잘못 입력하셨습니다" << endl;
		}
		else if (mycard[a[n]].attackval >= (usecard.size() + cardlist.size()))
		{
			cout << "낼 수 없습니다" << endl;
		}
		
		else
		{
			break;
		}
	}
	if (usecard[usecard.size() - 1].type == TEMP)
	{
		usecard.erase(usecard.begin() + (usecard.size() - 1));
	}
	usecard.push_back(mycard[a[n]]);
	mycard.erase(mycard.begin() + a[n]);
	cout << "현재 " << name << "의 카드 개수는 " << mycard.size() << "개입니다." << endl;
	bool k = !attackplus(usecard[usecard.size() - 1]);
	if (k)
	{

		Sleep(3000);
		clrscr();
	}

	return;

}