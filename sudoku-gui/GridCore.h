#pragma once
#include <string>
#include <vector>

const int SIZE = 9;

#define SUDOKUSIZE 9;

struct Memo {
	bool value[SIZE] = { false };
};

struct SelectedSquare {
	int row;
	int col;
};

struct SubGrid {
	int rows[3];
	int cols[3];
};

class GridCore
{
public:
	explicit GridCore();
	~GridCore();

	bool setInput(int value);
	bool rowChecker(int row, int value);
	bool colChecker(int index, int value);
	bool subGridChecker(SubGrid subGrid, int value);
	bool setMemo(int row, int col, int value);
	bool removeMemo(int row, int col, int value);
	bool loadFromFile(std::string filename);
	static bool validateInput(int input);
	SelectedSquare setSelectedSquare(int row, int col);
	SelectedSquare getSelectedSquare() const;
	void defineSubGrids();
	SubGrid searchForSubGrid(int row, int col) const;
	SubGrid getGridDefinition(int index);
	bool getGridSetupStatus() const;
	bool addDisallowedNumber(int number);
	bool clearDisallowedNumber() const;
	std::vector<int> getDisallowedNumbers() const;
	bool checkSolution();
protected:
	SelectedSquare selected;
	int grid[SIZE][SIZE];
	std::vector<int> disallowedNumbers;
private:
	bool memos[SIZE][SIZE];
	int solution[SIZE][SIZE];
	SubGrid subGrids[9];
	bool subGridsDefined;
	bool gridSetup;
	std::string puzzleName;
};


