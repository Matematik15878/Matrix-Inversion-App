/********************************************************************************
** Form generated from reading UI file 'startwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTWINDOW_H
#define UI_STARTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartWindow
{
public:
    QWidget *centralwidget;
    QLabel *GreetingText;
    QLabel *Ukrainian;
    QLabel *Russian;
    QLabel *British;
    QPushButton *UkrainianButton;
    QPushButton *RussianButton;
    QPushButton *BritishButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *StartWindow)
    {
        if (StartWindow->objectName().isEmpty())
            StartWindow->setObjectName("StartWindow");
        StartWindow->resize(400, 175);
        StartWindow->setMinimumSize(QSize(400, 175));
        StartWindow->setMaximumSize(QSize(400, 175));
        StartWindow->setIconSize(QSize(36, 36));
        centralwidget = new QWidget(StartWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setBaseSize(QSize(400, 200));
        GreetingText = new QLabel(centralwidget);
        GreetingText->setObjectName("GreetingText");
        GreetingText->setGeometry(QRect(0, 10, 401, 51));
        Ukrainian = new QLabel(centralwidget);
        Ukrainian->setObjectName("Ukrainian");
        Ukrainian->setGeometry(QRect(160, 90, 81, 51));
        Russian = new QLabel(centralwidget);
        Russian->setObjectName("Russian");
        Russian->setGeometry(QRect(270, 90, 81, 51));
        British = new QLabel(centralwidget);
        British->setObjectName("British");
        British->setGeometry(QRect(50, 90, 81, 51));
        UkrainianButton = new QPushButton(centralwidget);
        UkrainianButton->setObjectName("UkrainianButton");
        UkrainianButton->setEnabled(true);
        UkrainianButton->setGeometry(QRect(160, 90, 80, 51));
        UkrainianButton->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"border: none"));
        UkrainianButton->setAutoDefault(false);
        RussianButton = new QPushButton(centralwidget);
        RussianButton->setObjectName("RussianButton");
        RussianButton->setGeometry(QRect(270, 90, 80, 51));
        RussianButton->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"border: none"));
        BritishButton = new QPushButton(centralwidget);
        BritishButton->setObjectName("BritishButton");
        BritishButton->setGeometry(QRect(50, 90, 80, 51));
        BritishButton->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"border: none"));
        StartWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(StartWindow);
        menubar->setObjectName("menubar");
        menubar->setEnabled(false);
        menubar->setGeometry(QRect(0, 0, 400, 21));
        StartWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(StartWindow);
        statusbar->setObjectName("statusbar");
        statusbar->setEnabled(false);
        StartWindow->setStatusBar(statusbar);

        retranslateUi(StartWindow);

        QMetaObject::connectSlotsByName(StartWindow);
    } // setupUi

    void retranslateUi(QMainWindow *StartWindow)
    {
        StartWindow->setWindowTitle(QCoreApplication::translate("StartWindow", "StartWindow", nullptr));
        GreetingText->setText(QCoreApplication::translate("StartWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:700; color:#ffffff;\">Hi! Nice to meet you!</span></p><p align=\"center\"><span style=\" font-size:10pt; color:#ffffff;\">Please, choose your language:</span></p></body></html>", nullptr));
        Ukrainian->setText(QString());
        Russian->setText(QString());
        British->setText(QString());
        UkrainianButton->setText(QString());
        RussianButton->setText(QString());
        BritishButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class StartWindow: public Ui_StartWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTWINDOW_H
