#include "Window.h"
#include "Keypad.h"


Window::Window(QWidget *parent) : QMainWindow(parent)
{
	grid = new VisualGrid(&base);

	QAction *quit = new QAction("&Quit", this);
	QAction *openFile = new QAction("&Load from File", this);

	menuBar()->addAction(quit);
	menuBar()->addAction(openFile);

	QFileDialog* fileDialog = new QFileDialog(this);

	connect(quit, &QAction::triggered, qApp, QApplication::quit);
	connect(openFile, &QAction::triggered, qApp, [this]() {loadSudokuFromFile(); });

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
