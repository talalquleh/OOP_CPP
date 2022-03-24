#include "enor.h"
#include <iostream>

/*
In a sequential input file, hunt trophies are stored: hunter name, species, weight.
How many hunters have shot rabbit ?
*/

/*
(extra) HW: On average, how many preys have the hunters shot in all trophies?
In case of empty file, the average is zero!
*/
using namespace std;

int main()
{

    try
    {

        Enor t("input.txt");
        int cnt = 0;
        t.first();
        while (!t.end())
        {
            if (t.current())
                cnt++;
            t.next();
        }
        cout << "number of hunter who shot rabbit :" << cnt << endl;
    }
    catch (Enor::fileError e)
    {
        cout << "unable to open file\n";
        return 1;
    }

    return 0;
}