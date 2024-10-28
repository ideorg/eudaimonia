#include "mainwindow.h"
#include <QMenuBar>
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>
#include "generated/version.hpp"

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
    QPixmap customIcon(":/share/eudaimonia.png");;
    QMessageBox msgBox(this);
    msgBox.setWindowTitle(tr("About Eudaimonia %1").arg(APP_VERSION));
    QString Git_commit = GIT_COMMIT_HASH;
    msgBox.setText("<p><b>Eudaimonia</b> is Qt-based C++ IDE"
                   "<p>Copyright (C) 2024 Andrzej Borucki &lt;borucki.andrzej@gmail.com&gt;</p>"
                   "<p>This is free software; see the source for copying conditions. There is NO warranty; not "
                   "even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.</p><p>The source code for Eudaimonia is "
                   "available at <a href=\"https://github.com/ideorg/eudaimonia\"> "
                   "https://github.com/ideorg/eudaimonia</a>.</p>Git commit: " + Git_commit);
    msgBox.setIconPixmap(customIcon);
    msgBox.exec();
}

void MainWindow::aboutQt() {
    QMessageBox::aboutQt(this);
}

