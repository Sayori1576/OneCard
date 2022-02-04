

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <cstring>
#include <functional>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <string>
#include <iomanip>
#include <climits>
#include <thread>
#include <chrono>
#include <string_view>
#pragma once
using std::cout;
using std::endl;
using std::cin;
inline void cinnum()
{

	cin.clear();

	cin.ignore(INT_MAX, '\n');

	cout << "잘못된 값을 입력하셨습니다. 숫자만 입력해주세요.\n";
}
#define randomize() srand((unsigned)time(NULL))
#define random(n) (rand() % (n))
inline void Sleep(clock_t milliseconds)
{
std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}
const int sleeptime=1000;
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
