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

private:
    Ui::MainViewer *ui;
    GLWidget *myGLW;

private slots:
    void updateLabelText(int value);
    void on_rotate_x_valueChanged(int value);
    void on_rotate_y_valueChanged(int value);
    void on_rotate_z_valueChanged(int value);
    void on_zoom_scale_valueChanged(int value);
    void on_move_x_valueChanged(int value);
    void on_move_y_valueChanged(int value);
    void on_move_z_valueChanged(int value);
    void on_reset_model_released();
};
#endif // MAINVIEWER_H
