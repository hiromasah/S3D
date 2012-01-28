#ifndef CGPGEXEC_H
#define CGPGEXEC_H

#include <QtGui/QDialog>
#include "mainwindow.h"

namespace Ui {
    class CGpgExec;
}

class CGpgExec : public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(CGpgExec)
public:
    explicit CGpgExec(QWidget *parent = 0);
    virtual ~CGpgExec();
    bool gpgExecute(QString request, QString param1, QString param2, QString *result);

protected:
    virtual void changeEvent(QEvent *e);

private:
    Ui::CGpgExec *m_ui;
    MainWindow *wparent;
    QString pathToGnuPG;
    QString processExecutionTimeoutSeconds;

};

#endif // CGPGEXEC_H
