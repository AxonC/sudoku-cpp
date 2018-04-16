#pragma once

#include "GridCore.h"
#include <iostream>
#include <fstream>
#include <iomanip>

GridCore::GridCore()
{
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

	selected = { 0, 0 };

	subGridsDefined = false;

	defineSubGrids();
}

GridCore::~GridCore()
= default;

bool GridCore::setInput(const int value)
{
	if (validateInput(value))
	{
		if (!rowChecker(selected.row, value) 
			&& !colChecker(selected.col, value) 
			&& !subGridChecker(searchForSubGrid(selected.row, selected.col), value))
		{
			grid[selected.row][selected.col] = value;
			return true;
		}
	}

	return false;
}

bool GridCore::rowChecker(int row, int value)
{
	bool foundFlag{ false };

	for (int i = 0; i < SIZE; i++)
		if (grid[row][i] == value)
			foundFlag = true;

	return foundFlag;
}

bool GridCore::colChecker(int index, int value)
{
	bool foundFlag{ false };

	for (int i = 0; i < SIZE; i++)
		if (grid[i][index] == value)
			foundFlag = true;

	return foundFlag;
}

bool GridCore::subGridChecker(SubGrid subGrid, int value)
{
	bool foundFlag{ false };

	for(int row{0}; row < 3; row++)
	{
		for (int col{0}; col < 3; col++)
		{
			if (grid[subGrid.rows[row]][subGrid.cols[col]] == value)
			{
				foundFlag = true;
				break;
			}
		}
	}

	return foundFlag;
}

bool GridCore::setMemo(int row, int col, int value)
{
	memos[row][col] = true;

	return true;
}

bool GridCore::removeMemo(int row, int col, int value)
{
	memos[row][col] = false;

	return true;
}

bool GridCore::loadFromFile(std::string filename)
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
	}
	return false;
}

SelectedSquare GridCore::setSelectedSquare(int row, int col)
{
	selected.row = row;
	selected.col = col;

	return selected;
}

SelectedSquare GridCore::getSelectedSquare() const
{
	return selected;
}

void GridCore::defineSubGrids()
{
	subGrids[0] = { {0, 1, 2}, {0, 1, 2} };
	subGrids[1] = { {0, 1, 2}, {3, 4, 5} };
	subGrids[2] = { {0, 1, 2}, {6, 7, 8} };
	subGrids[3] = { {3, 4, 5}, {0, 1, 2} };
	subGrids[4] = { {3, 4, 5}, {3, 4, 5} };
	subGrids[5] = { {3, 4, 5}, {6, 7, 8} };
	subGrids[6] = { {6, 7, 8}, {0, 1, 2} };
	subGrids[7] = { {6, 7, 8}, {3, 4, 5} };
	subGrids[8] = { {6, 7, 8}, {6, 7, 8} };

	subGridsDefined = true;
}

SubGrid GridCore::searchForSubGrid(int row, int col) const
{
	int gridIndex;

	if(subGridsDefined)
	{
		for (int grid{ 0 }; grid < SIZE; grid++)
		{
			const SubGrid selectedGrid = subGrids[grid];
			for (int column{0}; column < 3; column++)
			{
				for (int row_i{ 0 }; row_i < 3; row_i++)
				{
					if (selectedGrid.rows[row_i] == row && selectedGrid.cols[column] == col)
					{
						return selectedGrid;
					}
				}
			}
		}
	}
}

SubGrid GridCore::getGridDefinition(int index)
{
	if (subGridsDefined)
	{
		return subGrids[index];
	}
}

bool GridCore::validateInput(int input)
{
	return input <= 9 && input >= 1;
}

