#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPlainTextEdit>

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QPlainTextEdit editor;
    void createMenus();
    void openFile();
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() = default;
};
#endif // MAINWINDOW_H
