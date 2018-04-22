#pragma once

#include <QVariant>
#include <QPushButton>


class Keypad : public QWidget
{
	Q_OBJECT
public:
	Keypad(QWidget *parent = Q_NULLPTR);
	~Keypad();

	int displayMatrix[3][3];
	QPushButton* buttons[3][3];
private:
	bool available[3][3];
};

