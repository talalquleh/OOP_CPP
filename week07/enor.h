#pragma once

#include <string>
#include <iostream>
#include <fstream>

struct Trophy
{
    std::string name;
    std::string spec;
    int weight;
    friend std::istream &operator>>(std::istream &is, Trophy &t);
};

enum Status
{
    abnorm,
    norm
};

class Enor
{
public:
    enum fileError
    {
        FILEERROR
    };

    Enor(const std::string &fileName);

    ~Enor() { x.close(); }
    void first()
    {
        read();
        next();
    }
    bool current() const { return curr; }
    void next();

    bool end() const { return _end; }

private:
    std::ifstream x;
    Trophy dx;
    Status sx;
    bool curr;
    bool _end;

    void read();
};