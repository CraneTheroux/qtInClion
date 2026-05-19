#include <QApplication>
#include <QPushButton>
#include "textGetter.h"
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    textGetter t;
    t.show();
    return QApplication::exec();
}
