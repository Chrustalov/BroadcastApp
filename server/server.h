#ifndef SERVER_H
#define SERVER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class server; }
QT_END_NAMESPACE

class server : public QMainWindow
{
    Q_OBJECT

public:
    server(QWidget *parent = nullptr);
    ~server();

private:
    Ui::server *ui;
};
#endif // SERVER_H
