// sudoku-cpp.cpp : Defines the entry point for the console application.
//
#pragma once
#include "stdafx.h"
#include <iostream>
#include "Grid.h"
#include "Point.h"


int main()
{
	Point newPoint("a0");

	Grid newGrid(3);

	newGrid.loadFromFile("grid.txt");

	newGrid.displayGrid();

	int value;
	std::string reference;

	std::cout << "Enter the Grid Ref" << std::endl;
	std::cin >> reference;

	std::cout << "Enter the Value" << std::endl;
	std::cin >> value;

	newGrid.setInput(reference, value);

	newGrid.displayGrid();
}

