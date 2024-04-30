/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *InfoWindow;
    QLabel *Matrix1;
    QLabel *Matrix2;
    QLabel *text1;
    QLabel *text2;
    QLabel *text3;
    QLabel *text4;
    QLabel *text5;
    QLabel *text6;
    QLabel *text8;
    QLabel *Asymptotic;
    QLabel *MatrixName2;
    QLabel *MatrixName1;
    QLabel *Theory1;
    QLabel *Theory4;
    QLabel *Theory5;
    QLabel *Theory6;
    QLabel *Theory3;
    QLabel *Theory2;
    QPushButton *pushButton;
    QLabel *determinant;
    QPushButton *Randomize;
    QPushButton *Save;
    QLabel *Det;
    QLabel *counter;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setEnabled(true);
        MainWindow->resize(960, 560);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(960, 560));
        MainWindow->setMaximumSize(QSize(960, 560));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        InfoWindow = new QLabel(centralwidget);
        InfoWindow->setObjectName("InfoWindow");
        InfoWindow->setGeometry(QRect(20, 20, 191, 520));
        InfoWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 0);"));
        Matrix1 = new QLabel(centralwidget);
        Matrix1->setObjectName("Matrix1");
        Matrix1->setGeometry(QRect(230, 20, 340, 340));
        Matrix1->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 255, 0);"));
        Matrix2 = new QLabel(centralwidget);
        Matrix2->setObjectName("Matrix2");
        Matrix2->setGeometry(QRect(590, 20, 340, 340));
        Matrix2->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 255, 0);"));
        text1 = new QLabel(centralwidget);
        text1->setObjectName("text1");
        text1->setGeometry(QRect(35, 225, 160, 40));
        text1->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 255, 255);"));
        text2 = new QLabel(centralwidget);
        text2->setObjectName("text2");
        text2->setGeometry(QRect(35, 35, 160, 70));
        text2->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 255, 255);"));
        text3 = new QLabel(centralwidget);
        text3->setObjectName("text3");
        text3->setGeometry(QRect(35, 115, 160, 40));
        text3->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 255, 255);"));
        text4 = new QLabel(centralwidget);
        text4->setObjectName("text4");
        text4->setGeometry(QRect(789, 470, 141, 70));
        text4->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 255, 255);"));
        text5 = new QLabel(centralwidget);
        text5->setObjectName("text5");
        text5->setGeometry(QRect(35, 410, 160, 51));
        text5->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 255, 255);"));
        text6 = new QLabel(centralwidget);
        text6->setObjectName("text6");
        text6->setGeometry(QRect(35, 165, 160, 40));
        text6->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 255, 255);"));
        text8 = new QLabel(centralwidget);
        text8->setObjectName("text8");
        text8->setGeometry(QRect(35, 315, 160, 40));
        text8->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 255, 255);"));
        Asymptotic = new QLabel(centralwidget);
        Asymptotic->setObjectName("Asymptotic");
        Asymptotic->setGeometry(QRect(630, 410, 301, 51));
        Asymptotic->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 41, 3);"));
        MatrixName2 = new QLabel(centralwidget);
        MatrixName2->setObjectName("MatrixName2");
        MatrixName2->setGeometry(QRect(590, 360, 341, 31));
        MatrixName2->setStyleSheet(QString::fromUtf8(""));
        MatrixName1 = new QLabel(centralwidget);
        MatrixName1->setObjectName("MatrixName1");
        MatrixName1->setGeometry(QRect(230, 360, 341, 31));
        Theory1 = new QLabel(centralwidget);
        Theory1->setObjectName("Theory1");
        Theory1->setGeometry(QRect(230, 400, 341, 31));
        Theory1->setStyleSheet(QString::fromUtf8(""));
        Theory4 = new QLabel(centralwidget);
        Theory4->setObjectName("Theory4");
        Theory4->setGeometry(QRect(230, 460, 341, 31));
        Theory5 = new QLabel(centralwidget);
        Theory5->setObjectName("Theory5");
        Theory5->setGeometry(QRect(230, 480, 341, 31));
        Theory6 = new QLabel(centralwidget);
        Theory6->setObjectName("Theory6");
        Theory6->setGeometry(QRect(230, 500, 341, 31));
        Theory3 = new QLabel(centralwidget);
        Theory3->setObjectName("Theory3");
        Theory3->setGeometry(QRect(230, 440, 341, 31));
        Theory2 = new QLabel(centralwidget);
        Theory2->setObjectName("Theory2");
        Theory2->setGeometry(QRect(230, 420, 341, 31));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(789, 470, 141, 70));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);"));
        determinant = new QLabel(centralwidget);
        determinant->setObjectName("determinant");
        determinant->setGeometry(QRect(630, 470, 151, 70));
        determinant->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 255, 127);"));
        Randomize = new QPushButton(centralwidget);
        Randomize->setObjectName("Randomize");
        Randomize->setGeometry(QRect(35, 35, 161, 71));
        Randomize->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);"));
        Save = new QPushButton(centralwidget);
        Save->setObjectName("Save");
        Save->setGeometry(QRect(35, 410, 161, 51));
        Save->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);"));
        Det = new QLabel(centralwidget);
        Det->setObjectName("Det");
        Det->setGeometry(QRect(659, 470, 121, 72));
        counter = new QLabel(centralwidget);
        counter->setObjectName("counter");
        counter->setGeometry(QRect(860, 410, 71, 51));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setEnabled(false);
        menubar->setGeometry(QRect(0, 0, 960, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        statusbar->setEnabled(false);
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        InfoWindow->setText(QString());
        Matrix1->setText(QString());
        Matrix2->setText(QString());
        text1->setText(QString());
        text2->setText(QString());
        text3->setText(QString());
        text4->setText(QString());
        text5->setText(QString());
        text6->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
        text8->setText(QString());
        Asymptotic->setText(QString());
        MatrixName2->setText(QString());
        MatrixName1->setText(QString());
        Theory1->setText(QString());
        Theory4->setText(QString());
        Theory5->setText(QString());
        Theory6->setText(QString());
        Theory3->setText(QString());
        Theory2->setText(QString());
        pushButton->setText(QString());
        determinant->setText(QString());
        Randomize->setText(QString());
        Save->setText(QString());
        Det->setText(QString());
        counter->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
