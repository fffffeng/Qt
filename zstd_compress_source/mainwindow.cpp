#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "AceCompress.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_uncomporessBtn_clicked()
{
    ui->textEdit_2->clear();
    //解压:
    QString str = ui->textEdit->toPlainText();

    QByteArray data(ui->textEdit->toPlainText().toUtf8());

    QByteArray result = AceCompress::zstdDecompress(QByteArray::fromBase64(data));
    if (result.isEmpty()) {
        return;
    }
    ui->textEdit_2->setText(QString(result));
}


void MainWindow::on_compressBtn_clicked()
{
    ui->textEdit_2->clear();
    //压缩
    QString str = ui->textEdit->toPlainText();
    QByteArray data(ui->textEdit->toPlainText().toUtf8());
    QByteArray result = AceCompress::zstdCompress(data).toBase64();

    if (!result.isEmpty()) {
        ui->textEdit_2->setText(QString(result));
    }
}

