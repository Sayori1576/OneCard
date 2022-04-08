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
            #ifndef ONECARD_DEBUG
            auto engine = std::default_random_engine{};
            std::shuffle(cardlist.begin(),cardlist.end(),engine);
            #endif

        }
        Card getrandomcard();
        void addcard(const Card& c);
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