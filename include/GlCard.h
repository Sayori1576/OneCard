#pragma once
#include "Default.h"
#include "Card.h"
namespace Onecard
{
    void defaultsetting(Card &cd,int plsize);
    class GlCard
    {
    public:
        GlCard(int plsize,std::function<void(Card &,int)> fn=defaultsetting)
        {
            init();
            for (auto &x : cardlist)
            {
                fn(x,plsize);
            }
        }
        Card getrandomcard();
        void Addcard();
        void init();
        decltype(auto) getcardlistsize() const
        {
            return cardlist.size();
        }
        decltype(auto) getusecardsize() const
        {
            return usecard.size();
        }
    private:
        std::vector<Card> cardlist;
        std::stack<Card> usecard;
        bool issettinged;
    };
};