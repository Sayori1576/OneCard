#pragma once
#include "Default.h"
namespace Onecard
{
enum tp
{
	NOMAL,
	ATTACK,
	JUMP,
	REVERSE,
	DEFENSE,
	CCHANGE,
	ONEMORE,
	TEMP,
	CANCEL
};			//상태 열거형
enum kn
{
	SPADE,
	DIAMOND,
	HEART,
	CLUB
};
struct Card //카드 구조체
{
	Card(kn k, int num, tp t = NOMAL, int im = 0, int at = 0); //종류, 숫자를 받아 초기화하는 생성자
	kn kind;														  //문양 종류
	int num;															  //숫자
	tp type;															  //카드 종류
															  //카드의 이름
	int importance;														  //중요도(높을수록 좋음)
	int attackval;														  //공격값
	bool operator<(const Card &rhs)										  //비교 연산자
	{
		if (kind != rhs.kind)
		{
			return kind < rhs.kind;
		}
		else
		{
			return num < rhs.num;
		}
	}
};
}