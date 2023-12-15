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

void server::incomingConnection(qintptr socketDescriptor) {
    qDebug() << "Incoming connection with descriptor: " << socketDescriptor;

    QTcpSocket *newSocket = new QTcpSocket;
    newSocket->setSocketDescriptor(socketDescriptor);

    connect(newSocket, &QTcpSocket::readyRead, this, &server::slotReadyRead);
    connect(newSocket, &QTcpSocket::disconnected, this, &server::deleteLater);

    Sockets.push_back(newSocket);

    qDebug() << "Client connected with descriptor: " << socketDescriptor;
    qDebug() << "Number of connected clients: " << Sockets.size();
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
            nextBlockSize = 0;
            SendToClient(str);
            break;
        }
    } else {
        qDebug() << "DataStream error";
    }
}

void server::SendToClient(QString str) {
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out << quint16(0) << str;
    out.device() -> seek(0);
    out << quint16(Data.size() - sizeof(quint16));
    for (int i = 0; i < Sockets.size(); i++) {
        Sockets[i] -> write(Data);
    }
}
