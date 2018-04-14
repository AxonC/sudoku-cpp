#include "Window.h"
#include "Keypad.h"
#include "VisualGrid.h"


Window::Window(QWidget *parent) : QMainWindow(parent)
{
	VisualGrid grid = new VisualGrid(&base);

	setCentralWidget(&base);
}