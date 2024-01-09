#ifndef MAINVIEWER_H
#define MAINVIEWER_H

#include <QMainWindow>
#include "glwidget.h"
#include<QColorDialog>


QT_BEGIN_NAMESPACE
namespace Ui { class MainViewer; }
QT_END_NAMESPACE

class MainViewer : public QMainWindow
{
    Q_OBJECT

public:
    MainViewer(QWidget *parent = nullptr);
    ~MainViewer();
    QString fileName;

private:
    Ui::MainViewer *ui;
    GLWidget *myGLW;

private slots:
    void on_rotate_x_valueChanged();
    void on_rotate_y_valueChanged();
    void on_rotate_z_valueChanged();
    void on_zoom_scale_valueChanged();
    void on_move_x_valueChanged();
    void on_move_y_valueChanged();
    void on_move_z_valueChanged();
    void on_reset_model_released();
    void on_fileBtm_clicked();
    void on_openBtm_clicked();
    void on_point_size_scale_valueChanged(int value);
    void on_line_width_scale_valueChanged(int value);
    void on_line_type_toggled(bool checked);
    void on_openBtm_released();
    void on_pointColor_clicked();
    void on_lineColor_clicked();
    void on_BGColor_clicked();
    void on_resetColor_clicked();
    void on_noLine_clicked();
    void on_line_clicked();
    void on_lineLoop_clicked();
    void on_quads_clicked();
    void on_perspective_clicked();
    void on_parallel_clicked();
};
#endif // MAINVIEWER_H
