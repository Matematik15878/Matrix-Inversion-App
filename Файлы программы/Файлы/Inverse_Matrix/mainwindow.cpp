 #include "mainwindow.h"

// Constructors and destructors
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Border of random 1
    numberInputField1 = new QLineEdit(this);
    numberInputField1->setGeometry(45, 170, 60, 30);
    // Border of random 2
    numberInputField2 = new QLineEdit(this);
    numberInputField2->setGeometry(125, 170, 60, 30);
    // Combo Box 1
    QComboBox *comboBox = new QComboBox(this);
    comboBox->addItem("10x10");
    comboBox->addItem("9x9");
    comboBox->addItem("8x8");
    comboBox->addItem("7x7");
    comboBox->addItem("6x6");
    comboBox->addItem("5x5");
    comboBox->addItem("4x4");
    comboBox->addItem("3x3");
    comboBox->addItem("2x2");
    comboBox->setGeometry(35, 365, 160, 25);
    connect(comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::handleComboBoxIndexChanged);
    // Combo Box 2
    QComboBox *comboBox2 = new QComboBox(this);
    comboBox2->addItem("LUP decomposition");
    comboBox2->addItem("Jordan-Gauss Method");
    comboBox2->setGeometry(35, 275, 160, 25);
    connect(comboBox2, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::handleComboBoxMethodChanged);
    // Matrixes
    int startX = 236;
    int startY = 27;
    int fieldWidth = 30;
    int fieldHeight = 30;
    numberInputFieldsN.resize(10);
    numberInputFieldsI.resize(10);
    for (int i = 0; i < 10; i++) {
        numberInputFieldsN[i].resize(10);
        numberInputFieldsI[i].resize(10);
        for (int j = 0; j < 10; j++) {
            int x = startX + i * 33;
            int y = startY + j * 33;
            numberInputFieldsN[i][j] = new QLineEdit(this);
            numberInputFieldsI[i][j] = new QLineEdit(this);
            numberInputFieldsN[i][j]->setGeometry(x, y, fieldWidth, fieldHeight);
            numberInputFieldsI[i][j]->setGeometry(x+360, y, fieldWidth, fieldHeight);
            numberInputFieldsI[i][j]->setReadOnly(true);
            numberInputFieldsN[i][j]->setAlignment(Qt::AlignCenter);
            numberInputFieldsI[i][j]->setAlignment(Qt::AlignCenter);
        }
    }
}
MainWindow::~MainWindow()
{
    delete ui;
    delete numberInputField1;
    delete numberInputField2;
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            delete numberInputFieldsN[i][j];
            delete numberInputFieldsI[i][j];
        }
    }
}
// Visual changes
void MainWindow::open(QString& LanguagePath)
{
    // Files
    QFile file(LanguagePath);
    QTextStream languagefile(&file);
    QString projectPath = QCoreApplication::applicationDirPath();
    QIcon logo(projectPath + "/Frog-logo.png");

    // QStrings
    QString title, choosemethod, random, chooserandom, asymptotic, savematrix, start, openmatrix,
        choosedimension, matrix1, matrix2, errormessage,
        Theory1, Theory2, Theory3, Theory4, Theory5, Theory6;

    // Open the file
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    // Read the file
    title = languagefile.readLine();
    choosemethod = languagefile.readLine();
    random = languagefile.readLine();
    chooserandom = languagefile.readLine();
    asymptotic = languagefile.readLine();
    savematrix = languagefile.readLine();
    start = languagefile.readLine();
    openmatrix = languagefile.readLine();
    choosedimension = languagefile.readLine();
    matrix1 = languagefile.readLine();
    matrix2 = languagefile.readLine();
    Theory1 = languagefile.readLine();
    Theory2 = languagefile.readLine();
    Theory3 = languagefile.readLine();
    Theory4 = languagefile.readLine();
    Theory5 = languagefile.readLine();
    Theory6 = languagefile.readLine();
    errormessage = languagefile.readLine();
    // Close the file
    file.close();

    // Application main window settings
    this->setStyleSheet("QMainWindow { border: 5px solid #3c6c14; background-color: #528e37; }");
    this->setWindowTitle(title);
    this->setWindowIcon(logo);
    this->resize(960, 560);

    //
    this->m_errorMessageBox.setText(errormessage);
    m_errorMessageBox.setWindowIcon(logo);
    m_errorMessageBox.setIcon(QMessageBox::Critical);
    m_errorMessageBox.setWindowFlags(Qt::Window | Qt::WindowStaysOnTopHint);

    // InfoWindow + Matrices
    QLabel *InfoWindow = this->findChild<QLabel*>("InfoWindow");
    InfoWindow->setStyleSheet("QLabel { border-radius: 8px; border: 3px solid #3b792c; background-color: #e6e6e9; }");
    QLabel *Matrix1 = this->findChild<QLabel*>("Matrix1");
    Matrix1->setStyleSheet("QLabel { border-radius: 8px; border: 3px solid #3b792c; background-color: #e6e6e9; }");
    QLabel *Matrix2 = this->findChild<QLabel*>("Matrix2");
    Matrix2->setStyleSheet("QLabel { border-radius: 8px; border: 3px solid #3b792c; background-color: #e6e6e9; }");
    // text1
    QLabel *text1 = this->findChild<QLabel*>("text1");
    text1->setStyleSheet("QLabel { background-color: #62c361; border-radius: 8px; text-align: center;"
                         "color: #f8ffc3; font-size: 14px; font-weight:bold; }");
    text1->setText("<center>" + choosemethod + "</center>");
    // text2
    QLabel *text2 = this->findChild<QLabel*>("text2");
    text2->setStyleSheet("QLabel { background-color: #62c361; border-radius: 8px; text-align: center;"
                         "color: #cd503d; font-size: 14px; font-weight:bold; }");
    text2->setText("<center>" + random + "</center>");
    text2->setWordWrap(true);
    // text3
    QLabel *text3 = this->findChild<QLabel*>("text3");
    text3->setStyleSheet("QLabel { background-color: #62c361; border-radius: 8px; text-align: center;"
                         "color: #f8ffc3; font-size: 14px; font-weight:bold; }");
    text3->setText("<center>" + chooserandom + "</center>");
    text3->setWordWrap(true);
    // text4
    QLabel *text4 = this->findChild<QLabel*>("text4");
    text4->setStyleSheet("QLabel { border-radius: 8px; border: 3px solid #3b792c; background-color: #e6e6e9; text-align: center;"
                         "color: #346eb4; font-size: 20px; font-weight:bold; }");
    text4->setAlignment(Qt::AlignCenter);
    text4->setWordWrap(true);
    text4->setText(start);
    // text5
    QLabel *text5 = this->findChild<QLabel*>("text5");
    text5->setStyleSheet("QLabel { background-color: #62c361; border-radius: 8px; text-align: center;"
                         "color: #cd503d; font-size: 14px; font-weight:bold; }");
    text5->setAlignment(Qt::AlignCenter);
    text5->setWordWrap(true);
    text5->setText(savematrix);
    // text6
    QLabel *text6 = this->findChild<QLabel*>("text6");
    text6->setStyleSheet("QLabel { background-color: #62c361; border-radius: 8px; text-align: center;"
                         "color: #f8ffc3; font-size: 14px; font-weight:bold; }");
    text6->setAlignment(Qt::AlignCenter);
    text6->setWordWrap(true);
    text6->setText("-");
    // text8
    QLabel *text8 = this->findChild<QLabel*>("text8");
    text8->setStyleSheet("QLabel { background-color: #62c361; border-radius: 8px; text-align: center;"
                         "color: #f8ffc3; font-size: 14px; font-weight:bold; }");
    text8->setText("<center>" + choosedimension + "</center>");
    // Asymptotic
    QLabel *Asymptotic = this->findChild<QLabel*>("Asymptotic");
    Asymptotic->setStyleSheet("QLabel { border-radius: 8px; border: 3px solid #3b792c; background-color: #e6e6e9;"
                              "text-align: center; color: #346eb4; font-size: 13px; font-weight:bold; padding-left: 5px;}");
    Asymptotic->setText(asymptotic);
    // MatrixName1
    QLabel *MatrixName1 = this->findChild<QLabel*>("MatrixName1");
    MatrixName1->setStyleSheet("QLabel { background-color: rgba(255, 255, 255, 0); text-align: center; color: #f8ffc3; "
                               "font-size: 14px; font-weight: bold; font-family: Times New Roman; }");
    MatrixName1->setText("<center>" + matrix1 + "</center>");
    // MatrixName2
    QLabel *MatrixName2 = this->findChild<QLabel*>("MatrixName2");
    MatrixName2->setStyleSheet("QLabel { background-color: rgba(255, 255, 255, 0); text-align: center; color: #f8ffc3; "
                               "font-size: 14px; font-weight: bold; font-family: Times New Roman; }");
    MatrixName2->setText("<center>" + matrix2 + "</center>");
    // Theory labels
    QLabel *Theory1l = this->findChild<QLabel*>("Theory1");
    Theory1l->setStyleSheet("QLabel { background-color: rgba(255, 255, 255, 0); text-align: center; color: #e3e380; "
                            "font-size: 15px; font-weight: bold; font-family: Times New Roman; padding-left: 5px;}");
    Theory1l->setText(Theory1);
    QLabel *Theory2l = this->findChild<QLabel*>("Theory2");
    Theory2l->setStyleSheet("QLabel { background-color: rgba(255, 255, 255, 0); text-align: center; color: #e3e380; "
                            "font-size: 15px; font-weight: bold; font-family: Times New Roman; padding-left: 5px;}");
    Theory2l->setText(Theory2);
    QLabel *Theory3l = this->findChild<QLabel*>("Theory3");
    Theory3l->setStyleSheet("QLabel { background-color: rgba(255, 255, 255, 0); text-align: center; color: #e3e380; "
                            "font-size: 15px; font-weight: bold; font-family: Times New Roman; padding-left: 5px;}");
    Theory3l->setText(Theory3);
    QLabel *Theory4l = this->findChild<QLabel*>("Theory4");
    Theory4l->setStyleSheet("QLabel { background-color: rgba(255, 255, 255, 0); text-align: center; color: #e3e380; "
                            "font-size: 15px; font-weight: bold; font-family: Times New Roman; padding-left: 5px;}");
    Theory4l->setText(Theory4);
    QLabel *Theory5l = this->findChild<QLabel*>("Theory5");
    Theory5l->setStyleSheet("QLabel { background-color: rgba(255, 255, 255, 0); text-align: center; color: #e3e380; "
                            "font-size: 15px; font-weight: bold; font-family: Times New Roman; padding-left: 5px;}");
    Theory5l->setText(Theory5);
    QLabel *Theory6l = this->findChild<QLabel*>("Theory6");
    Theory6l->setStyleSheet("QLabel { background-color: rgba(255, 255, 255, 0); text-align: center; color: #e3e380; "
                            "font-size: 15px; font-weight: bold; font-family: Times New Roman; padding-left: 5px;}");
    Theory6l->setText(Theory6);
    // determinant
    QLabel *determinant = this->findChild<QLabel*>("determinant");
    determinant->setStyleSheet("QLabel { border-radius: 8px; border: 3px solid #3b792c; background-color: #e6e6e9; text-align: center;"
                               "color: #346eb4; font-size: 14px; font-weight:bold; padding-left: 5px; }");
    determinant->setText("det = ");

    // Show the window
    this->show();
}
void MainWindow::outputDet(double det)
{
    QLabel *Det = this->findChild<QLabel*>("Det");
    Det->setStyleSheet("QLabel { text-align: center; color: #346eb4; font-size: 14px; font-weight:bold; padding-left: 7px;}");
    Det->setText("<center>" + QString::number(det) + "</center>");

}
void MainWindow::outputMatrix(double** matrix)
{
    for (int i = 0; i < dimension; ++i)
    {
        for (int j = 0; j < dimension; ++j)
        {
            numberInputFieldsI[i][j]->setText(QString::number(matrix[i][j]));
        }
    }
}
void MainWindow::outputCount(unsigned int steps)
{
    QLabel *counter = this->findChild<QLabel*>("counter");
    counter->setStyleSheet("QLabel { text-align: center; color: #346eb4; font-size: 14px; font-weight:bold; padding-left: 10px;}");
    counter->setText(QString::number(steps));

}
// Getters
int MainWindow::getdimension()
{
    return dimension;
}
int MainWindow::getmethod()
{
    return method;
}
// Private slots
void MainWindow::handleComboBoxMethodChanged(int method)
{
    QComboBox* comboBox = qobject_cast<QComboBox*>(sender());
    if (comboBox) {
        QString selectedMethod = comboBox->currentText();
        if (selectedMethod == "LUP decomposition") { this->method = 1; }
        else if (selectedMethod == "Jordan-Gauss Method") { this->method = 2; }
    }
}
void MainWindow::handleComboBoxIndexChanged(int index)
{
    QComboBox *comboBox = qobject_cast<QComboBox*>(sender());
    std::string selectedText = std::string(comboBox->currentText().toUtf8().constData());
    this->dimension = std::stoi(selectedText.substr(0, selectedText.find('x')));
    this->showmatrix(dimension);
}
void MainWindow::on_pushButton_clicked()
{
    emit StartSolving();
}
void MainWindow::on_Randomize_clicked()
{
    srand(time(nullptr));
    double lower, upper;
    lower = numberInputField1->text().toDouble();
    upper = numberInputField2->text().toDouble();
    if (lower > upper) {
        lower += upper;
        upper = lower - upper;
        lower -= upper;
    }
    for (int i = 0; i < dimension; ++i)
    {
        for (int j = 0; j < dimension; ++j)
        {
            if (((int)upper == upper) && ((int)lower == lower)) {
                numberInputFieldsN[i][j]->setText(QString::number(rand() % (int)(upper - lower + 1) + (int)lower));
            }
            else {
                numberInputFieldsN[i][j]->setText(QString::number((double) rand() / RAND_MAX * (upper - lower + 1) + lower));
            }
        }
    }
}
void MainWindow::on_Save_clicked()
{
    ofstream localfile("saved.txt");
    QLabel *Det = this->findChild<QLabel*>("Det");
    QString det = (Det->text());
    localfile << dimension << " \n";
    localfile << det.toStdString() << " \n";
    for (int i = 0; i < dimension; ++i)
    {
        for (int j = 0; j < dimension; ++j)
        {
            localfile << numberInputFieldsN[j][i]->text().toDouble() << " ";
        }
        localfile << " \n";
    }
    localfile << "\n";
    for (int i = 0; i < dimension; ++i)
    {
        for (int j = 0; j < dimension; ++j)
        {
            localfile << numberInputFieldsI[j][i]->text().toDouble() << " ";
        }
        localfile << " \n";
    }
}

// Matrices
void Matrices::fillMatrix(double** matrix)
{
    for (int i = 0; i < dimension; ++i)
    {
        for (int j = 0; j < dimension; ++j)
        {
            matrix[i][j] = numberInputFieldsN[i][j]->text().toDouble();
            string str = numberInputFieldsN[i][j]->text().toStdString();
            for (char c : str) {
                if (!isdigit(c) && c != '.' && c != '-') {
                    matrix[i][j] = numeric_limits<double>::quiet_NaN();
                }
            }
        }
    }
}
void Matrices::showmatrix(int amount)
{
    this->hideall();
    int startX = 236;
    int startY = 26;
    double position, size, fontsize;
    switch (amount) {
    case 10:
        position = 33;
        size = 30;
        fontsize = 8;
        break;
    case 9:
        position = 36.8;
        size = 33.8;
        fontsize = 9.5;
        break;
    case 8:
        position = 41.5;
        size = 37.5;
        fontsize = 11;
        break;
    case 7:
        position = 47.4;
        size = 43.4;
        fontsize = 12;
        break;
    case 6:
        position = 55.5;
        size = 50;
        fontsize = 13;
        break;
    case 5:
        position = 66.5;
        size = 62;
        fontsize = 14;
        break;
    case 4:
        position = 83;
        size = 78;
        fontsize = 15;
        break;
    case 3:
        position = 112;
        size = 104;
        fontsize = 17;
        break;
    case 2:
        position = 167;
        size = 161;
        fontsize = 18;
        break;
    }
    QFont font("Arial", fontsize);
    for (int i = 0; i < amount; ++i)
    {
        numberInputFieldsN.resize(10);
        numberInputFieldsI.resize(10);
        for (int j = 0; j < amount; ++j)
        {
            numberInputFieldsN[i].resize(10);
            numberInputFieldsI[i].resize(10);
            numberInputFieldsN[i][j]->setVisible(true);
            numberInputFieldsI[i][j]->setVisible(true);
            int x = startX + i * position;
            int y = startY + j * position;
            numberInputFieldsN[i][j]->setGeometry(x, y, size, size);
            numberInputFieldsI[i][j]->setGeometry(x+360, y, size, size);
            numberInputFieldsN[i][j]->setFont(font);
            numberInputFieldsI[i][j]->setFont(font);
        }
    }
}
void Matrices::hideall()
{
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            numberInputFieldsN[i][j]->setVisible(false);
            numberInputFieldsI[i][j]->setVisible(false);
        }
    }
}
