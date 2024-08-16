#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_select_pushButton_clicked();

    void on_browse_pushButton_clicked();

    void on_delete_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    bool deleteFolder(const QString &folderName, const QString &destinationPath, bool &folderFound);
};
#endif // MAINWINDOW_H
