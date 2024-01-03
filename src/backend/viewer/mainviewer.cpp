#include "mainviewer.h"
#include "ui_mainviewer.h"

MainViewer::MainViewer(QWidget *parent): QMainWindow(parent), ui(new Ui::MainViewer)
{
    ui->setupUi(this);
    myGLW = new GLWidget;
    connect(ui->rotate_x, &QSlider::valueChanged, this, &MainViewer::updateLabelText);
    connect(ui->rotate_x, &QSlider::valueChanged, myGLW, &GLWidget::function_rotate_x);
//    connect(ui->rotate_x, &QSlider::valueChanged, myGLW, &GLWidget::upda;
//    ui->GLwidget->update();
}

MainViewer::~MainViewer()
{
    delete ui;
}


void MainViewer::updateLabelText(int value) {
    ui->rotate_title_3->setText(QString::number(value)); // Convert integer value to QString
}


void MainViewer::on_rotate_x_valueChanged(int value)
{
    ui->GLwidget->update();
}

