#pragma once
#include "garden.h"

class Gardener
{
    public:
        Gardener(Garden* k) :  _garden(k) {}

        Garden* _garden;
};
