#include "client.h"
#include "ui_client.h"

client::client(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::client)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::readyRead, this, &client::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);
    nextBlockSize = 0;
}

client::~client()
{
    delete ui;
}


void client::on_connectServer_clicked()
{
    QString ipAddress = ui->ip_input->text();
    quint16 port = ui->port_input->text().toUShort();
    socket -> connectToHost(ipAddress, port);
}

void client::slotReadyRead()
{
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
            ui -> textBrowser -> append(str);
        }
    } else {
        ui -> textBrowser -> append("read error");
    }
}

void client::SendToServer(QString str) {
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out << quint16(0) << str;
    out.device() -> seek(0);
    out << quint16(Data.size() - sizeof(quint16));
    socket -> write(Data);
}

void client::on_pushButton_clicked()
{
    SendToServer("Блін");
}

