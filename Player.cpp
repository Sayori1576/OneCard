#include "Player.h"
void Player::simpleinfo() const
{
	cout << name << ":" << mycard.size();
}
void Player::info() const
{

	Card uc = usecard[usecard.size() - 1];
	cout << "현재 " << name << "의 점수는 " << score << "점이고 카드 개수는 " << mycard.size() << "개입니다." << endl;
	cout << uc.name << "이 카드패의 맨 위에 있습니다." << endl;
	cout << "현재 카드패:";
	for (std::vector<Card>::size_type i = 0; i < mycard.size(); i++)
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
	std::pair<std::vector<int>, bool> a;
	if ((uc.type == ATTACK) && attack != 0)
	{
		a = cardattack(uc);
	}
	else
	{
		a = nomal(uc);
	}
	endwork(a.first, a.second);
}
bool Player::attackplus(const Card &C)
{
	if (C.type == ATTACK)
	{
		attack += C.attackval;
		cout << name << " 은" << C.name << " 으로 공격" << endl;
		cout << "먹어야 할 카드 " << C.attackval << "개 누적" << endl;
		score += C.attackval;
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
				usecard.push_back({"♠0", TEMP, 0, 0});
				break;
			}
			else if (num == 1)
			{
				usecard.push_back({"♥0", TEMP, 0, 0});
				break;
			}
			else if (num == 2)
			{
				usecard.push_back({"◆0", TEMP, 0, 0});
				break;
			}
			else if (num == 3)
			{
				usecard.push_back({"♣0", TEMP, 0, 0});
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
std::pair<std::vector<int>, bool> Player::nomal(const Card &uc)
{
	std::vector<int> a;
	bool isint = 0;
	for (std::vector<int>::size_type i = 0; i < mycard.size(); i++)
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
	auto cnt = [uc = uc](auto &m, tp a)
	{ return (m.type == a && (m.kind == uc.kind || m.num == uc.num || m.kind == "J")); };

	if (((static_cast<size_t>(count_if(mycard.begin(), mycard.end(), [&cnt](auto &m)
									   { return cnt(m, ATTACK); }))) +
		 (static_cast<size_t>(count_if(mycard.begin(), mycard.end(), [&cnt](auto &m)
									   { return cnt(m, ONEMORE); })))) == a.size())
	{
		isint = 1;
	}

	return make_pair(a, isint);
}
std::pair<std::vector<int>, bool> Player::cardattack(const Card &uc)
{
	cout << "상대방의 공격 감지" << endl;
	std::vector<int> a;
	for (std::vector<int>::size_type i = 0; i < mycard.size(); i++)
	{
		if (mycard[i].kind == uc.kind || mycard[i].num == uc.num || mycard[i].kind == uc.kind || mycard[i].kind == "J")
		{
			if (((mycard[i].type == ATTACK) && mycard[i].importance >= uc.importance) || mycard[i].type == DEFENSE)
				a.push_back(i);
		}
	}
	return make_pair(a, 1);
}
void Player::endwork(std::vector<int> &a, bool cancel)
{
	
	
	if (a.size() == 0)
	{

		cout << "낼 수 있는 카드가 없습니다." << endl;
		cardmeokgi();
		return;
	}
	if (usecard[usecard.size() - 1].type == TEMP)
	{
		usecard.erase(usecard.begin() + (usecard.size() - 1));
	}
	score++;
	int n=printandinputcard(a,cancel);
	if(n==1)
	{
		return;
	}
	usecard.push_back(mycard[n]);
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
int Player::printandinputcard(const std::vector<int>& a,bool cancel)
{
	cout << "뽑을 수 있는 카드" << endl;
	int i;
	for (i = 0; i < static_cast<int64_t>(a.size()); i++)
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
		else if (cancel && n == static_cast<int64_t>(a.size()))
		{
			cout << "카드 내기를 포기합니다." << endl;
			cardmeokgi();
			return -1;
		}
		else if (n < 0 || n >= static_cast<int64_t>(a.size()))
		{
			cout << "잘못 입력하셨습니다" << endl;
		}
		else if (mycard[a[n]].attackval >= static_cast<int64_t>(usecard.size() + cardlist.size()))
		{
			cout << "낼 수 없습니다" << endl;
		}

		else
		{
			break;
		}
	}
return a[n];
}
void Player::cardmeokgi()
{
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
		cout << "현재 " << name << "의 카드 개수는 " << mycard.size() << "개입니다." << endl
			 << endl;
		Sleep(3000);
		clrscr();
}	