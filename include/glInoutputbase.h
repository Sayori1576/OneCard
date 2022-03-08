#include "Default.h"
#pragma once
namespace Onecard
{
class Glinoutputbase
{
public:
virtual bool quitment()=0;
virtual void startment()=0;
virtual int inputplayernum()=0;
virtual std::string inputplayername()=0;

};
}