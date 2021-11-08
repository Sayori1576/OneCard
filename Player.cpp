#include "Player.h"
void Player::info()//정보 출력 함수
{
	Card uc = usecard[usecard.size() - 1];//낸 카드패 맨 위에 있는 카드
	cout << "현재 " << name << "의 카드 개수는 " << mycard.size() << "개입니다." << endl;//카드 개수 출력
	cout << uc.name << "이 카드패의 맨 위에 있습니다."<<endl;//카드패 맨 위에 있는 카드 출력
	cout << "현재 카드패:";
	for (int i = 0; i < mycard.size(); i++)
	{
		cout << mycard[i].name << " ";
	}//현재 내 카드패에 있는 카드들 출력
	cout << endl;
	if (attack != 0)//공격받고 있다면 누적된 먹어야 할 카드 수 출력
	{
		cout << "현재 누적된 먹어야 할 카드 수는 " << attack << "개입니다." << endl;
	}
}
void Player::selectcard(int num)//카드 뽑는 함수
{
	for (int i = 0; i < num; i++)
	{
		fillcard();//카드패에 카드가 없다면 뽑아옴
		randomize();//랜덤 섞기
		int a = random(cardlist.size());//랜덤 번호 뽑기
		mycard.push_back(cardlist[a]);//추가하기
		cardlist.erase(cardlist.begin() + a);//삭제하기
	}
}
void Player::givecard()//카드 내는 함수
{
	Card uc = usecard[usecard.size() - 1];//현재 낸 카드패 맨 위에 있는 카드
	vector<int> a;
	if ((uc.num == 2|| uc.num == 1||uc.kind=="J") && attack != 0)//공격받고 있다면
	{
		a=cardattack(uc);//공격받았을 때 뽑을 수 있는 카드 고르기
	}
	else//아니면
	{
		a=nomal(uc);//뽑을 수 있는 카드 고르기
	}
	endwork(a);
}
void Player::attackplus(vector<int>& a,int n)//공격 카드를 냈다면 공격하는 함수
{
		 if (mycard[a[n]].kind == "♠" && mycard[a[n]].num == 1)//스페이드 A를 냈다면
	{
	attack += spadeA;//누적 공격값에 스페이드 A의 공격력 추가
	cout << name << " 은" << mycard[a[n]].name << " 으로 공격" << endl;;
	cout << "먹어야 할 카드 "<<spadeA<<"개 누적" << endl;//정보 출력
	}
		 else if (mycard[a[n]].kind == "J" && mycard[a[n]].num == 1)//일반 조커를 냈다면
		 {
			 attack += blackj;//일반 조커의 공격력 추가
			 cout << name << " 은" << mycard[a[n]].name << " 으로 공격" << endl;
			 cout << "먹어야 할 카드 "<<blackj<<"개 누적" << endl;//정보 출력
		 }
		 else if (mycard[a[n]].kind == "J" && mycard[a[n]].num == 2)//칼라 조커를 냈다면
		 {
			 attack += colorj;//칼라 조커의 공격력 추가
			 cout << name << " 은" << mycard[a[n]].name << " 으로 공격" << endl;;
			 cout << "먹어야 할 카드 "<<colorj<<"개 누적" << endl;//정보 출력
		 }
	else if (mycard[a[n]].num == 2)//2를 냈다면
	{
		attack += two;//2의 공격력 추가
		cout << name << " 은" << mycard[a[n]].name << " 으로 공격" << endl;;
		cout << "먹어야 할 카드 "<<two<<"개 누적" << endl;//정보 출력
	}

	else if (mycard[a[n]].num == 1)//A를 냈다면
	{
		attack += aA;//A의 공격력 추가
		cout << name << " 은" << mycard[a[n]].name << " 으로 공격" << endl;
		cout << "먹어야 할 카드 "<<aA<<"개 누적" << endl;//정보 출력
	}
	else if (mycard[a[n]].num == 3)//방어 카드를 냈다면
		 {
			 if (attack != 0)//현재 공격 중이라면
			 {
				 cout << name << " 은 공격을 막아냈다!" << endl;//정보 출력
				 attack = 0;//누적 공격값 0으로 만들기
			 }
		 }
	
}
vector<int> Player::nomal(Card uc)//일반적인 경우에 뽑을 수 있는 카드를 고르는 함수
{
	vector<int> a;//뽑을 수 있는 번호들 목록
	for (int i = 0; i < mycard.size(); i++)
	{
		if (uc.kind == "J")//이전에 조커를 냈다면
		{
			a.push_back(i);//그냥 추가
		}
		else if (mycard[i].kind == uc.kind || mycard[i].num == uc.num || mycard[i].kind == "J")//아니라면 숫자나 종류가 같은 카드만 추가
		{
			a.push_back(i);
		}
	}// 뽑을 수 있는 카드 찾기
	return a;
}
vector<int> Player::cardattack(Card uc)//공격받았을 경우 뽑을 수 있는 카드를 고르는 함수
{
		cout << "상대방의 공격 감지" << endl;//정보 출력
		vector<int> a;//뽑을 수 있는 번호들 목록
		for (int i = 0; i < mycard.size(); i++)
		{
			if(mycard[i].kind == uc.kind || mycard[i].num == uc.num||mycard[i].kind==uc.kind)//종류나 숫자가 같은데
			{
			if (uc.num == 1 && uc.kind == "♠")//낸 카드패 맨 위에 스페이드 A가 있다면
			{
				if ((mycard[i].num == 3 || mycard[i].kind == "J"))//방어 카드나 조커일때만
				{

					a.push_back(i);//카드 추가

				}
			}
			else if (uc.num == 1 && uc.kind == "J")//흑백 조커를 냈다면
			{
				if ((mycard[i].num == 3) || (mycard[i].kind == "J"&&mycard[i].num==2))//방어 카드나 칼라 조커일때만
				{

					a.push_back(i);//카드 추가
					

				}
			}
			else if (uc.num == 2 && uc.kind == "J")//칼라 조커를 냈다면
			{
				if ((mycard[i].num == 3))//방어 카드일때만
				{

					a.push_back(i);//카드 추가


				}
			}
			else if (uc.num == 1)//A를 냈다면
			{
				if (mycard[i].num == 3 || mycard[i].num == 1 || mycard[i].kind == "J")//같은 A이거나 방어 카드거나 조커일 때만
				{

					a.push_back(i);//카드 추가

				}
			}
			else if (uc.num == 2)//2를 냈다면
			{
				if ((mycard[i].num == 2 || mycard[i].num == 3 || mycard[i].num == 1 || mycard[i].kind == "J"))//같은 2이거나 방어 카드거나 A거나 조커일 때만
				{

					a.push_back(i);//카드 추가

				}
			}
		}
			
		}// 뽑을 수 있는 카드 찾기
		return a;
}
void Player::endwork(vector<int> &a)//뽑을 수 있는 카드를 출력하고 고르게 하는 함수
{
	cout << "뽑을 수 있는 카드" << endl;//
	int i;
	for (i = 0; i < a.size(); i++)
	{
		cout << i << "." << mycard[a[i]].name << "  ";
		if (i % 7 == 0&&i!=0)
		{
			cout << endl;
		}
	}//뽑을 수 있는 카드들 출력
	if (a.size() == 0)//낼 수 있는 카드가 없다면
	{
		cout << "낼 수 있는 카드가 없습니다." << endl;//정보 출력
		if (attack != 0)//공격받고 있다면
		{
			cout << "카드 " << attack << " 장을 먹습니다." << endl;
			selectcard(attack);//카드 먹기
			attack = 0;//공격값 0으로 만들기
		}
		else//아니라면
		{
			selectcard(1);//한 장 뽑기
		}
		cout << "현재 " << name << "의 카드 개수는 " << mycard.size() << "개입니다." << endl<<endl;//정보 출력
		Sleep(2000);//잠시 기다리기
		clrscr();//화면 초기화
		
		return;
	}
	cout << "번호 입력" << endl;
	int n;
	while(1)
	{
	
		cin >> n;//번호 입력받기
		if (n < 0 || n >= a.size())//잘못 입력했다면
		{
			cout << "잘못 입력하셨습니다" << endl;//잘못 입력했다고 출력
		}
		else
		{
			break;
		}
	}
	attackplus(a, n);//낸 카드가 특수 카드인 경우 처리
	usecard.push_back(mycard[a[n]]);
	mycard.erase(mycard.begin() + a[n]);//카드를 낸다.
	cout << "현재 " << name << "의 카드 개수는 " << mycard.size() << "개입니다." << endl<<endl;//정보 출력
	Sleep(2000);//기다리기
	clrscr();//화면 초기화
	
	return;

}