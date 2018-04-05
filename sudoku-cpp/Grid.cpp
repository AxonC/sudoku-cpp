#pragma once
#include "stdafx.h"
#include "Grid.h"
#include "Point.h"
#include <iostream>
#include <fstream>
#include <iomanip>

Grid::Grid(int difficulty)
{
	difficulty = difficulty;

	for (int x{ 0 }; x < SIZE; x++)
	{
		for (int y{ 0 }; y < SIZE; y++)
		{
			grid[x][y] = 0;
		}
	}
		

	for (int z{ 0 }; z < SIZE; z++)
	{
		for (int a{ 0 }; a < SIZE; a++)
		{
			for (int b{ 0 }; b < SIZE; b++)
			{
				memos[z][a] = { 0 };
			}
		}
	}
		
			
}

Grid::~Grid()
{}

bool Grid::setInput(std::string coordinate, int value)
{
	bool index = gridToIndex(coordinate);
	if (validateInput(value) && index)
	{
		if (!rowChecker(selected.row, value) && !colChecker(selected.col, value))
		{
			grid[selected.row][selected.col] = value;
		}
	}

	return false;
}

void Grid::displayGrid()
{	
	for (int i{ 0 }; i < SIZE; i++)
	{
		for (int j{ 0 }; j < SIZE; j++)
		{
			if (j % 9 == 0)
			{
				std::cout << "\n";
			}
			
			std::cout << std::setw(10) << grid[i][j];
		}
	}
	std::cout << std::endl;
}

int Grid::gridToIndex(std::string coordinate)
{
	Point pointConversion(coordinate);

	if (pointConversion.isValid())
	{
		selected.col = pointConversion.col;
		selected.row = pointConversion.row;

		return true;
	}
	else
	{
		return false;
	}
}

bool Grid::rowChecker(int row, int value)
{
	bool foundFlag{ false };

	for (int i = 0; i < SIZE; i++)
		if (grid[row][i] == value)
			foundFlag = true;

	return foundFlag;
}

bool Grid::colChecker(int index, int value)
{
	bool foundFlag{ false };

	for (int i = 0; i < SIZE; i++)
		if (grid[i][index] == value)
			foundFlag = true;

	return foundFlag;
}

bool Grid::setMemo(int row, int col, int value)
{
	memos[row][col] = true;

	return true;
}

bool Grid::removeMemo(int row, int col, int value)
{
	memos[row][col] = false;

	return true;
}

bool Grid::loadFromFile(std::string filename)
{
	std::ifstream gridFile(filename);

	if (gridFile) {
		for (int x{ 0 }; x < SIZE; x++)
		{
			for (int y{ 0 }; y < SIZE; y++)
			{
				gridFile >> grid[x][y];
			}
		}
		return true;
	} else {
		return false;
	}
}

bool Grid::validateInput(int input)
{
	if (input <= 9 && input >= 1)
		return true;

	return false;
}
