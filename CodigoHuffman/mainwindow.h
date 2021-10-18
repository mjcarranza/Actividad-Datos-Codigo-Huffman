#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setDecodedTxt(string str);
    void decodeText(string text);
private slots:
    void on_codeButton_clicked();

    void on_decodeButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
