#pragma once
#include "Player.h"
#include "Card.h"
class Game
{
public:
	Game(const vector<string>& a);
	void start();
private:
    
	vector<Card> cardlist;//ī����
	vector<Card> usecard;
	int attack;
	vector<Player> Players;
	void init();
};