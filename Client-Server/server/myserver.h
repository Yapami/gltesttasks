#ifndef MYSERVER_H
#define MYSERVER_H

#include <QString>
#include <QTcpServer>
#include <QTcpSocket>

class MyServer : public QTcpServer {
  Q_OBJECT
public:
  MyServer();
  ~MyServer();

  QTcpSocket *socket;
  QByteArray Data; //переменная, куда мы будем складывать данные для их передачи
                   //по сокету в сеть
public slots:
  void StartServer();
  void incomingConnection(
      qintptr
          socketDescriptor); //метод по умалчанию для сервера TCP, содержит
                             //инструкции в случаи присоиденения нового клиента,
                             // socketDescriptor - уникальный номер
                             // присоеденения
  void SockReady(); //метод описания готовности сокета читать полученные данные
  void SockDisc(); //отвечает задействия производимые при отключении клиента от
                   //сокета(удаление объекта отвечающего за соединение)
};

#endif // MYSERVER_H
