#include "pch.h"
#include "../sudoku-gui/GridCore.h"

struct GridTest : testing::Test
{
	GridCore* grid;


	GridTest()
	{
		grid = new GridCore(1);
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