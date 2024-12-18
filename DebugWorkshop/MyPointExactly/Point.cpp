#include "Point.h"
#include <iostream>

Point::Point()
{
	_coord = new int[2];
	_coord[0] = _coord[1] = 0;  // Allocates a dynamic array of size 2 and initializes it to 0
}

Point::Point(int x, int y)
{
	_coord = new int[2];  // Allocates a dynamic array of size 2 and initializes it to the given values (x and y)
	_coord[0] = x;
	_coord[1] = y;
}

Point::Point(const Point& other)
{
	delete _coord;
	_coord = other._coord;     // copy constractor
}

Point::~Point()
{
	delete _coord;   // destractor
}

Point& Point::operator=(const Point& other)
{
	delete this->_coord;
	this->_coord = new int[2];
	this->_coord[0] = other._coord[0];
	this->_coord[1] = other._coord[1];
	//             dest,   source,    size
	//memcpy(this->_coord, other._coord, 2);      // copy operator
	return *this;
}

int Point::getX() const 
{ 
	return _coord[0];   //  Returns the first element in the array
}

int Point::getY() const
{ 
	return _coord[1];   // Returns the second element in the array
}


std::ostream& operator<<(std::ostream& os, const Point& p)
{
	os << "(" << p._coord[0] << "," << p._coord[1] << ")";
	return os;
}
