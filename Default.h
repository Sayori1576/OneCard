


#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <string>
#pragma once
using namespace std;
inline void cinnum()
{

		cin.clear();

		cin.ignore(INT_MAX, '\n');
		
			cout << "�߸��� ���� �Է��ϼ̽��ϴ�. ���ڸ� �Է����ּ���.\n";


		


}
#define randomize() srand((unsigned)time(NULL))	
#define random(n) (rand() % (n))	
inline void Sleep(clock_t milliseconds) {

	clock_t start = clock();

	while ((clock() - start) * 1000 / CLOCKS_PER_SEC < milliseconds);
}
#ifdef _WIN32



// ȭ���� ��� �����.
inline void clrscr()
{
	system("cls");
}



#else
inline void clrscr()
{
	system("clear");
}


#endif
