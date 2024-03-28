#include "a.h"
#include <QDebug>

A::A(QObject *parent) : QObject(parent)
{
}

A::~A()
{
    qDebug() << Q_FUNC_INFO;
}

void A::initSerialPort()
{
    sp = new QSerialPort;
    sp->setBaudRate(QSerialPort::Baud9600);
    sp->setDataBits(QSerialPort::Data8);
    sp->setParity(QSerialPort::NoParity);
    sp->setStopBits(QSerialPort::OneStop);
    sp->setFlowControl(QSerialPort::NoFlowControl);
    sp->setReadBufferSize(10);
    sp->setPortName("COM21");
    connect(sp, &QSerialPort::readyRead, this, &A::handleReadyRead);
    sp->open(QIODevice::ReadWrite);
}

void A::handleReadyRead()
{
    byteRead += sp->readAll();
    while (sp->waitForReadyRead(10) == true) {
        byteRead += sp->readAll();
    }
    qDebug() << byteRead;
    byteRead.clear();
}
