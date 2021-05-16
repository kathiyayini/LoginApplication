#include "mainwindow.h"

#include <QApplication>
#include<QPushButton>
#include<QFile>
#include<QTextStream>

QString readTextFile(QString path) {
    QFile file(path);
    if(file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QTextStream in(&file);
        return in.readAll();
    }
    return "";
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString css=readTextFile(":/style.txt");
    if(css.length()>0)
    {
        a.setStyleSheet(css);
    }
    MainWindow w;
    w.setWindowTitle("Login");
    w.setFixedSize(500, 500);
    w.show();
    return a.exec();
}
