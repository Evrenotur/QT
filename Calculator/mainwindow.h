#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;


private slots:
   void NumPressed();
   void MathButtonPressed();
   void EqualButton();
   void ChangeNumberSign();
   void clearPressed();
   //void sinPressed();

};
#endif // MAINWINDOW_H
