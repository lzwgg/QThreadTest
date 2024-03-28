#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "a.h"
#include "b.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    A *a = new A;
    B *b = new B;

    connect(&thread, &QThread::finished, a, &QObject::deleteLater); // 线程退出时销毁对象a
    connect(&thread, &QThread::started, a, &A::initSerialPort); // 线程开始时创建对象a内的指针,以便指针在另一个线程的堆上
    connect(&thread, &QThread::finished, b, &QObject::deleteLater); // 线程退出时销毁对象b
    connect(&thread, &QThread::started, b, &B::initTCP); // 线程开始时创建对象b内的指针,以便指针时在另一个线程的堆上
    a->moveToThread(&thread); // 将对象a的数据移到另一个线程
    b->moveToThread(&thread); // 将对象b的数据移到另一个线程

    thread.start(); // 启动线程
}

MainWindow::~MainWindow()
{
    thread.quit(); // 线程退出
    thread.wait(); // 等待线程数据处理结束
    qDebug() << Q_FUNC_INFO;
    delete ui;
}

