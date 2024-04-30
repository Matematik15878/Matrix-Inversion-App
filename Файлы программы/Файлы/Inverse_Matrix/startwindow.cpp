#include "startwindow.h"

// Constructors and destructors
StartWindow::StartWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::StartWindow) { ui->setupUi(this); }
StartWindow::~StartWindow() { delete ui; }
// Private slots
void StartWindow::on_RussianButton_clicked() { emit languageSelected("ru"); }
void StartWindow::on_UkrainianButton_clicked() { emit languageSelected("ua"); }
void StartWindow::on_BritishButton_clicked() { emit languageSelected("uk"); }
// open
void StartWindow::open()
{
    // QStrings
    QString projectPath = QCoreApplication::applicationDirPath();
    QString logoPath = projectPath + "/Frog-logo.png";
    QString BritishImagePath = projectPath + "/British.png";
    QString UkrainianImagePath = projectPath + "/Ukrainian.jpg";
    QString RussianImagePath = projectPath + "/Russian.png";
    // Images
    QImage BritishImage(BritishImagePath);
    QImage UkrainianImage(UkrainianImagePath);
    QImage RussianImage(RussianImagePath);
    // Logotype
    QIcon logo(logoPath);
    // Window settings
    this->setStyleSheet("QMainWindow { border: 5px solid #1f5b21; background-color: #1f7a21 }");
    this->setWindowTitle("Matrix Inversion");
    this->setWindowIcon(logo);
    this->resize(400, 175);
    // Language labels
    QLabel *BritishLabel = this->findChild<QLabel*>("British");
    QPixmap pixmapBritish(BritishImagePath);
    BritishLabel->setPixmap(pixmapBritish);
    QLabel *UkrainianLabel = this->findChild<QLabel*>("Ukrainian");
    QPixmap pixmapUkrainian(UkrainianImagePath);
    UkrainianLabel->setPixmap(pixmapUkrainian);
    QLabel *RussianLabel = this->findChild<QLabel*>("Russian");
    QPixmap pixmapRussian(RussianImagePath);
    RussianLabel->setPixmap(pixmapRussian);
    // Show the interface
    this->show();
}
