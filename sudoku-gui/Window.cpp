#include "Window.h"
#include "Keypad.h"


Window::Window(QWidget *parent) : QMainWindow(parent)
{
	grid = new VisualGrid(&base);

	QAction* quit = new QAction("&Quit", this);
	QAction* openFile = new QAction("&Load from File...", this);
	QAction* checkSolution = new QAction("&Check Solution", this);

	menuBar()->addAction(openFile);
	menuBar()->addAction(checkSolution);
	menuBar()->addAction(quit);

	connect(quit, &QAction::triggered, qApp, QApplication::quit);
	connect(openFile, &QAction::triggered, qApp, [this]() {loadSudokuFromFile(); });
	connect(checkSolution, &QAction::triggered, qApp, [this]() {checkForCorrectAnswers(); });

	setCentralWidget(&base);
}

QStringList Window::createFileDialog()
{
	QFileDialog* fileDialog = new QFileDialog(this);
	QStringList fileNames;

	if (fileDialog->exec())
	{
		fileNames = fileDialog->selectedFiles();
	}
	
	return fileNames;
}

void Window::loadSudokuFromFile()
{	/** START OF CITATION: Code partially adapted from the Qt Documentation: http://doc.qt.io/qt-5/qtwidgets-tutorials-addressbook-part6-addressbook-cpp.html **/
	QString fileName = QFileDialog::getOpenFileName(this, tr("Load Sudoku File"), "", tr("Suokdu Grid Files (*.sudoku);"));

	if (fileName.isEmpty()) {
		return;
	} else {
		std::string realFile = fileName.toStdString();
		grid->loadFromFile(realFile);
		grid->updateInterface();
	}
	/** END OF CITED CODE FROM: http://doc.qt.io/qt-5/qtwidgets-tutorials-addressbook-part6-addressbook-cpp.html **/
}

bool Window::checkForCorrectAnswers()
{
	if (grid->checkSolution())
	{
		QMessageBox::information(this, tr("Sudoku"), tr("You have completed the puzzle! Well done!"), QMessageBox::Escape);
		return true;
	}
	QMessageBox::warning(this, tr("Sudoku"), tr("You are missing a few entries."), QMessageBox::Escape);
	return false;
}
