#pragma once
#include "product.h"
#include <vector>
#include <fstream>

class Department
{
    public:
        Department(const std::string &fname);
        void takeOutFromStock(Product *product); // _stock.remove(Product*)

        std::vector<Product*> _stock;
};
