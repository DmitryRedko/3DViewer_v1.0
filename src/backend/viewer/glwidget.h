#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QTimer>

extern "C" {
#include "../parser/s21_parser.h" // Include your OBJ parser header
}

class GLWidget : public QGLWidget
{
public:
    explicit GLWidget(QWidget *parent = nullptr);
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void example_drawAxis();
    void example_drawCube();

    // Add a function to set the parsed OBJ data
    void setObjData(ObjData objData);

public slots:
    void function_rotate_x(int value); // Declare the slot in GLWidget
    float xRot;


private:
    QTimer timer;
    ObjData objData; // Store parsed OBJ data here
};

#endif // GLWIDGET_H
