#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::login)
{
  ui->setupUi(this);

  QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
  //QString workdir = QDir::currentPath();
  //qDebug() <<workdir;
  //workdir = workdir + QString("/example.sqlite");
  db.setDatabaseName("./example.sqlite");

if(!db.open()){
  ui->status->setText("Failed!");
  }

 else {
    ui->status->setText("Connected!");
    QString string = "select * from Ramesh;", stringnew = "";
    QSqlQuery query(db);
    query.exec(string);
    qDebug() << string;
    while (query.next()) {
        QString id = query.value(0).toString();
        QString name = query.value(1).toString();
        QString lname = query.value(2).toString();
        QString email = query.value(3).toString();
        QString phone = query.value(4).toString();

        stringnew = stringnew + id + " " + name + " " + lname + " " + email+ " " + phone + "\n";
      }
    ui->status->setText(stringnew);
    qDebug() << stringnew;
    }


}


login::~login()
{
  delete ui;
}
