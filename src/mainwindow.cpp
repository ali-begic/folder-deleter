#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    QString statusBarMessage = "Folder Deleter - by AliTech Works v1.0";
    ui->statusBar->setSizeGripEnabled(false);
    ui->statusBar->setStyleSheet("border-top: 1px outset grey;");
    ui->statusBar->showMessage(statusBarMessage);

    ui->deleteInSubfolders_checkBox->setCheckState(Qt::Checked);
    ui->askBeforeDeletion_checkBox->setCheckState(Qt::Checked);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_select_pushButton_clicked() {
    QString folderPath = QFileDialog::getExistingDirectory(this, tr("Select Folder"), QDir::homePath());

    if (!folderPath.isEmpty()) {
        ui->folderName_lineEdit->setText(QFileInfo(folderPath).fileName());

        if (ui->folderDestination_lineEdit->text() == "")
            ui->folderDestination_lineEdit->setText(QFileInfo(folderPath).absolutePath());
    }
}


void MainWindow::on_browse_pushButton_clicked() {
    QString destinationPath = QFileDialog::getExistingDirectory(this, tr("Select Destination"), QDir::homePath());

    if (!destinationPath.isEmpty()) {
        ui->folderDestination_lineEdit->setText(destinationPath);
    }
}


void MainWindow::on_delete_pushButton_clicked() {
    QString folderName = ui->folderName_lineEdit->text();
    QString destinationPath = ui->folderDestination_lineEdit->text();

    if (folderName.isEmpty() || destinationPath.isEmpty()) {
        QMessageBox::warning(this, tr("Warning"), tr("Please specify both folder name and destination path."));

        return;
    }

    QString confirmationMessage;

    if (ui->deleteInSubfolders_checkBox->isChecked()) {
        confirmationMessage = tr("Are you sure you want to delete the folder \"%1\" in the path \"%2\" and in all of the subfolders of the given path?")
                                  .arg(folderName, destinationPath);
    } else {
        confirmationMessage = tr("Are you sure you want to delete the folder \"%1\" in the path \"%2\"?")
                                  .arg(folderName, destinationPath);
    }

    QMessageBox::StandardButton reply = QMessageBox::question(
        this, tr("Confirm Deletion"),
        confirmationMessage,
        QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::No) {
        return;
    }

    bool folderFound = false;
    bool success = deleteFolder(folderName, destinationPath, folderFound);

    if (folderFound) {
        if (success) {
            QMessageBox::information(this, tr("Success"), tr("All specified folders were successfully deleted."));
        } else {
            QMessageBox::warning(this, tr("Partial Success"), tr("Some folders could not be deleted. Check the warnings for more details."));
        }
    } else {
        QMessageBox::warning(this, tr("Folder Not Found"), tr("No such folder \"%1\" found in the given destination or subfolders.").arg(folderName));
    }
}
