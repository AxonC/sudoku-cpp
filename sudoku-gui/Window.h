#pragma once

#include <QtWidgets/QMainWindow>
#include <QPushButton>
#include <QGridLayout>
#include <QApplication>
#include <QAction>
#include <QMenuBar>
#include <QFileDialog>
#include <QMessageBox>
#include <string>

#include "VisualGrid.h"

class Window: public QMainWindow
{
	Q_OBJECT
public:
	Window(QWidget *parent = Q_NULLPTR);

	QStringList createFileDialog();
public slots:
	void loadSudokuFromFile();
	bool checkForCorrectAnswers();
private:
	QWidget base;
	QVBoxLayout verticalLayout;
	VisualGrid* grid;
};

