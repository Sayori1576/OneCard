#include "Default.h"
namespace Onecard
{
class Score
{
public:
    int getscore() const;
    void addscore(int addval);
    Score() : score(0)
    {
    }

private:
    int score;
};
}