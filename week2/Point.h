#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

//#pragma once

#include <cmath>
#include <sstream>

class Point
{
    private:
        double _x, _y;
        //_-> is just convention

    public:
        Point(double a = 0, double b = 0) : _x(a),_y(b) {
//            _x=a;
//            _y=b;


            }
            //constructor -> constructs Objects
            //object-> instance of a class
        double distance(const Point &p) const {
            return sqrt(pow(_x-p._x,2) + pow(_y-p._y,2));
        }
        double getX() const {return _x;}
        double getY() const {return _y;}
        //getters ->  double getX() const {return _x;}
        //setters-> void getX(double x){_x=x;}

        std::string toString() const
        {
            std::stringstream ss;
            ss << "("<<_x<<","<<_y<<")";
            return ss.str();
        }


};



#endif // POINT_H_INCLUDED
