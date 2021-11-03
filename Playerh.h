#include "Default.h"
#include "Card.h"
#pragma once

class Player
{

public:
	Player(vector<Card>& b, vector<Card>& c, const string& n, int& a)
		:cardlist(b), usecard(c), name(n), atack(a)
	{
		selectcard(7);
	}
	void info();
	void givecard();
	void selectcard(int num);
	int size()
	{
		return mycard.size();
	}
	string getname()
	{
		return name;
	}
private:
	vector<Card> mycard;
	vector<Card>& cardlist;
	vector<Card>& usecard;
	string name;
	int& atack;
	void atackplus(vector<int>& a,int n);
	void nomal(Card uc);
	void cardattack(Card uc);
	void endwork(vector<int>& a);
	void fillcard()
	{
		if (cardlist.size() == 0)
		{
			cout << "ī������ ������ ī�带 �ٽ� ä��ϴ�." << endl;
			cardlist = usecard;
			usecard.clear();
			usecard.push_back(cardlist[cardlist.size()-1]);
			cardlist.erase(cardlist.end() - 1);
			
		}
	}
};
