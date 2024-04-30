#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include "./ui_startwindow.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class StartWindow; }
QT_END_NAMESPACE

class StartWindow : public QMainWindow
{
    Q_OBJECT
public:
    StartWindow(QWidget *parent = nullptr);
    ~StartWindow();
    void open();
signals:
    void languageSelected(QString language);
private slots:
    void on_RussianButton_clicked();
    void on_UkrainianButton_clicked();
    void on_BritishButton_clicked();
private:
    Ui::StartWindow *ui;
};

#endif
