#include "cgpgif.h"
#include <QtGui>
#include <QDialog>

CGpgIf::CGpgIf()
{
}
QString CGpgIf::gpgExecute(QStringList *parameterList)
{
    QString result;
    QProcess coprocess;
    coprocess.setProcessChannelMode(QProcess::MergedChannels);
    //coprocess.setStandardOutputFile("c:/gnu/stdout.txt", QIODevice::Append);
    //coprocess.setStandardErrorFile("c:/gnu/stderr.txt", QIODevice::Append);

    coprocess.start("c:/gnu/gnupg/gpg.exe", *parameterList);
    //coprocess.start("c:/gnu/gnupg/gpg.exe", QStringList() << "--verbose" << "--import" << fileName);
    //coprocess.start("c:/gnu/gnupg/gpg.exe", QStringList() << "-n" << "--verbose" << "--import" << fileName);
    //coprocess.start("c:/gnu/gnupg/gpg.exe", QStringList() << "--batch" << "--interactive" << "--import" << fileName);

    //coprocess.start("c:/gnu/gnupg/gpg.exe", QStringList() << "--fingerprint" << uid);
    //coprocess.start("c:/gnu/gnupg/gpg.exe", QStringList() << "--list_sigs" << uid);
    //coprocess.start("c:/gnu/gnupg/gpg.exe", QStringList() << "--batch" << "--yes" << "--delete-keys" << uid);
    if (coprocess.waitForStarted()){
        if (!coprocess.waitForFinished()){
            QMessageBox::information(this, tr("Information"), QString(coprocess.errorString()));
        }
        else{
            result = QString(coprocess.readAll());
        }
    }
    else{
        QString errmsg = coprocess.errorString();
        QMessageBox::StandardButton reply;
        reply = QMessageBox::critical(this, tr("Error"),
                                        tr("Can't start GNU PG"),
                                        QMessageBox::Abort);
        if (reply == QMessageBox::Abort){
            close();
        }
    }
    return result;
}
