//
// Created by austincrane on 2026/5/19.
//

// You may need to build the project (run Qt uic code generator) to get "ui_textGetter.h" resolved

#include "../headerFile/textGetter.h"
#include "ui_textGetter.h"
#include<QFileDialog>
#include<QFile>
#include<QFileInfo>
#include<QStringConverter>
textGetter::textGetter(QWidget *parent) : QWidget(parent), ui(new Ui::textGetter) {
    ui->setupUi(this);
    /*
     * 上按钮图案流程：1.在lib文件夹中创建recources.qrc;2.编写qrc文件。3.在cmakelist中添加add_exetuable   lib/resource.qrc
     * 4.使用setIcon方法，文件路径为":/名称.png"
     */
    ui->commitButton->setIcon(QPixmap(":/cat.png"));
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

        file.close();
        //文件大小信息获取方式
        QFileInfo info(path);
        double sizeResultConvertInToMB = info.size()/(1000.0*1000.0);
        qDebug()<<"size:"<<sizeResultConvertInToMB<<",Create date:"<<info.birthTime()<<",type:"<<info.suffix();


    });
}

textGetter::~textGetter() {
    delete ui;
}
