#include "Card.h"
Card::Card(const string& k, int n) : kind(k), num(n)
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
Card::Card(const string& na)
{
	kind = na[0];
	num = atoi(&na[1]);
	char temp = na[1];
	if (temp == '1')
	{
		temp = 'A';
	}
	else if (temp == '11')
	{
		temp = 'J';
	}
	else if (temp == '12')
	{
		temp = 'Q';
	}
	else if (temp == '13')
	{
		temp = 'K';
	}
	name = na[0] + temp;
}