#include "GlCard.h"
namespace Onecard
{
    /* Card GlCard::getrandomcard()
     {

     }*/
    void GlCard::init()
    {
        for (int i = 0; i <= 3; i++)
        {

            for (int q = 1; q <= 13; q++)
            {
                Card temp = Card{static_cast<kn>(i), q};
                cardlist.push_back(temp);
            }
        }
        cardlist.push_back(Card{kn::JOCKER, 1});
        cardlist.push_back(Card{kn::JOCKER, 2});
    }
    void defaultsetting(Card &cd, int plsize)
    {
        if (cd.num == 1)
        {
            cd.type = tp::ATTACK;
            if (cd.kind == kn::SPADE)
            {
                cd.importance = 3;
                cd.attackval = 5;
            }
            else
            {
                cd.importance = 2;
                cd.attackval = 3;
            }
        }
        else if (cd.num == 2)
        {
            cd.type = tp::ATTACK;
            cd.importance = 1;
            cd.attackval = 2;
        }
        else if (cd.num == 3)
        {
            cd.type = tp::DEFENSE;
        }
        else if (cd.num == 7)
        {
            cd.type = tp::CCHANGE;
        }
        else if (cd.num == 11)
        {
            if (plsize < 3)
            {
                cd.type = tp::ONEMORE;
            }
            else
            {
                cd.type = tp::JUMP;
            }
        }
        else if (cd.num == 12)
        {
            if (plsize < 3)
            {
                cd.type = tp::ONEMORE;
            }
            else
            {
                cd.type = tp::REVERSE;
            }
        }
        else if (cd.num == 13)
        {
            cd.type = tp::ONEMORE;
        }
        if (cd.kind == kn::JOCKER)
        {
            cd.type = tp::ATTACK;
            if (cd.num == 1)
            {
                cd.attackval = 5;
                cd.importance = 4;
            }
            else if (cd.num == 2)
            {
                cd.attackval = 7;
                cd.importance = 5;
            }
        }
    }
};