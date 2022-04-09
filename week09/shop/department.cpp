#include "department.h"



Department::Department(const std::string &fname)
{
    std::ifstream f(fname);
    float i;
    std::string s;
    while (f >> s >> i) {
        ///Product* p = new Product(s,i);
        _stock.push_back(new Product(s,i));
    }
    
}

void Department::takeOutFromStock(Product* product)
{
    bool L = false;
    int ind;
    for( unsigned int i = 0; !L && i < _stock.size(); ++i) {
        L =( _stock[i] == product);
        ind = i;
    }
    if (L)  _stock.erase(_stock.begin()+ind);
}


