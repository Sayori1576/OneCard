


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

#define randomize() srand((unsigned)time(NULL))	
#define random(n) (rand() % (n))	
inline void Sleep(clock_t milliseconds) {

	clock_t start = clock();

	while ((clock() - start) * 1000 / CLOCKS_PER_SEC < milliseconds);
}
#ifdef _WIN32



// 화면을 모두 지운다.
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
