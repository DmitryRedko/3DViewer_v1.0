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
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void draw_model();
    void draw_model_lines();
    void initializeGLmodel();
    void apply_transform();
    char model_name[100] = " ";
    int welcome_flag = 0;
    int parse_flag = 0;
    ObjData objData;
    ObjData baseData;
    float scale = 100.0, xRot = 0.0f, yRot = 0.0f, zRot = 0.0f, xMov = 0.0f, yMov = 0.0f, zMov = 0.0f;
    int point_size = 5;
    int line_width = 1;
    int line_type = 1;
    int draw_lines = 1;

};

#endif // GLWIDGET_H
