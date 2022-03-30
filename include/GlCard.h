#pragma once
#include "Default.h"
#include "Card.h"
namespace Onecard
{
    void defaultsetting(Card &cd);
    class GlCard
    {
    public:
        GlCard(std::function<void(Card &)> fn=defaultsetting)
        {
            init();
            for (auto &x : cardlist)
            {
                fn(x);
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