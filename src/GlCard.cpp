#include "GlCard.h"
namespace Onecard
{
    /* Card GlCard::getrandomcard()
     {

     }*/
    void defaultsetting(Card &cd)
    {
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
        cardlist.push_back(Card{kn::JOCKER,1});
        cardlist.push_back(Card{kn::JOCKER,2});
        
    }
    
};