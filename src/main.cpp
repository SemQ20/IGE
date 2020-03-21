#include "mainwindow.h"
#include "glMainWindow.h"

#include "QtWidgets/QApplication"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow window;
    window.show();
    return a.exec();
}
