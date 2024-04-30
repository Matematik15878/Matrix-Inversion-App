#include "startwindow.h"
#include "mainwindow.h"
#include "squarematrix.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Application language selection window
    StartWindow ChooseLanguageWindow;
    ChooseLanguageWindow.open();
    // Application main window
    MainWindow InversionMatrixWindow;

    // Language chosen
    QObject::connect(&ChooseLanguageWindow, &StartWindow::languageSelected,
                     [&ChooseLanguageWindow, &InversionMatrixWindow](QString language) {
        // Files
        QString projectPath = QCoreApplication::applicationDirPath();
        QString LanguagePath = projectPath + "/" + language + ".txt";
        // Open Matrix Inversion window
        InversionMatrixWindow.open(LanguagePath);
        InversionMatrixWindow.showmatrix(10);
        InversionMatrixWindow.outputCount(0);
        InversionMatrixWindow.outputDet(0);
        // Close Language Choose window
        ChooseLanguageWindow.close();
    });

    // Initial matrix
    SquareMatrix* Matrix = nullptr;

    // Start button
    QObject::connect(&InversionMatrixWindow, &MainWindow::StartSolving,
                     [&InversionMatrixWindow, &Matrix]() {
        // info about matrix
        int dimension = InversionMatrixWindow.getdimension();
        int method = InversionMatrixWindow.getmethod();
        // Initialize matrix
        Matrix = new SquareMatrix(dimension);
        // Create initial and inversed matrices
        double** inversedmatrix;
        double** matrix = new double*[dimension];
        for (int i = 0; i < dimension; i++) {
             matrix[i] = new double[dimension];
        }
        // Fill initial matrix
        InversionMatrixWindow.fillMatrix(matrix);
        Matrix->setmatrix(matrix);
        // Find determinant
        Matrix->findDet();
        double determinant = Matrix->GetDet();
        // Is matrix reversable?
        if ((determinant != 0) && (!isnan(determinant))) {
             // Use chosen method to inverse
             if (method == 1) inversedmatrix = Matrix->LUPd();
             else inversedmatrix = Matrix->JGMethod();
             // isnan on the main diagonal?
             bool markerInv = Matrix->isInversable(inversedmatrix);
             if (markerInv) {
                 // Print determinant
                 InversionMatrixWindow.outputDet(determinant);
                 // Print inversed matrix
                 InversionMatrixWindow.outputMatrix(inversedmatrix);
                 // Print counter
                 InversionMatrixWindow.outputCount(Matrix->getCounter());
             }
             else {
                 // Error
                 InversionMatrixWindow.m_errorMessageBox.exec();
             }
        }
        else {
             // Error
             InversionMatrixWindow.m_errorMessageBox.exec();
        }
    });

    // End
    return a.exec();
}
