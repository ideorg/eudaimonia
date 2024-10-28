#include "mainwindow.h"
#include <QMenuBar>
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QSplitter>
#include <QTreeView>
#include "generated/version.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createMenus();
    auto *mainWidget = new QWidget(this);
    auto *mainLayout = new QVBoxLayout(mainWidget);
    auto splitterHorizontal = new QSplitter;
    splitterHorizontal->setOrientation(Qt::Vertical);
    auto *splitterVertical = new QSplitter;
    splitterVertical->setOrientation(Qt::Horizontal);
    auto *treeView = new QTreeView;
    treeView->setMinimumWidth(5);
    splitterVertical->addWidget(treeView);
    splitterVertical->addWidget(&editor);
    auto *bottomPanel = new QWidget;
    QList<int> sizes1;
    sizes1 << 250 << 1000;
    splitterVertical->setSizes(sizes1);
    splitterHorizontal->addWidget(splitterVertical);
    splitterHorizontal->addWidget(bottomPanel);
    QList<int> sizes2;
    sizes2 << 320 << 180;
    splitterHorizontal->setSizes(sizes2);
    mainLayout->addWidget(splitterHorizontal);
    setCentralWidget(mainWidget);
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

