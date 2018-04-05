#pragma once
#include<string>

const int SIZE = 9;

struct Memo {
	bool value[SIZE] = { 0 };
};

struct SelectedSquare {
	int row;
	int col;
};

class Grid
{
public:
	Grid(int difficulty);
	~Grid();
	
	bool setInput(std::string coordinate, int value);
	void displayGrid();
	int gridToIndex(std::string coordinate);
	bool rowChecker(int row, int value);
	bool colChecker(int index, int value);
	bool setMemo(int row, int col, int value);
	bool removeMemo(int row, int col, int value);
	bool loadFromFile(std::string filename);
protected:
	bool validateInput(int input);
private:
	int difficulty;
	int grid[SIZE][SIZE];
	bool memos[SIZE][SIZE];
	SelectedSquare selected;
};

