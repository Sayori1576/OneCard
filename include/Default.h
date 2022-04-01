
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
#include "effolkronium/random.hpp"
using Random = effolkronium::random_static;
using std::cin;
using std::cout;
using std::endl;
namespace Default
{
	template<typename T,typename U>
	decltype(auto) random(T from, U to)
	{
		#ifdef DEBUG
		return 0;
		#else
		return Random::get(from,to);
		#endif
	}
	inline void cinnum()
	{

		cin.clear();

		cin.ignore(INT_MAX, '\n');

		cout << "잘못된 값을 입력하셨습니다. 숫자만 입력해주세요.\n";
	}
}
