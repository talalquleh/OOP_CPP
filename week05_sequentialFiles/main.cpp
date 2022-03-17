/*
Give a sequential input file:
1-Average of temps before the first freezing point (< 0)
2-Average of temps after the first freezing point (first freezing point is not included)
3-Average of temps before and after the freezing point (first freezing point is not included)).



*/

#include <iostream>
#include <fstream>
using namespace std;

enum Status
{
    norm,
    abnorm
};

double divide(double s, int c);
void read(Status &st, double &e, fstream &x);

double avgBeforeFreezingPoint(fstream &x);
double avgAfterFreezingPoint(fstream &x);
pair<double, double> avgBeforeandAfterFreezingPoint(fstream &x);

int main()
{

    int choice;
    do
    {
        cout << "0- Exit\n";
        cout << "1-Average of temps before the first freezing point\n";
        cout << "2-Average of temps after the first freezing point\n";
        cout << "3-Average of temps before and after the first freezing point\n";
        cout << "choose a number: ";
        cin >> choice;
        if (choice > 0 && choice < 4)
        {
            string fileName;
            cout << "Enter a fileName: ";
            cin >> fileName;
            fstream f(fileName);
            if (f.fail())
            {
                cout << "file doesn't exists\n";
                f.close();
            }
            else
            {
                switch (choice)
                {
                case 1:
                    cout << "Average of temps before the first freezing point: " << avgBeforeFreezingPoint(f) << endl;
                    break;
                case 2:
                    cout << "Average of temps after the first freezing point: " << avgAfterFreezingPoint(f) << endl;
                    break;
                case 3:
                    pair<double, double> res = avgBeforeandAfterFreezingPoint(f);
                    cout << "Average of temps before the first freezing point: " << res.first <<", after freezing point:"<<res.second<<endl;
                    break;
                }
            }
        }
        else
        {
            cout << "invalid choice\n";
        }

    } while (choice != 0);

    return 0;
}
double divide(double s, int c)
{
    if (c == 0)
    {
        return 0;
    }
    else
    {
        return s / c;
    }
}

void read(Status &st, double &e, fstream &x)
{

    x >> e;
    if (x.fail())
    {
        st = abnorm;
    }
    else
    {
        st = norm;
    }
}

double avgBeforeFreezingPoint(fstream &x)
{
    double sum = 0;
    int cnt = 0;
    Status st;
    double e;
    read(st, e, x);
    while (e >= 0 && st == norm)
    {
        sum += e;
        cnt++;
        read(st, e, x);
    }
    return divide(sum, cnt);
    // to avoid dividing by 0

    // alternative sol:
    //  return (cnt==0)?0:sum/cnt;
}
double avgAfterFreezingPoint(fstream &x)
{

    double sum = 0;
    int cnt = 0;
    Status st;
    double e;
    read(st, e, x);
    while (e >= 0 && st == norm)
    {
        read(st, e, x);
    }
    read(st, e, x);
    while (st == norm)
    {
        sum += e;
        cnt++;
        read(st, e, x);
    }
    return divide(sum, cnt);
}
pair<double, double> avgBeforeandAfterFreezingPoint(fstream &x)
{
    pair<double, double> results;
    double sum1 = 0;
    int cnt1 = 0;
    Status st;
    double e;
    read(st, e, x);
    while (e >= 0 && st == norm)
    {
        sum1 += e;
        cnt1++;
        read(st, e, x);
    }
    results.first = divide(sum1, cnt1);

    read(st, e, x);
    double sum2 = 0;
    int cnt2 = 0;
    while (st == norm)
    {
        sum2 += e;
        cnt2++;
        read(st, e, x);
    }
    results.second = divide(sum2, cnt2);

    return results;
}
