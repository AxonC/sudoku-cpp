#include "Window.h"
#include "Keypad.h"
#include "VisualGrid.h"


Window::Window(QWidget *parent) : QMainWindow(parent)
{
	//for (int row{ 0 }; row < 9; row++)
	//{
	//	for (int col{ 0 }; col < 9; col++)
	//	{
	//		buttons[row][col] = createGridButton(row, col);
	//		connect(buttons[row][col], SIGNAL(clicked()), &base, SLOT(setSelected()));
	//	}
	//}
/*
	createGameLayout();*/

	VisualGrid grid = new VisualGrid(&base);

	//Keypad keypad = new Keypad(&base);

	//Keypad* keypad = new Keypad(&base);
	//
	//verticalLayout->addWidget(keypad);

	//verticalLayout->addLayout(keypad->getLayout());

	setCentralWidget(&base);
}

QGridLayout* Window::createGameLayout()
{
	QGridLayout* layout = new QGridLayout(&base);

	for (int row{ 0 }; row < 9; row++)
	{
		for (int col{ 0 }; col < 9; col++)
		{
			layout->addWidget(buttons[row][col], row, col);
		}
	}

	return layout;
}

QPushButton* Window::createGridButton(int row, int col)
{
	QPushButton* button = new QPushButton("0", &base);

	button->setProperty("row", QVariant(row));
	button->setProperty("col", QVariant(col));
	button->setFixedSize(40, 40);

	return button;
}
