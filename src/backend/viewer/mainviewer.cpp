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

            ui->GLwidget->free_memory(); //крашит приложение при открытие не модели

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
//    printf("\nchecked %d\n", checked);
    if (checked == 1) {
        ui->GLwidget->line_type = 1;
    } else {
       ui->GLwidget->line_type = 2;
    }
    ui->GLwidget->update();
}

void MainViewer::on_openBtm_released()
{
   on_reset_model_released();
}


void MainViewer::on_point_color_scale_red_valueChanged(int value)
{
    ui->GLwidget->point_color_red = value;
    ui->GLwidget->update();
}


void MainViewer::on_point_color_scale_green_valueChanged(int value)
{
    ui->GLwidget->point_color_green = value;
    ui->GLwidget->update();
}


void MainViewer::on_point_color_scale_blue_valueChanged(int value)
{
    ui->GLwidget->point_color_blue = value;
    ui->GLwidget->update();
}


void MainViewer::on_background_color_scale_red_valueChanged(int value)
{
    ui->GLwidget->background_color_red = value;
    ui->GLwidget->update();
}


void MainViewer::on_background_color_scale_green_valueChanged(int value)
{
    ui->GLwidget->background_color_green = value;
    ui->GLwidget->update();
}


void MainViewer::on_background_color_scale_blue_valueChanged(int value)
{
    ui->GLwidget->background_color_blue = value;
    ui->GLwidget->update();
}


void MainViewer::on_pointColor_clicked()
{
        QColor color = QColorDialog::getColor(QColor(ui->GLwidget->point_color_red, ui->GLwidget->point_color_green, ui->GLwidget->point_color_blue), this);
        if (color.isValid()){
        ui->GLwidget->point_color_red = static_cast<GLubyte>(color.red());
        ui->GLwidget->point_color_blue = static_cast<GLubyte>(color.blue());
        ui->GLwidget->point_color_green = static_cast<GLubyte>(color.green());
        ui->GLwidget->update();
        }
}


void MainViewer::on_lineColor_clicked()
{
    QColor color = QColorDialog::getColor(QColor(ui->GLwidget->line_color_red, ui->GLwidget->line_color_green, ui->GLwidget->line_color_blue), this);
    if (color.isValid()){
    ui->GLwidget->line_color_red = static_cast<GLubyte>(color.red());
    ui->GLwidget->line_color_blue = static_cast<GLubyte>(color.blue());
    ui->GLwidget->line_color_green = static_cast<GLubyte>(color.green());
    ui->GLwidget->update();
    }
}


void MainViewer::on_BGColor_clicked()
{
    QColor color = QColorDialog::getColor(QColor(ui->GLwidget->background_color_red, ui->GLwidget->background_color_green, ui->GLwidget->background_color_blue), this);
    if (color.isValid()){
    ui->GLwidget->background_color_red = static_cast<GLubyte>(color.red());
    ui->GLwidget->background_color_blue = static_cast<GLubyte>(color.blue());
    ui->GLwidget->background_color_green = static_cast<GLubyte>(color.green());
    ui->GLwidget->update();
    }
}


void MainViewer::on_resetColor_clicked()
{
    ui->GLwidget->point_color_red = ui->GLwidget->default_point_red;
    ui->GLwidget->point_color_blue = ui->GLwidget->default_point_blue;
    ui->GLwidget->point_color_green = ui->GLwidget->default_point_green;

    ui->GLwidget->line_color_red = ui->GLwidget->default_line_red;
    ui->GLwidget->line_color_blue = ui->GLwidget->default_line_blue;
    ui->GLwidget->line_color_green = ui->GLwidget->default_line_green;

    ui->GLwidget->background_color_red = ui->GLwidget->default_background_red;
    ui->GLwidget->background_color_blue = ui->GLwidget->default_background_blue;
    ui->GLwidget->background_color_green = ui->GLwidget->default_background_green;
    ui->GLwidget->update();
}


void MainViewer::on_noLine_clicked()
{
    ui->GLwidget->draw_lines = 0;
    ui->GLwidget->update();
}


void MainViewer::on_line_clicked()
{
    ui->GLwidget->draw_lines = 1;
    ui->GLwidget->primitive_type = GL_LINES;
    ui->GLwidget->update();
}


void MainViewer::on_lineLoop_clicked()
{
    ui->GLwidget->draw_lines = 1;
    ui->GLwidget->primitive_type = GL_LINE_LOOP;
    ui->GLwidget->update();
}


void MainViewer::on_quads_clicked()
{
    ui->GLwidget->draw_lines = 1;
    ui->GLwidget->primitive_type = GL_QUADS;
    ui->GLwidget->update();
}


void MainViewer::on_perspective_clicked()
{
    ui->GLwidget->isPerspective = 1;

    ui->GLwidget->resizeGL(ui->GLwidget->width(),ui->GLwidget->height());
    ui->GLwidget->update();
}


void MainViewer::on_parallel_clicked()
{
    ui->GLwidget->isPerspective = 0;

    ui->GLwidget->resizeGL(ui->GLwidget->width(),ui->GLwidget->height());
    ui->GLwidget->update();
}

