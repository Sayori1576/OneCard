#include "Card.h"

Card::Card(const string &k, int n, tp t, int im, int at) : kind(k), num(n), type(t), importance(im), attackval(at)
{
	string temp = to_string(n);
	switch (n)
	{
	case 1:
		temp = 'A';
		break;
	case 11:
		temp = 'J';
		break;
	case 12:
		temp = 'Q';
		break;
	case 13:
		temp = 'K';
		break;
	}
	name = k + temp;
}
Card::Card(const string &na, tp t, int im, int at) : type(t), importance(im), attackval(at)
{
	name = na;
	kind = na.substr(0, 3);
	int temp = na[3] - '0';
	if (na[1] == 'A')
	{
		temp = 1;
	}
	else if (na[2] == 'J')
	{
		temp = 11;
	}
	else if (na[2] == 'Q')
	{
		temp = 12;
	}
	else if (na[2] == 'K')
	{
		temp = 13;
	}

	num = temp;
}