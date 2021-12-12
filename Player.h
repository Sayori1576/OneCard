#include "Default.h"
#include "Card.h"
#pragma once

class Player
{

public:
	Player(vector<Card> &b, vector<Card> &c, const string &n, int &a, bool &ij, bool &ir) //생성자
		: cardlist(b), usecard(c), name(n), attack(a), isjmp(ij), isreverse(ir), score(0) //초기화
	{

		selectcard(7); // 7장 뽑기
	}
	Player &operator=(const Player &rhs)
	{
		mycard = rhs.mycard;
		score = rhs.score;
		name = rhs.name;
		return *this;
	}
	void info() const;		  //정보 출력 함수
	void givecard();		  //카드 내기 함수
	void selectcard(int num); //카드 가져오기 함수
	void simpleinfo() const;
	size_t size() const		  //크기 반환 함수
	{
		return mycard.size();
	}
	string getname() const //이름 반환 함수
	{
		return name;
	}
	void plusscore(unsigned i)
	{
		score += i;
	}
	void sort()
	{
		using std::sort;
		sort(mycard.begin(), mycard.end());
	}
	bool iswin() //이겼다면 1, 졌다면 0 반환
	{
		if (mycard.size() == 0) //내 패에 카드가 없다면
		{

			return 1;
		}
		else
		{
			return 0; //아니라면
		}
	}
	int getscore() const
	{
		return score;
	}

private:
	vector<Card> mycard;								//내 카드 패
	vector<Card> &cardlist;								//카드 낸 곳
	vector<Card> &usecard;								//카드 뽑는 곳
	string name;										//플레이어 이름
	int &attack;										//공격값 총합
	bool &isjmp;										//점프 여부
	bool &isreverse;									//반전 여부
	bool attackplus(const Card &C);						//공격 카드를 냈다면 공격하는 함수
	pair<vector<int>, bool> nomal(const Card &uc);		//일반적인 경우에 뽑을 수 있는 카드를 고르는 함수
	pair<vector<int>, bool> cardattack(const Card &uc); //공격받았을 경우 뽑을 수 있는 카드를 고르는 함수
	void endwork(vector<int> &a, bool cancel);			//뽑을 수 있는 카드를 출력하고 고르게 하는 함수
	int score;											//점수
	void fillcard()										//카드 뽑는 곳의 카드가 없다면 낸 곳에서 가져옴
	{
		if (cardlist.size() == 0) //카드 뽑는 곳의 카드가 없다면
		{
			cout << "카드패의 부족한 카드를 다시 채웁니다." << endl;
			cardlist = usecard;
			usecard.clear();
			usecard.push_back(cardlist[cardlist.size() - 1]);
			cardlist.erase(cardlist.end() - 1); //낸 곳에서 카드 옮겨오기
			if (cardlist.size() == 0)			//그래도 없다면
			{
				cout << "카드패에 카드가 부족합니다"; //정보 출력
				exit(1);							  //강종
			}
		}
	}
};
