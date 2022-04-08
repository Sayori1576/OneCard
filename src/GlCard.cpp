#include "GlCard.h"
namespace Onecard
{
    Card GlCard::getrandomcard()
    {
        if (cardlist.size() <= 0)
        {
            Card temp = usecard.top();
            if (!usecard.empty())
            {
                cardlist.push_back(usecard.top());
                usecard.pop();
            }
            else
            {
                usecard.push(temp);
                throw std::runtime_error("카드 없음");
            }
            usecard.push(temp);
        }

        auto temp = *(cardlist.end() - 1);
        cardlist.erase(cardlist.end() - 1);
        return temp;
    }
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
    void GlCard::addcard(const Card &c)
    {
        usecard.push(c);
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
            
        }
        else if (cd.num == 7)
        {
            
        }
        else if (cd.num == 11)
        {
            if (plsize < 3)
            {
               
            }
            else
            {
                
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