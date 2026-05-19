//
// Created by austincrane on 2026/5/19.
//

// You may need to build the project (run Qt uic code generator) to get "ui_textGetter.h" resolved

#include "../headerFile/textGetter.h"
#include "ui_textGetter.h"
#include<QFileDialog>
#include<QFile>
#include<QStringConverter>
textGetter::textGetter(QWidget *parent) : QWidget(parent), ui(new Ui::textGetter) {
    ui->setupUi(this);
    connect(ui->commitButton,&QPushButton::clicked,[this]() {
        //打开此电脑，获取需要打开的文件目录
        QString path = QFileDialog::getOpenFileName(this,"C:\\Users\\austincrane");
        //设置编辑line内容为目标文件目录
        ui->FileGet->setText(path);


        //将目录放入file流
        QFile file(path);
        //确定文件读取形式
        file.open(QIODevice::ReadOnly);



        //读取文件内容，用byte数组存储
        QByteArray textArray= file.readAll();
        //将文件内容转为utf8格式
        QString textReal = QString::fromUtf8(textArray);
        //在界面进行输出
        ui->textEdit->setText(textArray);
    });
}

textGetter::~textGetter() {
    delete ui;
}
