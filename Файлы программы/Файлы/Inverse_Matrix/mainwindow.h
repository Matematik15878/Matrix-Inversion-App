#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include "squarematrix.h"

using namespace std;

namespace Ui
{
class MainWindow;
class Matrices;
}

class Matrices
{
protected:
    vector<vector<QLineEdit*>> numberInputFieldsN;
    vector<vector<QLineEdit*>> numberInputFieldsI;
    int dimension = 10;
public:
    void showmatrix(int);
    void hideall();
    void fillMatrix(double**);
};

class MainWindow : public QMainWindow, public Matrices
{
    Q_OBJECT
public:
    // Constructors and destructors
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    // visual changes
    void open(QString&);
    void outputDet(double);
    void outputMatrix(double**);
    void outputCount(unsigned int);
    // getters
    int getdimension();
    int getmethod();
    // Error message
    QMessageBox m_errorMessageBox;
signals:
    void StartSolving();
    void StartRandomize();
private slots:
    void handleComboBoxMethodChanged(int);
    void handleComboBoxIndexChanged(int);
    void on_pushButton_clicked();
    void on_Randomize_clicked();
    void on_Save_clicked();
private:
    QLineEdit *numberInputField1;
    QLineEdit *numberInputField2;
    friend SquareMatrix;
    Ui::MainWindow *ui;
    int method = 1;
};

#endif
