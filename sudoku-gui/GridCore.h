#pragma once
#include <string>

const int SIZE = 9;

struct Memo {
	bool value[SIZE] = { 0 };
};

struct SelectedSquare final {
	int row;
	int col;
};

class GridCore
{
public:
	GridCore(int difficulty);
	~GridCore();

	bool setInput(int value);
	void displayGrid();
	bool rowChecker(int row, int value);
	bool colChecker(int index, int value);
	bool setMemo(int row, int col, int value);
	bool removeMemo(int row, int col, int value);
	bool loadFromFile(std::string filename);
	SelectedSquare setSelectedSquare(int col, int row);
protected:
	bool validateInput(int input);
	SelectedSquare selected;
private:
	int difficulty;
	int grid[SIZE][SIZE];
	bool memos[SIZE][SIZE];
};


