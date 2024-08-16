#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow window;

    window.setWindowTitle("Folder Deleter");
    window.setFixedSize(350, 255);

    window.show();
    return app.exec();
}
