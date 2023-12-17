#include "server.h"
#include <QFile>
#include <QTimer>
#include <QThread>

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
    connect(&timerCurrency, &QTimer::timeout, this, &ClientHandler::sendPeriodicMessageCurrency);
    connect(&timerStonks, &QTimer::timeout, this, &ClientHandler::sendPeriodicMessageStonks);
    // Додайте деякі налаштування таймера (наприклад, встановлення інтервалу часу)
    timerCurrency.setInterval(10000);
    timerStonks.setInterval(5000);
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
                if (str == "subscribedCurrency") {
                    clientHandler -> clientSubscribedCurrency();
                    SendToClient("Ви підписались на сервіс розсилки щоденний курс валют!", clientHandler->getSocket());
                } else if (str == "unsubscribedCurrency") {
                    clientHandler -> clientUnsubscribedCurrency();
                    SendToClient("Ви відписались від сервісу розсилки щоденний курс валют!", clientHandler->getSocket());
                }

                if (str == "subscribedStonks") {
                    clientHandler -> clientSubscribedStonks();
                    SendToClient("Ви підписались на сервіс розсилки щохвилинний курс акцій!", clientHandler->getSocket());
                } else if (str == "unsubscribedStonks") {
                    clientHandler -> clientUnsubscribedStonks();
                    SendToClient("Ви відписались від сервісу розсилки щохвилинний курс акцій!", clientHandler->getSocket());
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
}

void ClientHandler::clientSubscribedCurrency() {
    subscribeCurrency = true;
    timerCurrency.start();
}

void ClientHandler::clientUnsubscribedCurrency() {
    subscribeCurrency = false;
    timerCurrency.stop();
}

void ClientHandler::clientSubscribedStonks() {
    subscribeStonks = true;
    timerStonks.start();
}

void ClientHandler::clientUnsubscribedStonks() {
    subscribeStonks = false;
    timerStonks.stop();
}

void ClientHandler::sendPeriodicMessageCurrency()
{
    if (subscribeCurrency) {
        QFile file("../currencies.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << "Не вдалося відкрити файл.";
            return;
        }

        QTextStream in(&file);
        QStringList lines;
        while (!in.atEnd()) {
            lines << in.readLine();
        }
        file.close();

        if (currentIndexCurrency < lines.size()) {
            QString lineToSend = lines.at(currentIndexCurrency);

            // Формуємо дані для відправки
            Data.clear();
            QDataStream out(&Data, QIODevice::WriteOnly);
            out.setVersion(QDataStream::Qt_6_2);
            out << quint16(0) << lineToSend;
            out.device()->seek(0);
            out << quint16(Data.size() - sizeof(quint16));

            socket->write(Data);
            socket->waitForBytesWritten();

            // Збільшуємо лічильник для вибору наступного рядка
            currentIndexCurrency++;
        }
    }
}

void ClientHandler::sendPeriodicMessageStonks()
{
    if (subscribeStonks) {
        QFile file("../stonks.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << "Не вдалося відкрити файл.";
            return;
        }

        QTextStream in(&file);
        QStringList lines;
        while (!in.atEnd()) {
            lines << in.readLine();
        }
        file.close();

        Data.clear();
        QDataStream out(&Data, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_6_2);

        if (currentIndexStonks < lines.size()) {
            QString lineToSend = lines.at(currentIndexStonks);

            out << quint16(0) << lineToSend;
            out.device()->seek(0);
            out << quint16(Data.size() - sizeof(quint16));
            socket->write(Data);
            socket->waitForBytesWritten();

            currentIndexStonks++;
        } else {
            QString ops = "Упс, сталась прикрість, інформація щодо сервісу закінчилась!";
            out << quint16(0) << ops;
            out.device()->seek(0);
            out << quint16(Data.size() - sizeof(quint16));
            socket->write(Data);
        }
    }
}
