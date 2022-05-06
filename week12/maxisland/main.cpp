#include <iostream>
#include <vector>
#include "library/seqinfileenumerator.hpp"
#include "library/maxsearch.hpp"
#include "library/counting.hpp"
#include "library/selection.hpp"

/// Egy repülõ azonos idõközönként tengerszint feletti méréseket végez az óceán fölött.
/// Keressük a leghosszabb mért sziget hosszát.

using namespace std;

class CrossingSee : public Selection<int> /// keressük az elsõ pozitív mérést
{
protected:
    void first() override {} /// a fájl már meg van kezdve
    bool cond(const int &e) const override { return _enor->end() || e != 0; }
};

class IslandLength : public Counting<int> /// mérjük egy sziget hosszát
{
protected:
    void first() override {} /// a fájl már meg van kezdve
    bool whileCond(const int &e) const override { return e > 0; } /// kiegészítõ leállási feltétel
};

struct Island
{
	int length;
	int no;
};

class IslandEnumerator : public Enumerator<Island> /// felsorolja a szigetek hosszát
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
    CrossingSee pr1; /// megkeresi az elsõ szigetet (ha van)
    pr1.addEnumerator(_f);
    pr1.run();

    if( (_end = _f->end()) ) return; /// és ha nincs vége a fájlnak

	++_island.no;
    IslandLength pr2; /// megszámolja a sziget hosszát
    pr2.addEnumerator(_f);
    pr2.run();
    _island.length = pr2.result();
}

class MaxIsland : public MaxSearch<Island,int> /// Maxker a szigethosszakra
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
