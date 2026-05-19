//
// Created by austincrane on 2026/5/19.
//

#ifndef QTINCLION2_TEXTGETTER_H
#define QTINCLION2_TEXTGETTER_H

#include <QWidget>


QT_BEGIN_NAMESPACE

namespace Ui {
    class textGetter;
}

QT_END_NAMESPACE

class textGetter : public QWidget {
    Q_OBJECT

public:
    explicit textGetter(QWidget *parent = nullptr);

    ~textGetter() override;

private:
    Ui::textGetter *ui;
};


#endif //QTINCLION2_TEXTGETTER_H
