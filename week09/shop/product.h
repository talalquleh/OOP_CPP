#pragma once
#include <string>

class Product
{
    public:
        Product(std::string name, float price) : _name(name), _price(price) {}
        std::string getName() const { return _name; }
        float getPrice() const { return _price; }
    private:
        std::string _name;
        float _price;
};
