#include <iostream>
#include <string>
#include "library/seqinfileenumerator.hpp"
#include "library/summation.hpp"

using namespace std;

class Assortment : public Summation<int, ostream>
{
public:
    Assortment(ostream* o) : Summation<int, ostream>::Summation(o) { }
protected:
    std::string func(const int& e) const override { return (to_string(e)+" "); }
    bool cond(const int& e) const override { return e % 2 == 0; }

    /**string func(const int& e) const override
    {
        return (to_string(e)+" ");
    }
    bool cond(const int& e) const override { return e % 2 == 0; }*/
};

class assortToVector : public Summation<int,vector<int> >
{
public:
    assortToVector(const vector<int> &v) : Summation<int,vector<int> >::Summation(v) { }
protected:
    int func(const int& e) const override { return e; }
    bool cond(const int& e) const override { return e % 2 == 0; }

};

int main() ///ostream, vector
{
    ofstream f("output.txt");
    ///cout << "Even numbers: ";
    Assortment pr(&cout);  // Assortment pr(&cout);
    SeqInFileEnumerator<int> myenor("input.txt");
    pr.addEnumerator(&myenor);

    pr.run();
    f.close();
    cout << endl;

    vector<int> v = {2,3,4};

    assortToVector pr2(v);
    SeqInFileEnumerator<int> myenor2("input.txt");
    pr2.addEnumerator(&myenor2);

    pr2.run();

    v = pr2.result();

    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
