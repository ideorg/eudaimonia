#include <QApplication>
#include <QScreen>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow mainWindow;
    mainWindow.resize(800, 600);
    QScreen* screen = app.primaryScreen();
    QRect screenGeometry = screen->geometry();
    int x = (screenGeometry.width() - mainWindow.width()) / 2;
    int y = (screenGeometry.height() - mainWindow.height()) / 2;
    mainWindow.move(x, y);
    mainWindow.show();
    return app.exec();
}