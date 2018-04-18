#include "GridButton.h"

GridButton::GridButton(const QString &text, QWidget * parent) : QPushButton(text, parent)
{
	active = true;

	displayedValue = text.toStdString();
}

GridButton::GridButton(const QString &text): QPushButton(text, Q_NULLPTR)
{
	active = true;

	displayedValue = text.toStdString();
}

GridButton::~GridButton(){};

bool GridButton::toggleActive()
{
	active = !active;

	return active;
}

void GridButton::toggleActiveBackground()
{
	if(!active) {
		this->setStyleSheet(styleSheet());
	} else {
		const QString style = QString("background-color: %1; color: %2; border: none;").arg(QT_BLACK.name()).arg(QT_WHITE.name());
		this->setStyleSheet(style);
	}
}

void GridButton::setRowProperty(int givenRow)
{
	if (propertyValidator(givenRow))
	{
		row = givenRow;
	}
}

int GridButton::getRowProperty() const
{
	return row;	
}

void GridButton::setColProperty(int givenColumn)
{
	if (propertyValidator(givenColumn))
	{
		col = givenColumn;
	}
}

int GridButton::getColProperty() const
{
	return col;
}

void GridButton::setDisplayedValueProperty(std::string value)
{
	displayedValue = value;

	this->setText(QString::fromStdString(displayedValue));
}

void GridButton::setActiveProperty(bool property)
{
	active = property;

	if (!active)
	{
		this->setDisabled(true);
		this->setStyleSheet(QT_BOLD);
	}
}

bool GridButton::propertyValidator(int property)
{
	return property < 9 && property >= 0;
}
