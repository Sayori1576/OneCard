#include "Score.h"
int Score::getscore() const
{
    return score;
}
void Score::addscore(int addval)
{
    score += addval;
}