#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QMainWindow>
#include <QMessageBox>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

  QTcpSocket *socket; //отвечает за передачу информации
  QByteArray Data; //переменная, куда мы будем складывать данные для их передачи
                   //по сокету в сеть
  QJsonDocument doc;
  QJsonParseError doc_error; //переменная отвечает за ошибку

public slots:
  void SockReady(); // готовность читать данные от сервера
  void SockDisc(); // в случае если клиент отключается

private slots:
  void on_pushButton_clicked();

private:
  Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
