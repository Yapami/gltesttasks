#include "myserver.h"

MyServer::MyServer() {}
MyServer::~MyServer() {}

void MyServer::StartServer() {
  if (this->listen(QHostAddress::LocalHost,
                   5555)) // listen() запускает сервер, 1п. - адрес с которого
                          // сервер будет запущен, 2п. - порт
  {
    qDebug() << "Listening";
  } else {
    qDebug() << "Not Listening";
  }
}

void MyServer::incomingConnection(qintptr socketDescriptor) {

  socket = new QTcpSocket(this); //в случае нового соединения мы создаем сокет
                                 //через который будем общаться
  socket->setSocketDescriptor(
      socketDescriptor); //присваеваем ему его уник. номер. Он будет
                         //автоматически даваться самим приложением
  connect(socket, SIGNAL(readyRead()), this, SLOT(SockReady()));
  connect(socket, SIGNAL(disconnected()), this, SLOT(SockDisc()));
  qDebug() << socketDescriptor << "Clint connected"; // log

  socket->write(
      "{\"type\":\"connection\",\"status\":\"yes\"}"); //отправляем клиенту
                                                       //увидкмление о
                                                       //соеденении в формате
                                                       // json
  qDebug() << "Send client connect status - YES"; // log
}

void MyServer::SockReady() {}

void MyServer::SockDisc() {
  qDebug() << "Disconnect"; // log
  socket->deleteLater(); //удалить позже, как только это будет возможно
}
