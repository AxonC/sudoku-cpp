#pragma once

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QVariant>
#include <memory>

#include "GridCore.h"

class VisualGrid : public QWidget, public GridCore
{
	Q_OBJECT
public:
	VisualGrid(QWidget *parent = Q_NULLPTR);
	~VisualGrid();

	QPushButton* createGridButton(int row, int col);
	QGridLayout* getLayout();
	
private slots:
	void setSelected();
	void setSquareValue();
private:
	QGridLayout * layout;
	QGridLayout * padLayout;
	QVBoxLayout * vLayout;
	QPushButton * buttons[9][9];
};

