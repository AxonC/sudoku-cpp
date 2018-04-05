#include "stdafx.h"
#include "Point.h"

const int ASCII_A = 'A';

Point::Point(std::string coordinate)
{
	convert(coordinate);
}

Point::~Point()
{

}

bool Point::isValid()
{
	if (row >= 0 && row <= 9)
		if (col >= 0 && row <= 9)
			return true;

	return false;
}

bool Point::convert(std::string coord)
{
	int firstElement = toupper(coord[0]);

	if (firstElement - ASCII_A > 9 || firstElement - ASCII_A < 0)
		return false;

	row = firstElement - ASCII_A;

	int secondElement = coord[1];

	if (secondElement >= '1' || secondElement <= '9');
		col = secondElement - '1';

	return (isValid()) ? true : false;
}
