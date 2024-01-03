#include "mainviewer.h"
#include "ui_mainviewer.h"

MainViewer::MainViewer(QWidget *parent): QMainWindow(parent), ui(new Ui::MainViewer)
{
    ui->setupUi(this);
    myGLW = new GLWidget;
    // connect(ui->rotate_x, &QSlider::valueChanged, this, &MainViewer::updateLabelText);
    connect(ui->zoom_scale, &QSlider::valueChanged, myGLW, &GLWidget::function_zoom_scale);
    connect(ui->rotate_x, &QSlider::valueChanged, myGLW, &GLWidget::function_rotate_x);
    connect(ui->rotate_y, &QSlider::valueChanged, myGLW, &GLWidget::function_rotate_y);
    connect(ui->rotate_z, &QSlider::valueChanged, myGLW, &GLWidget::function_rotate_z);
    connect(ui->move_x, &QSlider::valueChanged, myGLW, &GLWidget::function_move_x);
    connect(ui->move_y, &QSlider::valueChanged, myGLW, &GLWidget::function_move_y);
    connect(ui->move_z, &QSlider::valueChanged, myGLW, &GLWidget::function_move_z);
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
    ui->rotate_title_3->setText("Rotate: x = " + QString::number(ui->rotate_x->value())
                                     + " y = " + QString::number(ui->rotate_y->value())
                                     + " z = " + QString::number(ui->rotate_z->value()));
    ui->GLwidget->update();
}


void MainViewer::on_rotate_y_valueChanged(int value)
{
    ui->rotate_title_3->setText("Rotate: x = " + QString::number(ui->rotate_x->value())
                                     + " y = " + QString::number(ui->rotate_y->value())
                                     + " z = " + QString::number(ui->rotate_z->value()));
    ui->GLwidget->update();
}


void MainViewer::on_rotate_z_valueChanged(int value)
{
    ui->rotate_title_3->setText("Rotate: x = " + QString::number(ui->rotate_x->value())
                                     + " y = " + QString::number(ui->rotate_y->value())
                                     + " z = " + QString::number(ui->rotate_z->value()));
    ui->GLwidget->update();
}


void MainViewer::on_zoom_scale_valueChanged(int value)
{
    ui->rotate_title->setText("Zoom: " + QString::number(ui->zoom_scale->value()));
    ui->GLwidget->update();
}


void MainViewer::on_move_x_valueChanged(int value)
{
    ui->translate_title->setText("Move: x = " + QString::number(ui->move_x->value()) +
                                 " y = " + QString::number(ui->move_y->value()) +
                                 " z = " + QString::number(ui->move_z->value()));
    ui->GLwidget->update();
}


void MainViewer::on_move_y_valueChanged(int value)
{
    ui->translate_title->setText("Move: x = " + QString::number(ui->move_x->value()) +
                                 " y = " + QString::number(ui->move_y->value()) +
                                 " z = " + QString::number(ui->move_z->value()));
    ui->GLwidget->update();
}


void MainViewer::on_move_z_valueChanged(int value)
{
    ui->translate_title->setText("Move: x = " + QString::number(ui->move_x->value()) +
                                 " y = " + QString::number(ui->move_y->value()) +
                                 " z = " + QString::number(ui->move_z->value()));
    ui->GLwidget->update();
}


void MainViewer::on_reset_model_released()
{
    ui->zoom_scale->setValue(100);
    ui->rotate_x->setValue(0);
    ui->rotate_y->setValue(0);
    ui->rotate_z->setValue(0);
    ui->move_x->setValue(0);
    ui->move_y->setValue(0);
    ui->move_z->setValue(0);

    ui->GLwidget->update();
}

