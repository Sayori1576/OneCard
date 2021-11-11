#include "Card.h"
Card::Card(const string& k, int n, tp t, int im, int at)
: kind(k), num(n), type(t), importance(im), attackval(at)//생성자 함수
{
	string temp = to_string(n);//일반적인 경우 숫자는 그대로 표시
	switch (n)
	{
	case 1://카드의 숫자가 1이라면 A로 표시
		temp = 'A';
		break;
	case 11:
		temp = 'J';//카드의 숫자가 11이라면 J로 표시
		break;
	case 12:
		temp = 'Q';//카드의 숫자가 12라면 Q로 표시
		break;
	case 13:
		temp = 'K';//카드의 숫자가 13이라면 K로 표시
		break;

	}
	name = k + temp;//이름 대입

}
Card::Card(const string& na, tp t, int im, int at)
:type(t), importance(im), attackval(at)//생성자 함수
{
	name = na;
	kind=na.substr(0,2);//종류 대입
	int temp = na[2] - '0';//일반적인 경우 그냥 둠
	if (na[2] == 'A')
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
	
	num = temp;//숫자 대입
}