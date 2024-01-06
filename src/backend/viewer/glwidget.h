#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QTimer>
#include <GL/glut.h>

extern "C" {
#include "../backend.h" // Include your OBJ parser header
}

class GLWidget : public QGLWidget
{
public:
    explicit GLWidget(QWidget *parent = nullptr);
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;
    void draw_model();
    void initializeGLmodel();
    void updateGLmodel(ObjData objData);
    void apply_transform();
    char model_name[100] = " ";
    double welcome_flag = 0;
    double parse_flag = 0;
    ObjData objData; // Store parsed OBJ data here
    ObjData baseData; // Store parsed OBJ data here

public slots:
    void function_zoom_scale(int value); // Declare the slot in GLWidget
    void function_rotate_x(int value); // Declare the slot in GLWidget
    void function_rotate_y(int value); // Declare the slot in GLWidget
    void function_rotate_z(int value); // Declare the slot in GLWidget
    void function_move_x(int value); // Declare the slot in GLWidget
    void function_move_y(int value); // Declare the slot in GLWidget
    void function_move_z(int value); // Declare the slot in GLWidget
    float scale = 1.0f, xRot = 0.0f, yRot = 0.0f, zRot = 0.0f, xMov = 0.0f, yMov = 0.0f, zMov = 0.0f;


private:
    QTimer timer;

};

#endif // GLWIDGET_H
