#pragma once
#include "Player.h"
#include "Card.h"
class Game //게임 클래스
{
public:
	Game(const std::vector<std::string> &a); //생성자
	void start();				   //게임 시작
private:
	std::vector<Card> cardlist;	//전체 카드패
	std::vector<Card> usecard;	//낸 카드패
	int attack;				//공격값
	std::vector<Player> Players; //플레이어들
	void init(size_t t);	//전체 카드패를 초기화하는 함수
	bool isjmp;				//점프 여부
	bool isreverse;			//반전 여부
	std::vector<std::pair<std::string, int>> winlist;
};