#pragma once
#include "Default.h"

enum tp{NOMAL,ATTACK,JUMP,REVERSE,DEFENSE,CCHANGE,ONEMORE};
struct Card //카드 구조체
{
	Card(const string& k, int num, tp t = NOMAL,int im=0, int at=0);//종류, 숫자를 받아 초기화하는 생성자
	Card(const string& na, tp t = NOMAL, int im = 0, int at = 0);//카드 이름을 받아 초기화하는 생성자
	string kind;//문양 종류
	int num;//숫자
	tp type;//카드 종류
	string name;//카드의 이름
	int importance;//중요도(높을수록 좋음)
	int attackval;//공격값
};