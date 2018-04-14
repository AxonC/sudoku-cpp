#include "VisualGrid.h"
#include "Keypad.h"

VisualGrid::VisualGrid(QWidget *parent): QWidget(parent)
{
	vLayout = new QVBoxLayout(parent);
	layout = new QGridLayout(parent);
	padLayout = new QGridLayout(parent);

	vLayout->addLayout(layout);
	vLayout->addLayout(padLayout);

	Keypad* keypad = new Keypad(parent);

	for (int row{ 0 }; row < 9; row++)
	{
		for (int col{ 0 }; col < 9; col++)
		{
			buttons[row][col] = createGridButton(row, col);
			connect(buttons[row][col], SIGNAL(clicked()), this, SLOT(setSelected()));
		}
	}

	for (int row{ 0 }; row < 9; row++)
	{
		for (int col{ 0 }; col < 9; col++)
		{
			layout->addWidget(buttons[row][col], row, col);
		}
	}

	for (int row{ 0 }; row < 3; row++)
	{
		for (int col{ 0 }; col < 3; col++)
		{
			padLayout->addWidget(keypad->buttons[row][col], row, col);
		}
	}
}


VisualGrid::~VisualGrid()
{}

QPushButton* VisualGrid::createGridButton(int row, int col)
{
	QPushButton* button = new QPushButton("0", this);

	button->setProperty("row", QVariant(row));
	button->setProperty("col", QVariant(col));
	button->setFixedSize(40, 40);

	return button;
}

QGridLayout * VisualGrid::getLayout()
{
	return layout;
}

void VisualGrid::setSelected()
{
	QPushButton* button = qobject_cast<QPushButton*>(sender());
	QVariant row = button->property("row");

	button->setText(row.toString());
}
