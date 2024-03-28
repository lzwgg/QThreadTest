#ifndef A_H
#define A_H

#include <QObject>
#include <QSerialPort>

class A : public QObject
{
    Q_OBJECT
    QSerialPort *sp; // 异步处理的串口不需要放子线程,同步处理的需要
    QByteArray byteRead;
public:
    explicit A(QObject *parent = nullptr);
    ~A();
public slots:
    void initSerialPort();
    void handleReadyRead();
signals:

};

#endif // A_H
