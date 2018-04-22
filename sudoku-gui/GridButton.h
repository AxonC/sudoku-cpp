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

	bool toggleSelected();
	void toggleSelectedBackground();
	void setSelectedBackground(bool status);

	void setSelected(bool status);

	void setRowProperty(int givenRow);
	int getRowProperty() const;

	void setColProperty(int givenColumn);
	int getColProperty() const;

	void setDisplayedValueProperty(std::string value);

	void setStaticSquare(bool status);
	bool getStaticProperty() const;

	static bool propertyValidator(int property);	
private:
	const QColor QT_BLACK = Qt::black;
	const QColor QT_WHITE = Qt::white;
	const QString QT_BOLD = QString("font-weight: 700;");
	int row;
	int col;
	bool selected;
	bool staticSquare;
	std::string displayedValue;
};

