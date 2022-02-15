#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


bool readFile(vector<int>&x,const string &fileName);
bool condMaxSearch(const vector<int>&x, int &max, int &ind);
bool condMaxSearchFromFile(int &max,const string &fileName);



int main()
{

    vector<int>x;
    string fileName;
    cout<<"Enter a file Name: ";
    cin>>fileName;
    if(readFile(x,fileName))
    {
        int max;
        int ind;
        if(condMaxSearch(x,max,ind)){
            cout<<"highest valley is " << max<<endl;

        }else{
            cout<<"no valley is matching the search "<<endl;
        }
    cout<<"second approach----------"<<endl;
        if(condMaxSearchFromFile(max,fileName)){
        cout<<"highest valley is " << max<<endl;

        }else{
            cout<<"no valley is matching the search "<<endl;
        }

    }
    else
    {
        cout<<"file doesn't exists"<<endl;

    }



    return 0;
}

bool readFile(vector<int>&x,const string &fileName)
{

    fstream f(fileName);
    if(f.fail()) return false;

    int e;
    x.clear();
    while(f>>e)
    {
        x.push_back(e);
    }
    f.close();

    return true;



}

bool condMaxSearch(const vector<int>&x, int &max, int &ind)
{

    bool L = false;
    for(int i = 1; i < int(x.size())-1; i++)
    {

//        if(!(x[i-1]>=x[i]&&x[i]<=x[i+1])){
//
//            //skip
//
//        }


        if(L&&x[i-1]>=x[i]&&x[i]<=x[i+1])
        {
            if(max<x[i])
            {
                max=x[i];
                ind=i;
            }

        }
        else if(!L&&x[i-1]>=x[i]&&x[i]<=x[i+1])
        {
            L=true;
            max=x[i];
            ind = i;

        }

    }

    return L;


}
//second approach
bool condMaxSearchFromFile(int &max,const string &fileName){

    fstream f(fileName);
    bool L = false;
    int before;
    int  current;
    int after;
    f>>before;
    f>>current;
    f>>after;
    while(!f.fail()){
        if(L&&before>=current&&current<=after)
        {
            if(max<current)
            {
                max=current;

            }

        }
        else if(!L&&before>=current&&current<=after)
        {
            L=true;
            max=current;


        }
        before=current;
        current=after;
        f>>after;



    }
    f.close();

    return L;


}


