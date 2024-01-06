#include "glwidget.h"
#include <GL/glut.h>
#include <QDebug>
#include <cstring>
#include <GL/glut.h>


GLWidget::GLWidget(QWidget *parent) : QGLWidget(parent) {

    initializeGLmodel();

}

void GLWidget::initializeGLmodel() {
    qDebug() << "Initializing GL model...";
    if (welcome_flag == 0) {
        const char defaultModel[] = "../frontend/default_models/welcome.obj";
        objData = parse_obj(defaultModel, &parse_flag);
        baseData = parse_obj(defaultModel, &parse_flag);
        welcome_flag = 1;
    } else {
        objData = parse_obj(model_name, &parse_flag);
        baseData = parse_obj(model_name, &parse_flag);
    }

    if (parse_flag == 0) {
        draw_model();
    } else {
        const char defaultModel[] = "../frontend/default_models/error.obj";
        objData = parse_obj(defaultModel, &parse_flag);
        baseData = parse_obj(defaultModel, &parse_flag);
        parse_flag = 0;
    }
}

void GLWidget::initializeGL() {
    qDebug() << "Initializing GL...";
    glClearColor(0.2, 0.2, 0.2, 1);

}

void GLWidget::paintGL() {
    qDebug() << "paintGL...";
    draw_model();
}

void GLWidget::draw_model() {
    qDebug() << "draw_model...";
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glMatrixMode(GL_TEXTURE);
    glLoadIdentity();

    glBegin(GL_TRIANGLES);
    glClearColor(0.2, 0.2, 0.2, 1);

    for (int i = 0; i < objData.faceCount; ++i) {
        for (int j = 0; j < 3; ++j) {
            int vIndex = objData.faces[i].vIndex[j] - 1;
            glVertex3f(objData.vertices[vIndex].x, objData.vertices[vIndex].y, objData.vertices[vIndex].z);
        }
    }
    glEnd();

    glFlush();
}

void GLWidget::resizeGL(int w, int h) {
    qDebug() << "resizeGL...";
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}


void GLWidget::function_zoom_scale(int value) {
    scale = static_cast<float>(value)/100; // Update xRot with the slider value
    apply_transform();
}

void GLWidget::function_rotate_x(int value) {
    xRot = static_cast<float>(value); // Update xRot with the slider value
    apply_transform();
}

void GLWidget::function_rotate_y(int value) {
    yRot = static_cast<float>(value); // Update yRot with the slider value
    apply_transform();
}

void GLWidget::function_rotate_z(int value) {
    zRot = static_cast<float>(value); // Update zRot with the slider value
    apply_transform();
}

void GLWidget::function_move_x(int value) {
    xMov = static_cast<float>(value) / 100; // Update zRot with the slider value
    apply_transform();
}

void GLWidget::function_move_y(int value) {
    yMov = static_cast<float>(value) / 100; // Update zRot with the slider value
    apply_transform();
}

void GLWidget::function_move_z(int value) {
    zMov = static_cast<float>(value) / 100; // Update zRot with the slider value
    apply_transform();
}

void GLWidget::apply_transform() {
    qDebug() << "apply_transform...";
    move_operation(xMov, yMov, zMov, &objData, baseData);
    rotate_operation(xRot, yRot, zRot, &objData, objData);
    zoom_operation(scale, scale, scale, &objData, objData);
    initializeGL();
//    resizeGL(w,h);
//    draw_model();
}



