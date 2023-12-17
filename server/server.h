#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QTimer>

class ClientHandler : public QObject
{
    Q_OBJECT

public:
    ClientHandler(QTcpSocket *socket);
    QTcpSocket* getSocket() const;

public slots:
    void clientSubscribed();
    void clientUnsubscribed();
    void sendPeriodicMessage();
    //void sendDataToClient(const QString &data) const;

private:
    QTcpSocket *socket;
    QTimer timer;
    QByteArray Data;
    bool subscribe = false;
    int currentIndex = 0;
};

class server : public QTcpServer
{
    Q_OBJECT

public:
    server();
    QTcpSocket *socket;

private:
    QList<ClientHandler*> clients;
    QVector <QTcpSocket*> Sockets;
    QByteArray Data;
    quint16 nextBlockSize;

public slots:
    void incomingConnection(qintptr socketDescriptor);
    void slotReadyRead();
    void SendToClient(QString str, QTcpSocket* socket);
};
#endif // SERVER_H
