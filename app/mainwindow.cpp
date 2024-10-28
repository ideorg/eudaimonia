#include "mainwindow.h"
#include <QMenuBar>
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createMenus();
    setCentralWidget(&editor);
}

void MainWindow::createMenus() {
    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
    auto *openAct = new QAction(tr("&Open..."), this);
    fileMenu->addAction(openAct);
    connect(openAct, &QAction::triggered, this, &MainWindow::openFile);
    QMenu *helpMenu = menuBar()->addMenu(tr("&Help"));
    auto *aboutAct = new QAction(tr("&About"), this);
    helpMenu->addAction(aboutAct);
    connect(aboutAct, &QAction::triggered, this, &MainWindow::about);
    auto *aboutQtAct = new QAction(tr("About &Qt"), this);
    helpMenu->addAction(aboutQtAct);
    connect(aboutQtAct, &QAction::triggered, this, &MainWindow::aboutQt);
}

void MainWindow::openFile() {
    QFileDialog dialog(this, tr("Open File"));
    dialog.setOption(QFileDialog::DontUseNativeDialog);
    if (dialog.exec() == QDialog::Accepted) {
        QString fileName = dialog.selectedFiles().first();
        QFile f(fileName);
        if (!f.open(QFile::ReadOnly)) {
            qWarning() << "Failed to open" << fileName << ":" << f.errorString();
            return;
        }
        editor.setPlainText(QString::fromUtf8(f.readAll()));
    }
}

void MainWindow::about() {

}
void MainWindow::aboutQt() {
    QMessageBox::aboutQt(this);
}

