#include "QT/mainwindow.h"
#include "QT/glMainWindow.h"
#include "QT/guiIGE.h"
#include <stdlib.h>
#include "SDL2/SDL.h"
#include "AL/al.h"
#include "AL/alc.h"
#include "AL/alext.h"
#include "AL/common/atomic.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow window;
    window.show();
    return a.exec();
}
