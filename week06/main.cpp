#include <iostream>
#include "infile.h"
using namespace std;
int main()
{
    bool fileErr = true;
    while (fileErr)
    {
        try
        {
            string fileName;
            cout << "Enter a fileName: ";
            cin >> fileName;
            inFile t(fileName);
            t.first();
            while (!t.end())
            {
                cout << t.current() << endl;
                t.next();
            }
            fileErr = false;
        }
        catch (inFile::fileError e)
        {
            cout << "file error" << endl;
        }
    }

    return 0;
}