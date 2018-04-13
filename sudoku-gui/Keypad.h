#pragma once

#include <QGridLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QPushButton>

class Keypad : public QWidget
{
	Q_OBJECT

public:
	Keypad(QWidget *parent = Q_NULLPTR);
	~Keypad();

	int displayMatrix[3][3];
	void resetAvailableButtons();
	QPushButton* setAvailableButtons(int * numbers);
	QPushButton* getAvailableButtons();
	QGridLayout* getLayout();

private:
	QPushButton* buttons[3][3];
	QGridLayout* layout;
};

