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
    void clientSubscribedCurrency();
    void clientUnsubscribedCurrency();
    void clientSubscribedStonks();
    void clientUnsubscribedStonks();
    void clientSubscribedForecast();
    void clientUnsubscribedForecast();
    void sendPeriodicMessageCurrency();
    void sendPeriodicMessageStonks();
    void sendPeriodicMessageForecast();

private:
    QTcpSocket *socket;
    QTimer timerCurrency;
    QTimer timerStonks;
    QTimer timerForecast;
    QByteArray Data;
    bool subscribeCurrency = false;
    bool subscribeStonks = false;
    bool subscribeForecast = false;
    int currentIndexStonks = 0;
    int currentIndexCurrency = 0;
    int currentIndexForecast = 0;
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
