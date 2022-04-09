#pragma once
#include "store.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

class Customer
{
    public:
        Customer(const std::string &fname);
        std::string purchase(const Store &store);

        std::string getName() const { return name; }

    private:
        std::string name;
        std::vector<std::string> list;
        std::vector<Product*> cart;

        bool linsearch(std::string name, Department* r, Product* &product) const;
        bool condminsearch(std::string name, Department* r, Product* &product) const;
};
