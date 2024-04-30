#include "squarematrix.h"

// Constructors and destructors
SquareMatrix::SquareMatrix(int d) : dimension(d)
{
    matrix = new double*[dimension];
    for (int i = 0; i < dimension; i++) {
        matrix[i] = new double[dimension];
    }
}
SquareMatrix::~SquareMatrix()
{
    //
    for (int i = 0; i < dimension; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}
// Matrix setter
void SquareMatrix::setmatrix(double** temp)
{
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            matrix[i][j] = temp[i][j];
        }
    }
}
// Matrix Inversion Methods
double** SquareMatrix::LUPd()
{
    // LUP
    double** L = new double*[dimension];
    double** U = new double*[dimension];
    int* P = new int[dimension];
    // Inverted matrix
    double** invMatrix = new double*[dimension];
    // Counter
    counter = 0;
    for (int i = 0; i < dimension; i++) {
        L[i] = new double[dimension];
        U[i] = new double[dimension];
        invMatrix[i] = new double[dimension];
        for (int j = 0; j < dimension; j++) {
            L[i][j] = 0.0;
            U[i][j] = matrix[i][j];
            invMatrix[i][j] = 0.0;
        }
    }
    for (int i = 0; i < dimension; i++) {
        P[i] = i;
    }
    for (int k = 0; k < dimension; k++) {
        int pivotRow = k;
        double pivot = abs(U[k][k]);
        for (int i = k + 1; i < dimension; i++) {
            if (abs(U[i][k]) > pivot) {
                pivotRow = i;
                pivot = abs(U[i][k]);
                counter++;
            }
        }
        swap(P[k], P[pivotRow]);
        swap(U[k], U[pivotRow]);
        swap(L[k], L[pivotRow]);
        for (int i = k + 1; i < dimension; i++) {
            L[i][k] = U[i][k] / U[k][k];
            for (int j = k + 1; j < dimension; j++) {
                U[i][j] -= L[i][k] * U[k][j];
                counter++;
            }
        }
    }
    for (int i = 0; i < dimension; i++) {
        double* e = new double[dimension];
        for (int j = 0; j < dimension; j++) {
            e[j] = 0.0;
        }
        e[i] = 1.0;
        double* y = new double[dimension];
        double* x = new double[dimension];
        for (int j = 0; j < dimension; j++) {
            y[j] = e[P[j]];
            for (int k = 0; k < j; k++) {
                y[j] -= L[j][k] * y[k];
                counter += 1;
            }
        }
        for (int j = dimension - 1; j >= 0; j--) {
            x[j] = y[j];
            for (int k = j + 1; k < dimension; k++) {
                x[j] -= U[j][k] * x[k];
                counter += 1;
            }
            x[j] /= U[j][j];
        }
        for (int j = 0; j < dimension; j++) {
            invMatrix[j][i] = x[j];
        }
        delete[] e;
        delete[] y;
        delete[] x;
    }

    // Free memory
    for (int i = 0; i < dimension; i++) {
        delete[] L[i];
        delete[] U[i];
    }
    delete[] L;
    delete[] U;
    delete[] P;

    return invMatrix;
}
double** SquareMatrix::JGMethod() {
    double ratio;
    int i, j, k;
    counter = 0;
    // Inverted matrix
    double** invmatrix = new double*[dimension];
    for (i = 0; i < dimension; i++) {
        invmatrix[i] = new double[dimension];
    }
    for (i = 0; i < dimension; i++) {
        for (j = 0; j < dimension; j++) {
            if (i == j) {
                invmatrix[i][j] = 1;
            }
            else {
                invmatrix[i][j] = 0;
            }
        }
    }
    // Jordan-Gauss  Elimination
    for (i = 0; i < dimension; i++) {
        for (j = 0; j < dimension; j++) {
            if (i != j) {
                ratio = matrix[j][i] / matrix[i][i];
                if (ratio != 1) {
                    for (k = 0; k < dimension; k++) {
                    invmatrix[j][k] = invmatrix[j][k] - ratio * invmatrix[i][k];
                    matrix[j][k] = matrix[j][k] - ratio*matrix[i][k];
                    counter++;
                    }
                }
            }
        }
    }
    // Row Operation
    for (i = 0; i < dimension; i++) {
        for (j = 0; j < dimension; j++) {
            invmatrix[i][j] = invmatrix[i][j] / matrix[i][i];
            counter++;
        }
    }
    // Free memory
    for (i = 0; i < dimension; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return invmatrix;
}
// Determinant methods
void SquareMatrix::findDet()
{
    // Gauss method
    double **tempMatrix = new double*[dimension];
    for (int i = 0; i < dimension; i++) {
        tempMatrix[i] = new double[dimension];
        for (int j = 0; j < dimension; j++) {
            tempMatrix[i][j] = matrix[i][j];
        }
    }
    for (int i = 0; i < dimension - 1; i++) {
        for (int j = i + 1; j < dimension; j++) {
            double factor = tempMatrix[j][i] / tempMatrix[i][i];
            for (int k = i; k < dimension; k++) {
                tempMatrix[j][k] -= factor * tempMatrix[i][k];
            }
        }
    }
    determinant = 1;
    for (int i = 0; i < dimension; i++) {
        determinant *= tempMatrix[i][i];
    }
    // Free memory
    for (int i = 0; i < dimension; i++) {
        delete[] tempMatrix[i];
    }
    delete[] tempMatrix;
}
double SquareMatrix::GetDet()
{ return determinant; }
// Steps getter
unsigned int SquareMatrix::getCounter()
{
    return counter;
}
// Reversibility test
bool SquareMatrix::isInversable(double** inversed) {
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            if (isnan(inversed[i][j])) return false;
        }
    }
    return true;
}
