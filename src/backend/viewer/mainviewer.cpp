#include "mainviewer.h"
#include "ui_mainviewer.h"
#include <QFileDialog>
#include <QDebug>
#include <string.h>

MainViewer::MainViewer(QWidget *parent): QMainWindow(parent), ui(new Ui::MainViewer)
{
    ui->setupUi(this);
    myGLW = new GLWidget;
    ui->point_size_scale->setValue(ui->GLwidget->point_size);
    ui->line_type->toggle();

    QString file_name = ui->pathLine->text();
    ui->model_name_and_props->setText("Model name: " +
                                      QFileInfo(file_name).fileName() +
                                      " with " +
                                      QString::number(ui->GLwidget->objData.vertexCount) +
                                      " vertices and " +
                                      QString::number(ui->GLwidget->objData.faceCount) +
                                      " faces");
}

MainViewer::~MainViewer()
{
    ui->GLwidget->free_memory();
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
        // ui->GLwidget->free_memory(); //крашит приложение при открытие не модели
        QByteArray byteArray = fileName.toUtf8();
        const char* charFileName = byteArray.constData();
        char* model_name = ui->GLwidget->model_name; // Получаем указатель на массив
        if (charFileName != nullptr) {
            strncpy(model_name, charFileName, sizeof(ui->GLwidget->model_name) - 1);
            model_name[sizeof(ui->GLwidget->model_name) - 1] = '\0';
        }

        ui->GLwidget->initializeGLmodel();
        on_reset_model_released();

        QString file_name = ui->pathLine->text();
        ui->model_name_and_props->setText("Model name: " +
                                          QFileInfo(file_name).fileName() +
                                          " with " +
                                          QString::number(ui->GLwidget->objData.vertexCount) +
                                          " vertices and " +
                                          QString::number(ui->GLwidget->objData.faceCount) +
                                          " faces, size: " +
                                          QString::number(QFileInfo(file_name).size() / 1000, 'f', 3) +
                                          " kb");
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


void MainViewer::on_line_type_toggled(bool checked)
{
    printf("\nchecked %d\n", checked);
    if (checked == 1) {
        ui->GLwidget->line_type = 1;
    } else {
       ui->GLwidget->line_type = 2;
    }
    ui->GLwidget->update();
}


void MainViewer::on_no_lines_toggled(bool checked)
{
    printf("\nchecked %d\n", checked);
    if (checked == 1) {
        ui->GLwidget->draw_lines = 0;
    } else {
        ui->GLwidget->draw_lines = 1;
    }
    ui->GLwidget->update();
}


void MainViewer::on_openBtm_released()
{
   on_reset_model_released();
}

