// ±¸ÇöÃþ.!!
// PointImpl.h
class PointImpl
{
	int x, y;
public:
	void printImpl();
};

// PointImpl.cpp
#include "PointImpl.h"

void PointImpl::print() { }
//======================================
// Bridge - Ãß»óÃþ
// Point.h
class Point
{
	Point* pImpl;
public:
	Point();
	void print();
};

// Point.cpp
#include "Point.h"

Point::Point() { pImpl = new PointImpl; }
void Point::print() { pImpl->pImpl(); }
//---------------------------------------





// main.cpp
#include "Point.h"
int main()
{
	Point p;
	p.print();
}


