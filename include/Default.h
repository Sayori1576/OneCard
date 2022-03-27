
#pragma once
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
#include <stack>
using std::cin;
using std::cout;
using std::endl;
namespace Default
{
	inline void cinnum()
	{

		cin.clear();

		cin.ignore(INT_MAX, '\n');

		cout << "잘못된 값을 입력하셨습니다. 숫자만 입력해주세요.\n";
	}
}
