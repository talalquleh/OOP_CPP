#include "Store.h"


Store::Store(const std::string &fname, const std::string &tname)
{
    foods = new Department(fname);
    technical = new Department(tname);
}

