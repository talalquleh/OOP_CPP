#include <iostream>
#include <vector>
#include "library/seqinfileenumerator.hpp"
#include "library/maxsearch.hpp"
#include "library/counting.hpp"
#include "library/selection.hpp"
using namespace std;

/*

Task Descritpion:
an island is a consecutive numbers in an input file , and water is represented by 0 to seprate the islands,
give the longest island among them, and indicate its length

*/
class CrossingSee : public Selection<int> 
{
protected:
    void first() override {} 
    bool cond(const int &e) const override { return _enor->end() || e != 0; }
};

class IslandLength : public Counting<int> 
{
protected:
    void first() override {} 
    bool whileCond(const int &e) const override { return e > 0; } 
};

struct Island
{
	int length;
	int no;
};

class IslandEnumerator : public Enumerator<Island> 
{
private:
    SeqInFileEnumerator<int> *_f;
    Island _island;
    bool _end;
public:
    IslandEnumerator(const string &fname){
        _f = new SeqInFileEnumerator<int>(fname);
    }
    ~IslandEnumerator(){ delete _f; }
    void first() override { _f->first(); _island.no = 0; next(); }
    void next() override;
    Island current() const override { return _island; }
    bool end() const override { return _end; }
};

void IslandEnumerator::next()
{
    CrossingSee pr1; 
    pr1.addEnumerator(_f);
    pr1.run();

    if( (_end = _f->end()) ) return; 

	++_island.no;
    IslandLength pr2; 
    pr2.addEnumerator(_f);
    pr2.run();
    _island.length = pr2.result();
}

class MaxIsland : public MaxSearch<Island,int> 
{
protected:
    int func(const Island &e) const { return e.length; }
};

int main()
{
    try
    {
        MaxIsland pr;
        IslandEnumerator enor("input.txt");
        pr.addEnumerator(&enor);
        pr.run();
        if (pr.found())
            cout << "Longest island's (" << pr.optElem().no << ".) length is: " << pr.opt() << endl;
        else
            cout << "There is no island in the file.\n";
    }
    catch (SeqInFileEnumerator<int>::Exceptions exc)
    {
        cout << "File not found!\n";
        return 1;
    }
    return 0;
}
