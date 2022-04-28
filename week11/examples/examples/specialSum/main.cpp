#include <iostream>
#include <vector>
#include "../library/summation.hpp"
#include "../library/seqinfileenumerator.hpp"
#include "../library/arrayenumerator.hpp"

using namespace std;

class Concat : public Summation<int, vector<int> >{
public:
    Concat(const vector<int> &v) : Summation<int, vector<int> >(v) {}
    int func(const int &e) const override { return e; }
};

class Write : public Summation<int, ostream > {
public:
   Write(ostream* o) : Summation<int, ostream>(o) {}
    string func(const int &e) const override {
        ostringstream os;
        os << e << " " ;
        return os.str();
    }
};

int main()
{
    cout << "Hello world!" << endl;
    vector<int> v = { -17 };

    Concat pr(v);
    SeqInFileEnumerator<int> enor("input.txt");
    pr.addEnumerator(&enor);
    pr.run();

    Write pr1(&cout);
    ArrayEnumerator<int> enor1(&pr.result());
    pr1.addEnumerator(&enor1);
    pr1.run();

    cout << endl;

    return 0;
}
