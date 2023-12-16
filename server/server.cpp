#include "server.h"

server::server() {
    if(this->listen(QHostAddress("127.0.0.1"), 4000)) {
        qDebug() << "Start";
        qDebug() << "Server address: " << this->serverAddress().toString();

    } else {
        qDebug() << "Error";
    }
    nextBlockSize = 0;
}

ClientHandler::ClientHandler(QTcpSocket *socket)
    : socket(socket) {
    connect(&timer, &QTimer::timeout, this, &ClientHandler::sendPeriodicMessage);

    // Додайте деякі налаштування таймера (наприклад, встановлення інтервалу часу)
    timer.setInterval(10000);
}

void server::incomingConnection(qintptr socketDescriptor) {
    qDebug() << "Incoming connection with descriptor: " << socketDescriptor;

    QTcpSocket *newSocket = new QTcpSocket;
    newSocket->setSocketDescriptor(socketDescriptor);

    connect(newSocket, &QTcpSocket::readyRead, this, &server::slotReadyRead);

    Sockets.push_back(newSocket);
    ClientHandler* newClient = new ClientHandler(newSocket);
    clients.push_back(newClient);

    connect(newSocket, &QTcpSocket::disconnected, this, [this, newSocket]() {
        for (ClientHandler* client : clients) {
            if (client->getSocket() == newSocket) {
                clients.removeOne(client);
                delete client;
                break;
            }
        }

        Sockets.removeOne(newSocket);
        newSocket->deleteLater();
    });

    qDebug() << "Client connected with descriptor: " << socketDescriptor;
    qDebug() << "Number of connected clients: " << Sockets.size();
}

QTcpSocket* ClientHandler::getSocket() const {
    return socket;
}

void server::slotReadyRead() {
    socket = (QTcpSocket*)sender();
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_2);
    if (in.status() == QDataStream::Ok) {
        for (;;) {
            if (nextBlockSize == 0) {
                if (socket -> bytesAvailable() < 2) {
                    break;
                }
                in >> nextBlockSize;
            }
            if (socket -> bytesAvailable() < nextBlockSize) {
                break;
            }
            QString str;
            in >> str;

            ClientHandler* clientHandler = nullptr;
            for (ClientHandler* client : clients) {
                if (client -> getSocket() == socket) {
                    clientHandler = client;
                    break;
                }
            }

            nextBlockSize = 0;
            if (clientHandler) {
                if (str == "subscribed") {
                    clientHandler -> clientSubscribed();
                    SendToClient("Ви підписались на сервіс розсилки щоденний курс валют!", clientHandler->getSocket());
                } else {
                    clientHandler -> clientUnsubscribed();
                    SendToClient("Ви відписались від сервісу розсилки щоденний курс валют!", clientHandler->getSocket());
                }
            } else {
                SendToClient("Упс! Помилка", clientHandler->getSocket());
            }
            break;
        }
    } else {
        qDebug() << "DataStream error";
    }
}

void server::SendToClient(QString str, QTcpSocket* socket) {
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out << quint16(0) << str;
    out.device() -> seek(0);
    out << quint16(Data.size() - sizeof(quint16));

    socket -> write(Data);
//    for (int i = 0; i < Sockets.size(); i++) {
//        Sockets[i] -> write(Data);
//    }
}

void ClientHandler::clientSubscribed() {
    subscribe = true;
    timer.start();
}

void ClientHandler::clientUnsubscribed() {
    subscribe = false;
    timer.stop();
}

void ClientHandler::sendPeriodicMessage()
{
    if (subscribe) {
        Data.clear();
        QDataStream out(&Data, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_6_2);
        out << quint16(0) << "str";
        out.device() -> seek(0);
        out << quint16(Data.size() - sizeof(quint16));

        socket -> write(Data);
        // Надішліть періодичне повідомлення клієнту
    }
}
