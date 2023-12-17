#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QCloseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class client; }
QT_END_NAMESPACE

class client : public QMainWindow
{
    Q_OBJECT

public:
    client(QWidget *parent = nullptr);
    ~client();

private slots:
    void on_connectServer_clicked();

    void on_push_exchange_rate_clicked();

    void on_push_shares_rate_clicked();

    void on_push_weather_forecast_clicked();

public slots:
    void slotReadyRead();

private:
    Ui::client *ui;
    QTcpSocket *socket;
    QByteArray Data;
    void SendToServer(QString str);
    quint16 nextBlockSize;
    void CreateUserFile(const QString &fileName);
    void closeEvent(QCloseEvent *event) override;
};
#endif // CLIENT_H
