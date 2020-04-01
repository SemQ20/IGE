#include "mainwindow.h"
#include "glmainwindow.h"
#include "guiige.h"
#include <stdlib.h>
#include "SDL2/SDL.h"
#include "AL/al.h"
#include "AL/alc.h"
#include "AL/alext.h"
#include "AL/common/atomic.h"

#include "QtWidgets/QApplication"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow window;
    window.show();
    return a.exec();
}
