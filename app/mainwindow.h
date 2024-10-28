#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPlainTextEdit>

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QTabWidget tabWidget;
    void createMenus();
    void openFile();
    void about();
    void aboutQt();
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() = default;
};
#endif // MAINWINDOW_H
