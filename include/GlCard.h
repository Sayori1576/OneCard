#pragma once
#include "Default.h"
#include "Card.h"
namespace Onecard
{
    class GlCard
    {
    public:
        Card getrandomcard() const;
        void Addcard();
    private:
        std::vector<Card> cardlist;
        std::vector<Card> usecard;
    };
};