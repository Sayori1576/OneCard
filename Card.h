#pragma once
#include "Default.h"


struct Card //카드 구조체
{
	Card(const string& k, int num);//종류, 숫자를 받아 초기화하는 생성자
	Card(const string& na);//카드 이름을 받아 초기화하는 생성자
	string kind;//종류
	int num;//숫자
	string name;//카드의 이름

};