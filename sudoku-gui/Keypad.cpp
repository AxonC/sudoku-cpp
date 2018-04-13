#include "Keypad.h"

#include <QVariant>

Keypad::Keypad(QWidget *parent): QWidget(parent)
{
	const int displayMatrix[][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };

	QGridLayout* layout = new QGridLayout();

	// creates boolean arrray for those numbers which are available.

	for (int row{ 0 }; row < 10; row++)
	{
		for (int col{ 0 }; col < 3; col++)
		{
			int number = displayMatrix[row][col];
			QString text = QString::number(number);
			QPushButton* button = new QPushButton(text);
			button->setText(text);
			button->setProperty("digit", QVariant(number));

			buttons[row][col] = button;
		}
	}

	for (int row{ 0 }; row < 3; row++)
	{
		for (int col{ 0 }; col < 3; col++)
		{
			layout->addWidget(buttons[row][col], row, col);
		}
	}
}


Keypad::~Keypad()
{
	delete buttons;
}

QGridLayout * Keypad::getLayout()
{
	return layout;
}

//void Keypad::resetAvailableButtons()
//{
//	for (int i{ 0 }; i < 10; i++)
//	{
//		available[i] = true;
//	}
//}
//
//QPushButton * Keypad::getAvailableButtons()
//{
//	return *buttons;
//}

//QPushButton * Keypad::setAvailableButtons(int * numbers)
//{
//	int * available;
//	int numberSet[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	// Parameter passed should include those which are available.
//	// based upon results of col, row and sq checks, eliminate numbers which are already present.
//
//	for (int i{ 1 }; i < 10; i++)
//	{
//
//	}
//
//	return 
//}
