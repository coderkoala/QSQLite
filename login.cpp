#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::login)
{
  ui->setupUi(this);

  QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
  QString workdir = QDir::currentPath();
  workdir = workdir + QString("/example.sqlite");
  db.setDatabaseName(workdir);

if(!db.open()){
  ui->status->setText("Failed!");
  }

 else {
    ui->status->setText("Connected!");
    QString string = "select * from Ramesh";
    QSqlQuery query(db);
    query.exec(string);
    qDebug() << " The app is actually running";
    qDebug() << string;
    while (query.next()) {
        QString name = query.value(0).toString();
        QString email = query.value(1).toString();
        qDebug() << name << email;
    }
    }
}


login::~login()
{
  delete ui;
}
