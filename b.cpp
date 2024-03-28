#include "b.h"

B::B(QObject *parent) : QObject(parent)
{
}

B::~B()
{
    qDebug() << Q_FUNC_INFO;
}

void B::initTCP()
{
    tcp = new QTcpSocket;
    connect(tcp, &QTcpSocket::stateChanged, this, &B::handleTCPStateChanged, Qt::DirectConnection);
    tcp->connectToHost("127.0.0.1", 2334);
}

void B::handleTCPStateChanged(QAbstractSocket::SocketState socketState)
{
    qDebug() << "B: " << socketState;
}
