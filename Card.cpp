#include "Card.h"
Card::Card(const string& k, int n) : kind(k), num(n)//생성자 함수
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
Card::Card(const string& na)//생성자 함수
{
	name = na;
	kind = na[0];//종류 대입
	int temp = na[1] - '0';//일반적인 경우 그냥 둠
	if (temp == 'A')
	{
		temp = 1;
	}
	else if (temp == 'J')
	{
		temp = 11;
	}
	else if (temp == 'Q')
	{
		temp = 12;
	}
	else if (temp == 'K')
	{
		temp = 13;
	}
	
	num = temp;//숫자 대입
}