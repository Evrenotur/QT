#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>
double calcVal = 0.0;
bool divTrigger = false;
bool multTrigger = false;
bool addTrigger = false;
bool subTrigger = false;
bool sinTrigger = false;
bool cosTrigger = false;
bool sqrtTrigger = false;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Değişkenin değeri "calcVal" olarak ayarlanıyor ve bu değer metin kutusuna ("Display") yazılıyor.
    ui->Display->setText(QString::number(calcVal));

    // 10 adet QPushButton işaretçisi tutacak bir dizi tanımlanıyor.
    QPushButton *numButtons[10];

    for(int i = 0; i < 10; ++i)
    {
        QString butName = "Button" + QString::number(i); // Her bir düğme için bir isim oluşturuluyor, örneğin "Button 0", "Button 1" gibi.
        numButtons[i] = MainWindow::findChild<QPushButton*>(butName); // Her bir düğmeyi bulmak için MainWindow sınıfının findChild fonksiyonu kullanılıyor ve bu düğmeler numButtons dizisine atanıyor.
        connect(numButtons[i], SIGNAL(released()), this, SLOT(NumPressed())); // Her bir düğmenin released sinyali NumPressed fonksiyonu ile bağlanıyor.
    }
     connect(ui->Add, SIGNAL(released()), this, SLOT(MathButtonPressed()));
     connect(ui->Subtract, SIGNAL(released()), this, SLOT(MathButtonPressed()));
     connect(ui->Multy, SIGNAL(released()), this, SLOT(MathButtonPressed()));
     connect(ui->Divide, SIGNAL(released()), this, SLOT(MathButtonPressed()));
      connect(ui->sin, SIGNAL(released()), this, SLOT(MathButtonPressed()));
      connect(ui->cos, SIGNAL(released()), this, SLOT(MathButtonPressed()));
      connect(ui->Kok, SIGNAL(released()), this, SLOT(MathButtonPressed()));
     connect(ui->Equals, SIGNAL(released()), this, SLOT(EqualButton()));
     connect(ui->ChangeSign, SIGNAL(released()), this, SLOT(ChangeNumberSign()));
       connect(ui->Clear, SIGNAL(released()), this, SLOT(clearPressed()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::NumPressed()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender()); // Göndericiyi QPushButton türüne dönüştürüyoruz.
    QString butval = button->text(); // Düğmenin metin değerini alıyoruz.
    QString displayVal = ui->Display->text(); // Ekranın mevcut metin değerini alıyoruz.

    if (displayVal.toDouble() == 0.0) { // Eğer ekran boşsa veya sıfırsa...
        ui->Display->setText(butval); // Düğmenin değerini ekrana yazıyoruz.
    } else { // Eğer ekran doluysa...
        QString newVal = displayVal + butval; // Ekranın mevcut değerine düğmenin değerini ekliyoruz.
        double dbNewVal = newVal.toDouble(); // Yeni değeri double türüne dönüştürüyoruz.
        ui->Display->setText(QString::number(dbNewVal, 'g', 16)); // Yeni değeri ekrana yazıyoruz.
    }


}
void MainWindow::MathButtonPressed()
{
divTrigger=false;
multTrigger=false;
addTrigger = false;
subTrigger = false;
sinTrigger = false;
cosTrigger = false;
sqrtTrigger = false;
QString displayVal = ui->Display->text(); // Ekrandaki texti displayVal değişkenine attık.
calcVal = displayVal.toDouble(); // String degeri double a dönüştürerek calcValue değişkenine attık.
QPushButton * button =  (QPushButton*)sender();//sender() fonksiyonu, sinyalin hangi nesne tarafından gönderildiğini belirler
QString butVal = button->text();//button değerini but val değişkenine attık
if(QString::compare(butVal,"/",Qt::CaseInsensitive) == 0)
{
 // Eğer butVal, "/" karakter dizisine eşitse (büyük/küçük harf duyarlılığı gözetmeksizin)...
    divTrigger = true;
}
else if(QString::compare(butVal,"*",Qt::CaseInsensitive) == 0)
{
 // Eğer butVal, "*" karakter dizisine eşitse (büyük/küçük harf duyarlılığı gözetmeksizin)...
   multTrigger = true;
}
else if(QString::compare(butVal,"+",Qt::CaseInsensitive) == 0)
{
 // Eğer butVal, "+" karakter dizisine eşitse (büyük/küçük harf duyarlılığı gözetmeksizin)...
   addTrigger = true;
}
else if(QString::compare(butVal,"-",Qt::CaseInsensitive) == 0)
{
 // Eğer butVal, "-" karakter dizisine eşitse (büyük/küçük harf duyarlılığı gözetmeksizin)...
  subTrigger = true;
}
else if(QString::compare(butVal,"sin",Qt::CaseInsensitive) == 0)
{
 // Eğer butVal, "-" karakter dizisine eşitse (büyük/küçük harf duyarlılığı gözetmeksizin)...
  sinTrigger = true;
}
else if(QString::compare(butVal,"cos",Qt::CaseInsensitive) == 0)
{
 // Eğer butVal, "-" karakter dizisine eşitse (büyük/küçük harf duyarlılığı gözetmeksizin)...
  cosTrigger = true;
}
else if(QString::compare(butVal,"kok",Qt::CaseInsensitive) == 0)
{
 // Eğer butVal, "-" karakter dizisine eşitse (büyük/küçük harf duyarlılığı gözetmeksizin)...
  sqrtTrigger = true;
}
ui->Display->setText("");
}
void MainWindow::EqualButton()
{
    double solution= 0.0;
    QString displayVal = ui->Display->text(); // Ekrandaki texti displayVal değişkenine attık.
    double dbDisplayVal = displayVal.toDouble(); // String degeri double a dönüştürerek calcValue değişkenine attık.

    if(addTrigger || subTrigger || multTrigger ||divTrigger||sinTrigger||sqrtTrigger||cosTrigger)
    {
        if(addTrigger)
        {
            solution = calcVal + dbDisplayVal;
        }
        else if(subTrigger)
        {
           solution = calcVal - dbDisplayVal;
        }
        else if(multTrigger)
        {
            solution = calcVal * dbDisplayVal;
        }
        else if(divTrigger)
        {
            solution = calcVal / dbDisplayVal;
        }
        else if(sinTrigger)
        {
            solution = std::sin(dbDisplayVal);
        }
        else if(cosTrigger)
        {
            solution = std::cos(dbDisplayVal);
        }
        else if(sqrtTrigger)
        {
            solution = std::sqrt(dbDisplayVal);
        }
        ui->Display->setText(QString::number(solution));
    }

    QPushButton * button =  (QPushButton*)sender();//sender() fonksiyonu, sinyalin hangi nesne tarafından gönderildiğini belirler
    QString butVal = button->text();//button değerini but val değişkenine attık

}
/*[-]?: Bu öğe, negatif sayıları da içerecek şekilde isteğe bağlı bir negatif işareti temsil eder.
 *  Yani, eğer sayı negatifse, bu öğeyle eşleşir.
[0-9.]*: Bu öğe, rakam ve nokta karakterlerinin birleşimini temsil eder. 0-9 aralığındaki rakamlar
ve . karakteri bu ifadeyle eşleşir. * ifadesi ise bu karakterlerin sıfır veya daha fazla kez
tekrarlanabileceğini belirtir
. Yani, bu ifade herhangi bir uzunluktaki sayısal değerlere eşleşir.
*/
void MainWindow::ChangeNumberSign()
{

    QString displayVal = ui->Display->text();
    QRegExp reg("[-]?[0-9.]*");
    if(reg.exactMatch(displayVal))
    {
        double dbDispval = displayVal.toDouble();
        double dbDispvalsign = -1*dbDispval;
        ui->Display->setText((QString::number(dbDispvalsign)));



    }
}
void MainWindow::clearPressed()
{
    ui->Display->setText((QString::number(0)));
}
