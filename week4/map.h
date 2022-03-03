#ifndef PRIORSOR_H_INCLUDED
#define PRIORSOR_H_INCLUDED
#include <string>
#include <iostream>
#include <vector>
#include "read.hpp"
#include <exception>

///function for controlled data reading
///To avoid multiple declaration, it is inline.
inline bool valid(int a){return true;}

struct Item
{
    ///public attributes
    int key;
    std::string data;

    ///constructors
    Item() {};
    Item(int key,std::string data):key(key), data(data) {}

    friend std::istream& operator>>(std::istream& s, Item& e)
    {
        e.key=read<int>("Key: ","Integer is needed!",valid);
        std::cout<<"Data: ";
        s>>e.data;
        return s;
    }
    friend std::ostream& operator<<(std::ostream& s, const Item& e)
    {
        s<<"("<<e.key<<","<<e.data<<")";
        return s;
    }

    ///for testing
    bool operator==(const Item& b)
    {
        return (key==b.key && data==b.data);
    }
};

class Map
{
    public:
        class ExistingKeyException : public std::exception {};
        class NonExistingKeyException : public std::exception {};


        ///Map(); //Not needed
        ///~Map() {} //Not needed
        int count() const {return _vec.size();}
        void insert(Item a) throw (std::exception);
        void erase(int key) throw (std::exception);
        bool isIn(int key) const;
        
        std::string &operator [](int key)  throw (std::exception);
        bool isEmpty() const {return _vec.size()==0;}

        friend std::ostream& operator<<(std::ostream& s, const Map& m); ///print a line

        ///Methods for testing
        std::vector<Item> getItems() const;
        
        std::pair<bool,int> getLogSearch(int key) const {return logSearch(key);}

    private:
        std::vector<Item> _vec; ///array implemented as a vector

        std::pair<bool,int> logSearch(int key) const;

};


#endif // PRIORSOR_H_INCLUDED
