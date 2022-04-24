#pragma once

#include <vector>

class Entry ///interface
{
/*    private:
        Entry() {}*/
    public:
        virtual int getSize() const = 0;
        virtual ~Entry(){}
};

class File : public Entry
{
    public:
        File(int s) : _size(s) {};
        void setSize(int s) { _size = s; }
        int getSize() const override { return _size;}
    private:
        int _size;
};

class Library : public Entry
{
    public:
        ~Library() {
            for( Entry *f : _content ) delete f;
        }
        void add(Entry* r) { _content.push_back(r); }
        int getSize() const override {
            int sum = 0;
            for(Entry* r : _content){
                sum += r->getSize();
            }
            return sum;
        }
    protected:
        std::vector<Entry*> _content;
};

class FileSystem : public Library { };
