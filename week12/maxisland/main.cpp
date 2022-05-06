#include <iostream>
#include <vector>
#include "library/seqinfileenumerator.hpp"
#include "library/maxsearch.hpp"
#include "library/counting.hpp"
#include "library/selection.hpp"

/// Egy rep�l� azonos id�k�z�nk�nt tengerszint feletti m�r�seket v�gez az �ce�n f�l�tt.
/// Keress�k a leghosszabb m�rt sziget hossz�t.

using namespace std;

class CrossingSee : public Selection<int> /// keress�k az els� pozit�v m�r�st
{
protected:
    void first() override {} /// a f�jl m�r meg van kezdve
    bool cond(const int &e) const override { return _enor->end() || e != 0; }
};

class IslandLength : public Counting<int> /// m�rj�k egy sziget hossz�t
{
protected:
    void first() override {} /// a f�jl m�r meg van kezdve
    bool whileCond(const int &e) const override { return e > 0; } /// kieg�sz�t� le�ll�si felt�tel
};

struct Island
{
	int length;
	int no;
};

class IslandEnumerator : public Enumerator<Island> /// felsorolja a szigetek hossz�t
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
    CrossingSee pr1; /// megkeresi az els� szigetet (ha van)
    pr1.addEnumerator(_f);
    pr1.run();

    if( (_end = _f->end()) ) return; /// �s ha nincs v�ge a f�jlnak

	++_island.no;
    IslandLength pr2; /// megsz�molja a sziget hossz�t
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
