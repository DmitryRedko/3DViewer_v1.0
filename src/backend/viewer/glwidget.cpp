#include "glwidget.h"
#include <GL/glut.h>
#include <QDebug>
#include <cstring>
#include <GL/glut.h>


GLWidget::GLWidget(QWidget *parent) : QGLWidget(parent) {
    initializeGLmodel();
}

void GLWidget::initializeGLmodel() {
    if (welcome_flag == 0) {
        const char defaultModel[] = "../frontend/default_models/welcome.obj";
        objData = parse_obj(defaultModel, &parse_flag);
        baseData = objData;
        welcome_flag = 1;
    } else {
        objData = parse_obj(model_name, &parse_flag);
        baseData = objData;
    }

    if (parse_flag == 0) {
        draw_model();
    } else {
        const char defaultModel[] = "../frontend/default_models/error.obj";
        objData = parse_obj(defaultModel, &parse_flag);
        baseData = objData;
        parse_flag = 0;
    }
}


void GLWidget::initializeGL() {
    glClearColor(0.2, 0.2, 0.2, 1);
}

void GLWidget::paintGL() {
    draw_model();
}

void GLWidget::draw_model() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_LINES);
    glClearColor(0.2, 0.2, 0.2, 1);

    for (int i = 0; i < objData.faceCount; ++i) {
        for (int j = 0; j < 3; ++j) {
            int vIndex = objData.faces[i].vIndex[j] - 1;
            glVertex3f(objData.vertices[vIndex].x, objData.vertices[vIndex].y, objData.vertices[vIndex].z);
        }
    }
    glEnd();
}

void GLWidget::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
}

void GLWidget::apply_transform() {
    move_operation(xMov, yMov, zMov, &objData, &baseData);
    rotate_operation(xRot, yRot, zRot, &objData, &objData);
    zoom_operation(scale, scale, scale, &objData, &objData);
}






