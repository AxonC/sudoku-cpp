#include "pch.h"
#include "../sudoku-gui/GridCore.h"

struct GridTest : testing::Test
{
	GridCore* grid;


	GridTest()
	{
		grid = new GridCore();
	}

	~GridTest()
	{
		delete grid;
	}
};

TEST_F(GridTest, InputMustBeInRange)
{
	EXPECT_EQ(true, grid->validateInput(1));
	EXPECT_EQ(false, grid->validateInput(10));
}

TEST_F(GridTest, DontAllowMultipleOfSameNumberOnRow)
{
	grid->setSelectedSquare(0, 0);
	grid->setInput(9);
	// if found, return value will be true
	EXPECT_EQ(true, grid->rowChecker(grid->getSelectedSquare().row, 9));
}

TEST_F(GridTest, DontAllowMultipleOfSameNumberOnCol)
{
	grid->setSelectedSquare(0, 0);
	grid->setInput(9);
	// if found, return value will be true
	EXPECT_EQ(true, grid->colChecker(grid->getSelectedSquare().col, 9));
}

TEST_F(GridTest, GridCheckerTrueIfFound)
{
	SubGrid subGrid = { { 0, 1, 2 }, { 0, 1, 2 } };

	grid->setSelectedSquare(0, 1);
	grid->setInput(9);

	EXPECT_EQ(true, grid->subGridChecker(subGrid, 9));
}

TEST_F(GridTest, SubGridSearcher)
{
	SelectedSquare gridSelection = { 8, 8 };

	EXPECT_EQ(grid->getGridDefinition(8).rows[0], grid->searchForSubGrid(8, 8).rows[0]);
	EXPECT_EQ(grid->getGridDefinition(8).rows[1], grid->searchForSubGrid(8, 8).rows[1]);
	EXPECT_EQ(grid->getGridDefinition(8).rows[2], grid->searchForSubGrid(8, 8).rows[2]);
}