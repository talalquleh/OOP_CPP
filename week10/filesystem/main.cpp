#include <iostream>
#include "filesystem.h"

using namespace std;

int main()
{
    FileSystem* sys = new FileSystem;

    sys->add(new File(2));

    Library* f = new Library();
    sys->add(f);
    f->add(new File(20));
    f->add(new File(10));

    Library* ff = new Library();
    f->add(ff);
    ff->add(new File(100));

    sys->add(new File(3));

    cout << "Size: " << sys->getSize() << endl;

    delete sys;

    return 0;
}
