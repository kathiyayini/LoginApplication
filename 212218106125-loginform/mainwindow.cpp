#include "mainwindow.h"
#include "QPushButton"
#include "QLabel"
#include "QLineEdit"
#include "QDebug"
#include "QMessageBox"
#include "QVBoxLayout"
#include "QFont"
#include "dialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    //Image icon for username
    QLabel *lab=new QLabel(this);
    lab->setMinimumSize(70,70);
    lab->move(70,110);
    QPixmap pixx("E:/sem 6/c++/212218106125-loginform/id.jpg");
    lab->setPixmap(pixx.scaled(20,20));

    //Set image icon in center
    QLabel *mlabel=new QLabel(this);
    mlabel->setMinimumSize(80,80);
    mlabel->move(150,10);
    mlabel->setAlignment(Qt::AlignHCenter);
    QPixmap pix("E:/sem 6/c++/212218106125-loginform/login.jpg");
    mlabel->setPixmap(pix.scaled(80,80,Qt::KeepAspectRatio));

    //QLabel for username mainwindow.cpp*
    QLabel *unLabel=new QLabel("UserName",this);
    unLabel->setMinimumSize(70,50);
    unLabel->move(100,110);
    QPalette l1;
    l1.setColor(QPalette::WindowText,Qt::blue);
    unLabel->setPalette(l1);

    //QLineEdit for username
    QLineEdit *unLineEdit=new QLineEdit(this);
    unLineEdit->setMinimumSize(220,45);
    unLineEdit->move(190,110);

    //set the lineedit border to red color
    unLineEdit->setStyleSheet("border: 2px blue ");

    //Image icon for password
    QLabel *labb=new QLabel(this);
    labb->setMinimumSize(200,50);
    labb->move(70,180);
    QPixmap pixxx("E:/sem 6/c++/212218106125-loginform/pass.png");
    labb->setPixmap(pixxx.scaled(20,20));

    //QLabel for password
    QLabel *pwd=new QLabel("Password",this);
    pwd->setMinimumSize(70,50);
    pwd->move(100,180);
    QPalette l2;
    l2.setColor(QPalette::WindowText,Qt::green);
    pwd->setPalette(l2);

    //QLineEdit for password
    QLineEdit *pwdLineEdit=new QLineEdit(this);
    pwdLineEdit->setMinimumSize(220,45);
    pwdLineEdit->move(190,180);
    pwdLineEdit->setEchoMode(QLineEdit::Password);

    //set the lineedit border to green color
    pwdLineEdit->setStyleSheet("border: 2px solid green");

    //QLabel
    QLabel *account=new QLabel("Dont have account",this);
    account->setMinimumSize(130,50);
    account->move(100,240);

    //QPushButton for signup
    QFont button("Times",8,QFont::Bold);
    QPushButton *button1=new QPushButton("SignUp",this);
    button1->setFont(button);
    button1->move(245,250);
    connect(button1,&QPushButton::clicked,[=](){
        Dialog *dialog=new Dialog(this);
        int result = dialog->exec();
        if(result == QDialog::Rejected)
        {
            close();
        }
    });

    //QPushButton for Login
    QFont buttons("Times",12,QFont::Bold);
    QPushButton *button2=new QPushButton("Login",this);
    button2->setFont(buttons);
    button2->setMinimumSize(160,40);
    button2->move(170,300);
    connect(button2,&QPushButton::clicked,[=](){
        if(unLineEdit->text() == "kathiyayini" && pwdLineEdit->text() == "1130")
        {
            QMessageBox::information(this, "Login", "Username and Password are correct");
        }
        else
        {
            QMessageBox::information(this, "Login", "Username and password are incorrect");
        }
    });

}

MainWindow::~MainWindow()
{
}
