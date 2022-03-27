#include "Default.h"
inline void Sleep(clock_t milliseconds)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}
const int sleeptime = 1000;
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

