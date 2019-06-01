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
    QString string = "select * from Ramesh;";
    QSqlQuery query(db);
    query.exec(string);
    qDebug() << string;
    while (query.next()) {
        QString name = query.value(0).toString();
        QString email = query.value(1).toString();
        qDebug() << name << email;
    }
    qDebug() << db.lastError();
    }
}


login::~login()
{
  delete ui;
}
