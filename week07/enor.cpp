#include "enor.h"

std::istream &operator>>(std::istream &is, Trophy &t)
{

    is >> t.name >> t.spec >> t.weight;

    return is;
}

Enor::Enor(const std::string &fileName)
{

    x.open(fileName);
    if (x.fail())
        throw FILEERROR;
}

void Enor::next()
{

    _end = (sx == abnorm);
    if (!_end)
    {

        std::string name = dx.name;
        curr = false;
        while (sx == norm && dx.name == name)
        {
            curr = curr || (dx.spec == "rabbit");
            read();
        }
    }
}

void Enor::read(){
    sx=(x>>dx)?norm:abnorm;
}