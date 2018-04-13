#pragma once

#include <QtWidgets/QMainWindow>
#include <QPushButton>
#include <QGridLayout>
#include <QVariant>

class Window: public QMainWindow
{
	Q_OBJECT
public:
	Window(QWidget *parent = Q_NULLPTR);

private:
	QWidget base;
	QVBoxLayout verticalLayout;
	QPushButton* buttons[9][9];
	QGridLayout* createGameLayout();
	QPushButton* createGridButton(int row, int col);
};

