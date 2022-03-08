#include "glInoutputbase.h"
#pragma once
namespace Onecard
{
class TextGlInOutput:public Glinoutputbase
{
public:
virtual bool quitment() override;
virtual void startment() override;
virtual int inputplayernum() override;
virtual std::string inputplayername() override;
};
}