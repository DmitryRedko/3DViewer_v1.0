#include "mainviewer.h"
#include "ui_mainviewer.h"
#include <QFileDialog>
#include <QDebug>

MainViewer::MainViewer(QWidget *parent): QMainWindow(parent), ui(new Ui::MainViewer)
{
    ui->setupUi(this);
    myGLW = new GLWidget;


}

MainViewer::~MainViewer()
{
    delete ui;
}

void MainViewer::on_rotate_x_valueChanged()
{
    ui->rotate_title_3->setText("Rotate: x = " + QString::number(ui->rotate_x->value())
                                     + " y = " + QString::number(ui->rotate_y->value())
                                     + " z = " + QString::number(ui->rotate_z->value()));
    ui->GLwidget->xRot = ui->rotate_x->value();
    ui->GLwidget->apply_transform();
    ui->GLwidget->update();
}


void MainViewer::on_rotate_y_valueChanged()
{
    ui->rotate_title_3->setText("Rotate: x = " + QString::number(ui->rotate_x->value())
                                     + " y = " + QString::number(ui->rotate_y->value())
                                     + " z = " + QString::number(ui->rotate_z->value()));
    ui->GLwidget->yRot = ui->rotate_y->value();
    ui->GLwidget->apply_transform();
    ui->GLwidget->update();
}


void MainViewer::on_rotate_z_valueChanged()
{
    ui->rotate_title_3->setText("Rotate: x = " + QString::number(ui->rotate_x->value())
                                     + " y = " + QString::number(ui->rotate_y->value())
                                     + " z = " + QString::number(ui->rotate_z->value()));
    ui->GLwidget->zRot = ui->rotate_z->value();
    ui->GLwidget->apply_transform();
    ui->GLwidget->update();
}


void MainViewer::on_zoom_scale_valueChanged()
{
    ui->rotate_title->setText("Zoom: " + QString::number(ui->zoom_scale->value()));
    ui->GLwidget->scale = ui->zoom_scale->value();
    ui->GLwidget->apply_transform();
    ui->GLwidget->update();

}


void MainViewer::on_move_x_valueChanged()
{
    ui->translate_title->setText("Move: x = " + QString::number(ui->move_x->value()) +
                                 " y = " + QString::number(ui->move_y->value()) +
                                 " z = " + QString::number(ui->move_z->value()));
    ui->GLwidget->xMov = ui->move_x->value();
    ui->GLwidget->apply_transform();
    ui->GLwidget->update();
}


void MainViewer::on_move_y_valueChanged()
{
    ui->translate_title->setText("Move: x = " + QString::number(ui->move_x->value()) +
                                 " y = " + QString::number(ui->move_y->value()) +
                                 " z = " + QString::number(ui->move_z->value()));
    ui->GLwidget->yMov = ui->move_y->value();
    ui->GLwidget->apply_transform();
    ui->GLwidget->update();
}


void MainViewer::on_move_z_valueChanged()
{
    ui->translate_title->setText("Move: x = " + QString::number(ui->move_x->value()) +
                                 " y = " + QString::number(ui->move_y->value()) +
                                 " z = " + QString::number(ui->move_z->value()));
    ui->GLwidget->zMov = ui->move_z->value();
    ui->GLwidget->apply_transform();
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


void MainViewer::on_fileBtm_clicked()
{
    fileName = QFileDialog::getOpenFileName(this,
            tr("Выберите файл"), "",
            tr("Все файлы (*)"));
    ui->pathLine->setText(fileName);
}


void MainViewer::on_openBtm_clicked()
{
    if (!fileName.isEmpty()) {
        QByteArray byteArray = fileName.toUtf8();
        const char* charFileName = byteArray.constData();
        char* model_name = ui->GLwidget->model_name; // Получаем указатель на массив
        if (charFileName != nullptr) {
            strncpy(model_name, charFileName, sizeof(ui->GLwidget->model_name) - 1);
            model_name[sizeof(ui->GLwidget->model_name) - 1] = '\0';
        }

        ui->GLwidget->initializeGLmodel();
        on_reset_model_released();
    }
}


void MainViewer::on_point_size_scale_valueChanged(int value)
{
    ui->point_size_title->setText("Point size: " + QString::number(ui->point_size_scale->value()));
    ui->GLwidget->point_size = value;
    ui->GLwidget->update();
}


void MainViewer::on_line_width_scale_valueChanged(int value)
{
    ui->line_width_title->setText("Line width: " + QString::number(ui->line_width_scale->value()));
    ui->GLwidget->line_width = value;
    ui->GLwidget->update();
}

