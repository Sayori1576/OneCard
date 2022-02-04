#include "GmInoutputbase.h"
#pragma once
class TextGmInoutput:public GmInoutputbase
{
    public:
virtual void jumpment(std::string_view plname) override;
virtual void winment(std::string_view plname) override;
virtual bool isretry() override;
virtual void printranks(const std::vector<std::pair<std::string, int>>& winlist,std::vector<std::pair<std::string, int>>&players)  override;
};