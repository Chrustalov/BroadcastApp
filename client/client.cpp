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

    connect(socket, &QTcpSocket::connected, this, [=]() {
        qDebug() << "Connected to the server!";
    });

    connect(socket, &QTcpSocket::errorOccurred, this, [=](QAbstractSocket::SocketError socketError) {
        qDebug() << "Connection error: " << socket->errorString();
    });
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
            if (!str.isEmpty()){
                ui -> textBrowser -> append(str);
            }
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

void client::on_push_exchange_rate_clicked()
{
    QString currentStyles = ui -> push_exchange_rate -> styleSheet();

    if (ui -> push_exchange_rate -> text() == "Підписатись") {
        SendToServer("subscribed");
        ui -> push_exchange_rate -> setStyleSheet(currentStyles + "background-color: #a20c40;");
        ui -> push_exchange_rate -> setText("Відписатись");
    } else {
        SendToServer("Ви відписались від сервісу розсилки щоденний курс валют!");
        ui -> push_exchange_rate -> setStyleSheet(currentStyles + "background-color: #036317;");
        ui -> push_exchange_rate -> setText("Підписатись");
    }
}


void client::on_push_shares_rate_clicked()
{
    QString currentStyles = ui -> push_shares_rate -> styleSheet();

    if (ui -> push_shares_rate -> text() == "Підписатись") {
        SendToServer("Ви підписались на сервіс розсилки щохвилинний курс акцій!");
        ui -> push_shares_rate -> setStyleSheet(currentStyles + "background-color: #a20c40;");
        ui -> push_shares_rate -> setText("Відписатись");
    } else {
        SendToServer("Ви відписались від сервіс розсилки щохвилинний курс акцій!");
        ui -> push_shares_rate -> setStyleSheet(currentStyles + "background-color: #036317;");
        ui -> push_shares_rate -> setText("Підписатись");
    }
}


void client::on_push_weather_forecast_clicked()
{
    QString currentStyles = ui -> push_weather_forecast -> styleSheet();

    if (ui -> push_weather_forecast -> text() == "Підписатись") {
        SendToServer("Ви підписались на сервіс розсилки щогодинний прогноз погоди!");
        ui -> push_weather_forecast -> setStyleSheet(currentStyles + "background-color: #a20c40;");
        ui -> push_weather_forecast -> setText("Відписатись");
    } else {
        SendToServer("Ви відписались від сервісу розсилки щогодинний прогноз погоди!");
        ui -> push_weather_forecast -> setStyleSheet(currentStyles + "background-color: #036317;");
        ui -> push_weather_forecast -> setText("Підписатись");
    }
}

