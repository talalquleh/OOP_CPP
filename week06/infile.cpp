#include "infile.h"

inFile::inFile(const std::string &fileName)
{
    x.open(fileName);
    if (x.fail())
        throw openingFileError;
}
void inFile::next()
{

    _end = (sx == abnorm);
    if (!_end)
    {
        curr.num = dx;
        curr.occ = 0;
        while (sx == norm && dx == curr.num)
        {
            curr.occ++;
            read();
        }
    }
}

void inFile::read()
{
    //     x >> dx;
    //     if (x.fail)
    //         sx = abnorm;
    //     else
    //         sx = nor;
    sx = (x >> dx) ? norm : abnorm;
}