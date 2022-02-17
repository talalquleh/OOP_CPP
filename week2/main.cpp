#include <iostream>
#include <fstream>
#include <vector>
#include "point.h"
#include "circle.h"
#include "circle.h"
using namespace std;

void readFromFile(Circle &c,vector<Point> &vec);
bool search(const Circle& cir, const vector<Point> &t, unsigned int &ind);

int main()
{
    //using exception : throw , try-catch block
    try
    {
        Circle circle;
        vector<Point> vec;

        readFromFile(circle,vec);

        unsigned int ind;

        if(search(circle, vec, ind))
            cout << vec[ind].toString() << " is in the circle.\n";
        else
            cout << "None of them is in the circle.\n";

    }
    catch (Circle::WrongRadiusException ex)
    {
        cout << "Negative radius in the file!\n";
    }
    return 0;
}

void readFromFile(Circle &cir,vector<Point> &vec)
{
    ifstream f("input.txt");
    if(f.fail())
    {
        cout << "Wrong file name!\n";
        exit(1);
    }

    double a, b, c;
    f >> a >> b >> c;
    cir = Circle(Point(a,b),c);

    vec.clear();
    while(f >> a >> b){
        vec.push_back(Point(a,b));
    }
}

bool search(const Circle& cir, const vector<Point> &t, unsigned int &ind)
{
    bool l = false;
    for(unsigned int i=0; !l && i<t.size(); ++i)
    {
        l = cir.in(t[i]);
        ind = i;
    }
    return l;


//    for(ind=0; ind<t.size(); ++ind)
//    {
//        if( cir.in(t[i]) ) return true;
//    }
//    return false;
}
