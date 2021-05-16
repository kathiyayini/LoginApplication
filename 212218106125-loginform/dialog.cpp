#include "dialog.h"
#include "ui_dialog.h"
#include "QDebug"
#include "QPixmap"
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QPixmap pix("E:/sem 6/c++/212218106125-loginform/signup.png");
    ui->label_icon->setPixmap(pix.scaled(200,100,Qt::KeepAspectRatio));
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_confirm_clicked()
{
    QString email = ui->email_lineEdit->text();
    QString pwd = ui->password_lineEdit->text();
    QString confirmPwd = ui->confirm_lineEdit->text();
    qDebug() << "Email :" << email;
    qDebug() << "Password :" << pwd;
    qDebug() << "Confirm Password :" << confirmPwd;
    if(!email.isEmpty() && !pwd.isEmpty() && !confirmPwd.isEmpty())
       {

       }
       else
       {
           qDebug() << "One Field is Empty";
       }
}

void Dialog::on_cancel_clicked()
{

    QApplication::quit();
}
