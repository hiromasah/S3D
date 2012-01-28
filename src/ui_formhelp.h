/********************************************************************************
** Form generated from reading ui file 'formhelp.ui'
**
** Created: Sun Jul 12 13:42:21 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_FORMHELP_H
#define UI_FORMHELP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QTextBrowser>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormHelp
{
public:
    QGridLayout *gridLayout;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *FormHelp)
    {
        if (FormHelp->objectName().isEmpty())
            FormHelp->setObjectName(QString::fromUtf8("FormHelp"));
        FormHelp->resize(740, 590);
        QIcon icon;
        icon.addPixmap(QPixmap(QString::fromUtf8("Briefcase_files.ico")), QIcon::Normal, QIcon::Off);
        FormHelp->setWindowIcon(icon);
        gridLayout = new QGridLayout(FormHelp);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        textBrowser = new QTextBrowser(FormHelp);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        gridLayout->addWidget(textBrowser, 0, 0, 1, 1);


        retranslateUi(FormHelp);

        QMetaObject::connectSlotsByName(FormHelp);
    } // setupUi

    void retranslateUi(QWidget *FormHelp)
    {
        FormHelp->setWindowTitle(QApplication::translate("FormHelp", "Form", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(FormHelp);
    } // retranslateUi

};

namespace Ui {
    class FormHelp: public Ui_FormHelp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMHELP_H
