#pragma once

#include <QGridLayout>
#include <QPainter>
#include <QFileDialog>
#include <QMainWindow>
#include <QFrame>

#include "GridCore.h"
#include "GridButton.h"

class VisualGrid : public QWidget, public GridCore
{
	Q_OBJECT
public:
	VisualGrid(QWidget *parent = Q_NULLPTR);
	~VisualGrid();

	GridButton* createGridButton(int row, int col);
	QGridLayout* getLayout() const;
	void updateInterface();
	static QFileDialog createFileDialog();
	void clearSelectedButton();
private slots:
	void setSelected();
	void setSquareValue();
private:
	QGridLayout * layout;
	QGridLayout * padLayout;
	QVBoxLayout * vLayout;
	GridButton * buttons[9][9]{};
};

