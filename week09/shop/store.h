#pragma once
#include "department.h"

class Store
{
    public:
        Store(const std::string &fname, const std::string &tname);

        Department* technical;
        Department* foods;
};
