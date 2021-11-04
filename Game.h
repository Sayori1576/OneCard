#pragma once
#include "Player.h"
#include "Card.h"
class Game
{
public:
	Game(const vector<string>& a);
	void start();
private:
    
	vector<Card> cardlist;//Ä«µåÆÐ
	vector<Card> usecard;
	int attack;
	vector<Player> Players;
	void init();
};