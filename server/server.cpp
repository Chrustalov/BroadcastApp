#include "server.h"
#include "ui_server.h"

server::server(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::server)
{
    ui->setupUi(this);
}

server::~server()
{
    delete ui;
}

Server::Server() {
    if(this->listen(QHostAddress::Any, 3000)) {
        qDebug() << "Start";
    } else {
        qDebug() << "Error";
    }
    nextBlockSize = 0;
}

void Server::incomingConnection(qintptr socketDescriptor) {
    socket = new QTcpSocket;
    socket -> setSocketDescriptor(socketDescriptor);
    connect(socket, &QTcpSocket::readyRead, this, &Server::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, this, &Server::deleteLater);

    Sockets.push_back(socket);
    qDebug() << "client connected " << socketDescriptor;
}

void Server::slotReadyRead() {
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

void Server::SendToClient(QString str) {
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out.setVersion(QDataStream::Qt_6_2);
    out << quint16(0) << str;
    out.device() -> seek(0);
    out << quint16(Data.size() - sizeof(quint16));
    for (int i = 0; i < Sockets.size(); i++) {
        Sockets[i] -> write(Data);
    }
}

