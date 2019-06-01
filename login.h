#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include<QFileInfo>
#include <QDir>

namespace Ui {
  class login;
}

class login : public QMainWindow
{
  Q_OBJECT

public:
  explicit login(QWidget *parent = nullptr);
  ~login();

private:
  Ui::login *ui;
};

#endif // LOGIN_H
