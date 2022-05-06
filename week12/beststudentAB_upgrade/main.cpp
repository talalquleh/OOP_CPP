#include <iostream>
#include "library/enumerator.hpp"
#include "library/linsearch.hpp"
#include "library/maxsearch.hpp"
#include "library/counting.hpp"
#include "library/seqinfileenumerator.hpp"
#include "library/stringstreamenumerator.hpp"

/// Fájlban: hallgató egy szavas neve+tárgy egy szavas neve+(komment,jegy) párosok, amiket a hallgató abból a tárgyból szerzett
/// egy hallgatóhoz több tárgy is tartozik
/// a fájl hallgatók szerint rendezett

/// Kérdés: Melyik hallgató végezte el a legkevesebb tárgyat (minden jegye legalább 2)?
/// Én ezt úgy oldottam meg, hogy megszámoltam azokat a tárgyakat, ahol minden jegy leaglább kettes, majd egy minimum a darabszámra (opt. lin. ker.+ számlálás + min. ker.).
/// Más megoldás is lehetséges, de ebben 3 fajta tételre is rá lehet nézni.

using namespace std;

struct Mark
{
    string comment;
    int grade;
    friend istream& operator>>(istream &is, Mark &m)
    {
        is >> m.comment >> m.grade;
        return is;
    }
};

class CoursePass : public LinSearch<Mark,true>
{
    bool cond(const Mark& e) const override { return e.grade >= 2; }
};

struct Course
{
    string name;
    string course;
    bool passed;
    friend istream& operator>>(istream &is, Course &c);
};

istream& operator>>(istream &is, Course &c)
{
    string str;
    getline(is, str);
    stringstream ss(str);
    ss >> c.name >> c.course;
    CoursePass pr;
    StringStreamEnumerator<Mark> ssenor(ss);
    pr.addEnumerator(&ssenor);
    pr.run();
    c.passed = pr.found();
    return is;
}

class countPassed : public Counting<Course>
{
private:
    string _name;
public:
    countPassed(const string &studentName) : _name(studentName) {}
protected:
    bool cond(const Course& e) const override { return e.passed; }
    bool whileCond(const Course &e) const override { return e.name == _name; }
    void first() override {}
};

struct Student
{
    string name;
    int noOfPassed;
};

class StudentEnumerator : public Enumerator<Student>
{
private:
    SeqInFileEnumerator<Course>* _f;
    Student _student;
    bool _end;
public:
    StudentEnumerator(const string &fname) { _f = new SeqInFileEnumerator<Course>(fname); }
    ~StudentEnumerator() { delete _f; }
    void first() override { _f->first(); next(); }
    void next() override;
    Student current() const override { return _student; }
    bool end() const override { return _end; }
};

void StudentEnumerator::next()
{
    if (_end = _f->end()) return;
    _student.name = _f->current().name;
    countPassed pr(_student.name);
    pr.addEnumerator(_f);
    pr.run();
    _student.noOfPassed = pr.result();
}

class minPassing : public MaxSearch<Student,int,Less<int>>
{
    virtual int func(const Student& e) const override { return e.noOfPassed; }
};

int main()
{
    try
    {
        minPassing pr;
        StudentEnumerator stenor("input.txt");
        pr.addEnumerator(&stenor);
        pr.run();
        cout << "The students who passed the least courses: "<< pr.optElem().name <<" ("<<pr.opt()<<" courses).\n";
    }
    catch (SeqInFileEnumerator<Course>::Exceptions exc)
    {
        cout << "File not found.\n";
    }
    return 0;
}
