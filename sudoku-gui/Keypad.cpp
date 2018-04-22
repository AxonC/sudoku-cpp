#pragma once

#include "Keypad.h"

Keypad::Keypad(QWidget *parent): QWidget(parent)
{
	const int displayMatrix[][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };

	for (int row{ 0 }; row < 3; row++)
	{
		for (int col{ 0 }; col < 3; col++)
		{
			const int number = displayMatrix[row][col];
			const QString text = QString::number(number);
			QPushButton* button = new QPushButton(text, parent);
			button->setText(text);
			button->setProperty("digit", QVariant(number));
			button->setStyleSheet("background-color: rgb(188, 15, 15); color: white; font-weight: 700; padding: 1em;");

			buttons[row][col] = button;
		}
	}
}

Keypad::~Keypad()
= default;