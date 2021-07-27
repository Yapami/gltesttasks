#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  socket = new QTcpSocket(this); //при запуске клента создаем новый сокет
  connect(socket, SIGNAL(readyRead()), this, SLOT(SockReady()));
  connect(socket, SIGNAL(disconnected()), this, SLOT(SockDisc()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_clicked() {
  socket->connectToHost(
      "127.0.0.1",
      5555); //пытется соедениться с сервером, 1п. - локальный адрес, 2п. - порт
}

void MainWindow::SockDisc() {
  socket->deleteLater(); //приложение удаляет сокет
}

void MainWindow::SockReady() {
  if (socket->waitForConnected(
          500)) //проверяем есть ли соеденение и устойчивое ли оно
  {
    socket->waitForReadyRead(500); // ждем сокет на чтение 0.5 секунд
    Data = socket->readAll(); // Считываем все, что есть в секете
    doc = QJsonDocument::fromJson(
        Data, &doc_error); //помещаем то, что получили в Data, 1п. - Data, 2п. -
                           //складирует ошибки

    if (doc_error.errorString() == "no error occured") // проверка на ошибки
    {
      if ((doc.object().value("type").toString() == "connection") &&
          (doc.object().value("status").toString() == "yes")) {
        QMessageBox::information(this, "Connect", "You are connected");
      } else {
        QMessageBox::warning(this, "Connect", "You are not connected");
      }
    }
  }
}
