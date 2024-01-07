#ifndef MAINVIEWER_H
#define MAINVIEWER_H

#include <QMainWindow>
#include "glwidget.h"

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
    void on_no_lines_toggled(bool checked);
};
#endif // MAINVIEWER_H
