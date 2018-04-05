#pragma once
class InputChecker
{
public:
	InputChecker(int input);
	InputChecker(float input);
	~InputChecker();

	virtual bool checkInput();
private:
	int input;
};

