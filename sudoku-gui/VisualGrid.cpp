#include "VisualGrid.h"
#include "Keypad.h"

#define VARIANT(x) (QVariant(x))


VisualGrid::VisualGrid(QWidget *parent) : QWidget(parent)
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
			layout->addWidget(buttons[row][col], row, col);
		}
	}

	for (int row{ 0 }; row < 3; row++)
	{
		for (int col{ 0 }; col < 3; col++)
		{
			padLayout->addWidget(keypad->buttons[row][col], row, col);
			connect(keypad->buttons[row][col], SIGNAL(clicked()), this, SLOT(setSquareValue()));
		}
	}
}

VisualGrid::~VisualGrid()
= default;

GridButton* VisualGrid::createGridButton(const int row, const int col)
{
	GridButton* button = new GridButton("0", this);

	button->setColProperty(col);
	button->setRowProperty(row);
	button->setFixedSize(50, 50);

	if(row % 3 == 2)
	{
		QFrame* line = new QFrame();
		line->setGeometry(QRect(320, 150, 118, 3));
		line->setFrameShape(QFrame::HLine);
		line->setFrameShadow(QFrame::Sunken);
		layout->addWidget(line);
	}

	return button;
}

QGridLayout * VisualGrid::getLayout() const
{
	return layout;
}

void VisualGrid::updateInterface()
{
	for(int row{0}; row < SIZE; row++)
	{
		for (int col{0}; col < SIZE; col++)
		{
			int selected = grid[row][col];
			GridButton* button = buttons[row][col];
			if (selected != 0) {
				button->setDisplayedValueProperty(std::to_string(selected));
				button->setStaticSquare(false);
			} else {
				button->setDisplayedValueProperty(std::to_string(selected));
			}
		}
	}
}

void VisualGrid::setSquareValue()
{
	QPushButton* padButton = qobject_cast<QPushButton*>(sender());
	const QVariant value = padButton->property("digit");

	if (setInput(value.toInt()))
	{
		buttons[selected.row][selected.col]->setText(value.toString());
	}
}

void VisualGrid::clearSelectedButton()
{
	for (int row{0}; row < SIZE; row++)
	{
		for (int col{0}; col < 9; col++)
		{
			if (!buttons[row][col]->getStaticProperty())
			{
				buttons[row][col]->setSelected(false);
				buttons[row][col]->setSelectedBackground(false);
			}
			
		}
	}
}

void VisualGrid::setSelected()
{
	clearSelectedButton();

	GridButton* button = qobject_cast<GridButton*>(sender());

	setSelectedSquare(button->getRowProperty(), button->getColProperty());
	button->toggleSelected();
}
