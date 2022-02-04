#pragma once
#include "Default.h"

class GmInoutputbase
{
    public:
virtual void jumpment(std::string_view plname)=0;
virtual void winment(std::string_view plname)=0;
virtual bool isretry()=0;
virtual void printranks(const std::vector<std::pair<std::string, int>>& winlist,std::vector<std::pair<std::string, int>>&players)=0;
};