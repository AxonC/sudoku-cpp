#include "GridButton.h"

GridButton::GridButton(const QString &text, QWidget * parent) : QPushButton(text, parent)
{
	selected = true;

	staticSquare = false;

	displayedValue = text.toStdString();
}

GridButton::GridButton(const QString &text): QPushButton(text, Q_NULLPTR)
{
	selected = false;
	
	staticSquare = false;

	displayedValue = text.toStdString();
}

GridButton::~GridButton() = default;;

bool GridButton::toggleSelected()
{
	selected = !selected;

	this->toggleSelectedBackground();

	return selected;
}

void GridButton::toggleSelectedBackground()
{
	if(!selected) {
		this->setStyleSheet("");
	} else {
		const QString style = QString("background-color: %1; color: %2; border: none;").arg(QT_BLACK.name()).arg(QT_WHITE.name());
		this->setStyleSheet(style);
	}
}

void GridButton::setSelectedBackground(bool status)
{
	if(!staticSquare)
	{
		if (!status) {
			this->setStyleSheet("");
		} else {
			const QString style = QString("background-color: %1; color: %2; border: none;").arg(QT_BLACK.name()).arg(QT_WHITE.name());
			this->setStyleSheet(style);
		}
	}
	
}

void GridButton::setRowProperty(const int givenRow)
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

void GridButton::setDisplayedValueProperty(const std::string value)
{
	displayedValue = value;

	this->setText(QString::fromStdString(displayedValue));
}

void GridButton::setStaticSquare(const bool status)
{
	staticSquare = status;

	if(!staticSquare)
	{
		this->setEnabled(staticSquare);
		this->setStyleSheet(QT_BOLD);
	}
}

bool GridButton::getStaticProperty() const
{
	return staticSquare;
}

void GridButton::setSelected(const bool status)
{
	selected = status;
}

bool GridButton::propertyValidator(const int property)
{
	return property < 9 && property >= 0;
}
