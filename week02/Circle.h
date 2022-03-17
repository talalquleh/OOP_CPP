#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED

#include "point.h"


class Circle
{
    private:
        Point _cp;
        double  _r;
    //private -> can be accessed inside the class only
    public:
        class WrongRadiusException : public std::exception {};
        Circle(){}
        Circle(const Point &p, double d) : _cp(p), _r(d)
        {
            if (_r < 0) throw WrongRadiusException();//invariant
        }
        bool in(const Point &p) const {
            return _cp.distance(p) <= _r;
        }
          //public -> can be accessed outside the class
};

#endif // CIRCLE_H_INCLUDED
