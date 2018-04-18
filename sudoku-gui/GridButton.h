#pragma once
//#include <QString>
#include <string>
#include <QPushButton>

class GridButton : public QPushButton
{
	Q_OBJECT
public:
	explicit GridButton(const QString &text, QWidget *parent = Q_NULLPTR);
	explicit GridButton(const QString &text);
	~GridButton();

	bool toggleActive();
	void toggleActiveBackground();

	void setRowProperty(int givenRow);
	int getRowProperty() const;

	void setColProperty(int givenColumn);
	int getColProperty() const;

	void setDisplayedValueProperty(std::string value);

	void setActiveProperty(bool property);

	void setStaticSquare();

	static bool propertyValidator(int property);	
private:
	const QColor QT_BLACK = Qt::black;
	const QColor QT_WHITE = Qt::white;
	const QString QT_BOLD = QString("font-weight: 700;");
	int row;
	int col;
	bool active;
	bool staticSquare;
	std::string displayedValue;
};

