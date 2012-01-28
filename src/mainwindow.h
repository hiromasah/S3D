#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include <QtGui/QMainWindow>
#include "formhelp.h"

namespace Ui
{
    class MainWindow;
    class QDragEnterEvent;
    class QDropEvent;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QString pathToGnuPG;
    QString processExecutionTimeoutSeconds;
    QString passphrase;
    QString formalProgramName, programName, programVersion;

private:
    bool CheckPathToGnuPG(QSettings *ini_settings);
    bool isDup(QString fpath);
    void rewriteFileStatus();
    void getTargetFiles(QStringList files);
    bool getTargetFolder(QString folder);
    bool getTargetFile(QString fpath);
    bool moveFilesFromFolderToFolder(QString sfolder, QString dfolder);
    bool removeFolderAndFiles(QString folder);
    bool moveFileToFolderWithConfirm(QString spath, QString dfolder);
    bool copyFileToFile(QString spath, QString dpath);

    Ui::MainWindow *ui;
    FormHelp *formHelp;
    QString openFilesPath;
    QString workingFolder, tgzFname;

private slots:
    void on_actionHelp_triggered();
    void on_action_About_triggered();
    void on_actionDelete_triggered();
    void on_action_Add_triggered();
    void on_pushButton_Encrypt_clicked();
    void on_action_Exit_triggered();
    void on_pushButton_Delete_clicked();
    void on_pushButton_Add_clicked();
    void on_pushButton_Exit_clicked();
    void on_pushButton_Ref_clicked();

protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dropEvent(QDropEvent *event);
    void closeEvent(QCloseEvent *event);
};

#endif // MAINWINDOW_H
