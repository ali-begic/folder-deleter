#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDir>
#include <QMessageBox>

bool MainWindow::deleteFolder(const QString &folderName, const QString &destinationPath, bool &folderFound) {
    QDir dir(destinationPath);
    bool allDeleted = true;

    // Set the filter for directory listing
    QDir::Filters filters = QDir::Dirs | QDir::NoDotAndDotDot;
    if (ui->deleteHiddenFolders_checkBox->isChecked()) {
        filters |= QDir::Hidden;
    }

    // Include hidden directories based on checkbox state
    QFileInfoList entries = dir.entryInfoList(filters);
    for (const QFileInfo  &entry : entries) {
        if (entry.fileName() == folderName) {
            folderFound = true; // Folder found

            if (ui->askBeforeDeletion_checkBox->isChecked()) {
                QString confirmationMessage;
                if (ui->deleteInSubfolders_checkBox->isChecked()) {
                    confirmationMessage = tr("Are you sure you want to delete the folder \"%1\" in the path \"%2\" and in all of the subfolders of the given path?")
                                              .arg(folderName, destinationPath);
                } else {
                    confirmationMessage = tr("Are you sure you want to delete the folder \"%1\" in the path \"%2\"?")
                                              .arg(entry.fileName(), entry.absoluteFilePath());
                }

                QMessageBox::StandardButton reply = QMessageBox::question(
                    this, tr("Confirm Deletion"),
                    confirmationMessage,
                    QMessageBox::Yes | QMessageBox::No);
                if (reply == QMessageBox::No) {
                    continue;
                }
            }

            QDir folderDir(entry.absoluteFilePath());
            if (!folderDir.removeRecursively()) {
                QMessageBox::warning(this, tr("Deletion Failed"), tr("Failed to delete the folder \"%1\".").arg(entry.absoluteFilePath()));
                allDeleted = false;
            }
        }

        // If delete in subfolders is enabled, recurse into subdirectories
        if (ui->deleteInSubfolders_checkBox->isChecked()) {
            if (!deleteFolder(folderName, entry.absoluteFilePath(), folderFound)) {
                allDeleted = false;
            }
        }
    }

    return allDeleted;
}
