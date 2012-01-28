/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Sun Jul 12 13:42:21 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionUser_Information;
    QAction *actionAddress_Book;
    QAction *action_Add;
    QAction *action_Exit;
    QAction *actionDelete;
    QAction *action_About;
    QAction *actionHelp;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout1;
    QPushButton *pushButton_Delete;
    QPushButton *pushButton_Add;
    QListWidget *listWidget;
    QLineEdit *labelFileStatus;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout2;
    QLineEdit *lineEdit_OutputFolder;
    QPushButton *pushButton_Ref;
    QPushButton *pushButton_Exit;
    QPushButton *pushButton_Encrypt;
    QSpacerItem *verticalSpacer;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(680, 569);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setAcceptDrops(false);
        QIcon icon;
        icon.addPixmap(QPixmap(QString::fromUtf8("Briefcase_files.ico")), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionUser_Information = new QAction(MainWindow);
        actionUser_Information->setObjectName(QString::fromUtf8("actionUser_Information"));
        actionAddress_Book = new QAction(MainWindow);
        actionAddress_Book->setObjectName(QString::fromUtf8("actionAddress_Book"));
        action_Add = new QAction(MainWindow);
        action_Add->setObjectName(QString::fromUtf8("action_Add"));
        action_Exit = new QAction(MainWindow);
        action_Exit->setObjectName(QString::fromUtf8("action_Exit"));
        action_Exit->setMenuRole(QAction::TextHeuristicRole);
        actionDelete = new QAction(MainWindow);
        actionDelete->setObjectName(QString::fromUtf8("actionDelete"));
        action_About = new QAction(MainWindow);
        action_About->setObjectName(QString::fromUtf8("action_About"));
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QString::fromUtf8("actionHelp"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setMargin(11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(551, 151));
        groupBox->setSizeIncrement(QSize(0, 0));
        QFont font;
        font.setPointSize(12);
        groupBox->setFont(font);
        groupBox->setContextMenuPolicy(Qt::DefaultContextMenu);
        groupBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        groupBox->setCheckable(false);
        gridLayout1 = new QGridLayout(groupBox);
        gridLayout1->setSpacing(6);
        gridLayout1->setMargin(11);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        pushButton_Delete = new QPushButton(groupBox);
        pushButton_Delete->setObjectName(QString::fromUtf8("pushButton_Delete"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_Delete->sizePolicy().hasHeightForWidth());
        pushButton_Delete->setSizePolicy(sizePolicy1);
        pushButton_Delete->setFont(font);

        gridLayout1->addWidget(pushButton_Delete, 0, 2, 1, 1);

        pushButton_Add = new QPushButton(groupBox);
        pushButton_Add->setObjectName(QString::fromUtf8("pushButton_Add"));
        pushButton_Add->setEnabled(true);
        sizePolicy1.setHeightForWidth(pushButton_Add->sizePolicy().hasHeightForWidth());
        pushButton_Add->setSizePolicy(sizePolicy1);
        pushButton_Add->setSizeIncrement(QSize(0, 0));
        pushButton_Add->setFont(font);

        gridLayout1->addWidget(pushButton_Add, 0, 3, 1, 2);

        listWidget = new QListWidget(groupBox);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        sizePolicy.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy);
        listWidget->setFont(font);
        listWidget->setAcceptDrops(true);
        listWidget->setSelectionMode(QAbstractItemView::MultiSelection);

        gridLayout1->addWidget(listWidget, 1, 0, 1, 5);

        labelFileStatus = new QLineEdit(groupBox);
        labelFileStatus->setObjectName(QString::fromUtf8("labelFileStatus"));
        labelFileStatus->setFont(font);
        labelFileStatus->setReadOnly(true);

        gridLayout1->addWidget(labelFileStatus, 2, 0, 1, 5);


        gridLayout->addWidget(groupBox, 0, 0, 1, 3);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        sizePolicy1.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy1);
        groupBox_3->setFont(font);
        gridLayout2 = new QGridLayout(groupBox_3);
        gridLayout2->setSpacing(6);
        gridLayout2->setMargin(11);
        gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
        lineEdit_OutputFolder = new QLineEdit(groupBox_3);
        lineEdit_OutputFolder->setObjectName(QString::fromUtf8("lineEdit_OutputFolder"));
        sizePolicy1.setHeightForWidth(lineEdit_OutputFolder->sizePolicy().hasHeightForWidth());
        lineEdit_OutputFolder->setSizePolicy(sizePolicy1);
        lineEdit_OutputFolder->setFont(font);

        gridLayout2->addWidget(lineEdit_OutputFolder, 0, 0, 1, 13);

        pushButton_Ref = new QPushButton(groupBox_3);
        pushButton_Ref->setObjectName(QString::fromUtf8("pushButton_Ref"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_Ref->sizePolicy().hasHeightForWidth());
        pushButton_Ref->setSizePolicy(sizePolicy2);
        pushButton_Ref->setFont(font);

        gridLayout2->addWidget(pushButton_Ref, 0, 13, 1, 1);


        gridLayout->addWidget(groupBox_3, 1, 0, 1, 3);

        pushButton_Exit = new QPushButton(centralWidget);
        pushButton_Exit->setObjectName(QString::fromUtf8("pushButton_Exit"));
        sizePolicy1.setHeightForWidth(pushButton_Exit->sizePolicy().hasHeightForWidth());
        pushButton_Exit->setSizePolicy(sizePolicy1);
        pushButton_Exit->setFont(font);

        gridLayout->addWidget(pushButton_Exit, 3, 2, 1, 1);

        pushButton_Encrypt = new QPushButton(centralWidget);
        pushButton_Encrypt->setObjectName(QString::fromUtf8("pushButton_Encrypt"));
        sizePolicy1.setHeightForWidth(pushButton_Encrypt->sizePolicy().hasHeightForWidth());
        pushButton_Encrypt->setSizePolicy(sizePolicy1);
        pushButton_Encrypt->setFont(font);

        gridLayout->addWidget(pushButton_Encrypt, 3, 0, 1, 2);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 680, 18));
        menuBar->setDefaultUp(false);
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(action_Add);
        menuFile->addAction(actionDelete);
        menuFile->addAction(action_Exit);
        menuHelp->addAction(action_About);
        menuHelp->addAction(actionHelp);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "PGencUI", 0, QApplication::UnicodeUTF8));
        actionUser_Information->setText(QApplication::translate("MainWindow", "&User Information", 0, QApplication::UnicodeUTF8));
        actionAddress_Book->setText(QApplication::translate("MainWindow", "&Recipient List", 0, QApplication::UnicodeUTF8));
        action_Add->setText(QApplication::translate("MainWindow", "&Add", 0, QApplication::UnicodeUTF8));
        action_Exit->setText(QApplication::translate("MainWindow", "&Exit", 0, QApplication::UnicodeUTF8));
        actionDelete->setText(QApplication::translate("MainWindow", "&Delete", 0, QApplication::UnicodeUTF8));
        action_About->setText(QApplication::translate("MainWindow", "&About", 0, QApplication::UnicodeUTF8));
        actionHelp->setText(QApplication::translate("MainWindow", "&Help", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Target Files", 0, QApplication::UnicodeUTF8));
        pushButton_Delete->setText(QApplication::translate("MainWindow", "Delete", 0, QApplication::UnicodeUTF8));
        pushButton_Add->setText(QApplication::translate("MainWindow", "Add", 0, QApplication::UnicodeUTF8));
        labelFileStatus->setStyleSheet(QApplication::translate("MainWindow", "background-color: rgb(212, 208, 200);", 0, QApplication::UnicodeUTF8));
        labelFileStatus->setText(QString());
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Output Folder", 0, QApplication::UnicodeUTF8));
        pushButton_Ref->setText(QApplication::translate("MainWindow", "Ref", 0, QApplication::UnicodeUTF8));
        pushButton_Exit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        pushButton_Encrypt->setText(QApplication::translate("MainWindow", "Decrypt", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        menuBar->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        menuFile->setTitle(QApplication::translate("MainWindow", "&File", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "&Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
