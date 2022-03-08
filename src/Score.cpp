#include "Score.h"
namespace Onecard
{
int Score::getscore() const
{
    return score;
}
void Score::addscore(int addval)
{
    score += addval;
}
}