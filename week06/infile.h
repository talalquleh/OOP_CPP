#include <iostream>
#include <fstream>

struct Occur
{
    int num;
    int occ;
    friend std::ostream &operator<<(std::ostream &o, const Occur &oc)
    {
        std::cout << "<" << oc.num << "," << oc.occ << ">";
        return o;
    }
};
enum Status
{
    norm,
    abnorm
};

class inFile
{
private:
    std::ifstream x;
    int dx;
    Status sx;
    Occur curr;
    bool _end;
    void read();

public:
    enum fileError
    {
        openingFileError
    };
    inFile(const std::string &fileName);
    ~inFile() { x.close(); }
    void first()
    {
        read();
        next();
    }
    void next();
    Occur current()const { return curr; }
    bool end() const
    {
        return _end;
    }
};
