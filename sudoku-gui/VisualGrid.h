#pragma once

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QVariant>

#include "GridWrapper.h"

class VisualGrid : public QWidget, public GridWrapper
{
	Q_OBJECT
public:
	VisualGrid(QWidget *parent = Q_NULLPTR);
	~VisualGrid();

	QPushButton* createGridButton(int row, int col);
	QGridLayout* getLayout();
private slots:
	void setSelected();
private:
	QGridLayout * layout;
	QPushButton * buttons[9][9];
};

