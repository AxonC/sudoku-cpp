#pragma once
#include <string>

class Point
{
public:
	Point(std::string coordinate);
	~Point();

	int row;
	int col;

	bool isValid();
	bool convert(std::string coord);
};

