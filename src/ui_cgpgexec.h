/********************************************************************************
** Form generated from reading ui file 'cgpgexec.ui'
**
** Created: Sun Jul 12 13:42:21 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_CGPGEXEC_H
#define UI_CGPGEXEC_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_CGpgExec
{
public:
    QLabel *label;
    QLabel *label_FileName;
    QLabel *label_FileSize;
    QLabel *label_2;

    void setupUi(QDialog *CGpgExec)
    {
        if (CGpgExec->objectName().isEmpty())
            CGpgExec->setObjectName(QString::fromUtf8("CGpgExec"));
        CGpgExec->setEnabled(true);
        CGpgExec->resize(345, 69);
        label = new QLabel(CGpgExec);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 50, 21));
        label_FileName = new QLabel(CGpgExec);
        label_FileName->setObjectName(QString::fromUtf8("label_FileName"));
        label_FileName->setGeometry(QRect(80, 10, 261, 21));
        label_FileName->setAutoFillBackground(false);
        label_FileName->setFrameShape(QFrame::WinPanel);
        label_FileName->setFrameShadow(QFrame::Sunken);
        label_FileSize = new QLabel(CGpgExec);
        label_FileSize->setObjectName(QString::fromUtf8("label_FileSize"));
        label_FileSize->setGeometry(QRect(80, 40, 261, 21));
        label_FileSize->setAutoFillBackground(false);
        label_FileSize->setFrameShape(QFrame::WinPanel);
        label_FileSize->setFrameShadow(QFrame::Sunken);
        label_2 = new QLabel(CGpgExec);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 40, 50, 21));

        retranslateUi(CGpgExec);

        QMetaObject::connectSlotsByName(CGpgExec);
    } // setupUi

    void retranslateUi(QDialog *CGpgExec)
    {
        CGpgExec->setWindowTitle(QApplication::translate("CGpgExec", "GNU PG Executing", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CGpgExec", "File Name", 0, QApplication::UnicodeUTF8));
        label_FileName->setStyleSheet(QString());
        label_FileName->setText(QString());
        label_FileSize->setStyleSheet(QString());
        label_FileSize->setText(QString());
        label_2->setText(QApplication::translate("CGpgExec", "Size", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(CGpgExec);
    } // retranslateUi

};

namespace Ui {
    class CGpgExec: public Ui_CGpgExec {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CGPGEXEC_H
