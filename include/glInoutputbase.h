#include "Default.h"
#pragma once
class Glinoutputbase
{
public:
virtual bool quitment()=0;
virtual void startment()=0;
virtual int inputplayernum()=0;
virtual std::string inputplayername()=0;

};