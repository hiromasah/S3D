#include "cgpgexec.h"
#include "ui_cgpgexec.h"
#include <QtGui>
#include <QDialog>

CGpgExec::CGpgExec(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::CGpgExec)
{
    wparent = (MainWindow *)parent;
    pathToGnuPG = wparent->pathToGnuPG;
    processExecutionTimeoutSeconds = wparent->processExecutionTimeoutSeconds;

    m_ui->setupUi(this);
}

CGpgExec::~CGpgExec()
{
    delete m_ui;
}

void CGpgExec::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

bool CGpgExec::gpgExecute(QString request, QString param1, QString param2, QString *result)
{
    QTextCodec *codec = QTextCodec::codecForName("Shift-JIS");
    QTextDecoder *decoder = codec->makeDecoder();

    QString cmdPath = pathToGnuPG;
    QProcess coprocess;
    QString filePath;
    QString keyid;
    bool stat = false;

    coprocess.setProcessChannelMode(QProcess::MergedChannels);

    if(request == "decrypt"){
        filePath = param1;
        QString outfilePath = param2;
        QProcess coprocess1;
        coprocess1.setStandardOutputProcess(&coprocess);
        coprocess1.start("cmd.exe", QStringList() << "/c" << "echo" << wparent->passphrase);
        coprocess.start(cmdPath, QStringList() << "--output" << outfilePath << "--passphrase-fd" << "0" << filePath);

        if (coprocess.waitForStarted()){
            int timeoutSec = 60;
            if(! processExecutionTimeoutSeconds.isEmpty()){
                bool ok;
                timeoutSec = processExecutionTimeoutSeconds.toInt(&ok, 10);
                if(timeoutSec == 0){
                    timeoutSec = 60;
                }
            }
            if (!coprocess.waitForFinished(timeoutSec * 1000)){
                QMessageBox::information(this, tr("Confirm"), decoder->toUnicode(coprocess.readAll()));
            }
            else{
                *result = QString(coprocess.readAll());
                if((result->indexOf("復号に失敗しました") >= 0) ||
                   (result->indexOf("decryption failed") >= 0) ||
                   (result->indexOf("有効なOpenPGPデータが見つかりません") >= 0) ||
                   (result->indexOf("no valid OpenPGP data found") >= 0)){
                    stat = false;
                }
                else{
                    stat = true;
                }
            }
        }
        else{
            QString errmsg = coprocess.errorString();
            QMessageBox::StandardButton reply;
            reply = QMessageBox::critical(this, tr("Error"),
                                            tr("Can't start GNU PG."),
                                            QMessageBox::Abort);
            if (reply == QMessageBox::Abort){
                close();
            }
        }
    }
    return stat;
}

