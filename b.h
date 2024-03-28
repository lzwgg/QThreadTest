#ifndef B_H
#define B_H

#include <QObject>
#include <QTcpSocket>

class B : public QObject
{
    Q_OBJECT
    QTcpSocket *tcp;//tcp 本来就是异步处理的,并不需要放在子线程处理
public:
    explicit B(QObject *parent = nullptr);
    ~B();
public slots:
    void initTCP();
    void handleTCPStateChanged(QAbstractSocket::SocketState socketState);
signals:

};

#endif // B_H
