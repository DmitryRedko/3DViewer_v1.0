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
    void free_memory();
    char model_name[100] = " ";
    int welcome_flag = 0;
    int parse_flag = 0;
    int before_parse_flag = 0;
    ObjData objData;
    ObjData baseData;
    void normalize_model(ObjData *data);
    float scale = 100.0, xRot = 0.0f, yRot = 0.0f, zRot = 0.0f, xMov = 0.0f, yMov = 0.0f, zMov = 0.0f;
    int point_size = 2;

    int default_point_red = 255;
    int default_point_green = 255;
    int default_point_blue = 0;

    int default_line_red = 255;
    int default_line_green = 0;
    int default_line_blue = 0;

    int default_background_red = 51;
    int default_background_green = 51;
    int default_background_blue = 51;

    int point_color_red = default_point_red;
    int point_color_green = default_point_green;
    int point_color_blue = default_point_blue;
    int background_color_red = default_background_red;
    int background_color_green = default_background_green;
    int background_color_blue = default_background_blue;

    int line_color_red = 255;
    int line_color_green = 0;
    int line_color_blue = 0;


    int line_width = 1;
    int line_type = 1;
    int draw_lines = 1;

    GLenum primitive_type = GL_LINES;

    int isPerspective = 0;
};

#endif // GLWIDGET_H
