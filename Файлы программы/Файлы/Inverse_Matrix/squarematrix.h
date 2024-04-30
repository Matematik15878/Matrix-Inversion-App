#pragma once

#include <QApplication>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QComboBox>
#include <QLineEdit>
#include <QObject>
#include <QFile>

#include <fstream>
#include <string>
#include <random>
#include <ctime>

using namespace std;

class SquareMatrix {
protected:
    int dimension;
    double **matrix;
    double determinant;
    unsigned int counter;
public:
    // Constructors and destructors
    SquareMatrix(int);
    ~SquareMatrix();
    // Matrix setter
    void setmatrix(double** temp);
    // Matrix Inversion Methods
    double** LUPd();
    double** JGMethod();
    // Determinant methods
    void findDet();
    double GetDet();
    // Steps getter
    unsigned int getCounter();
    // Reversibility test
    bool isInversable(double**);
};

