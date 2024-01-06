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
        // const char defaultModel[] = "../models/water.obj";
        objData = parse_obj(defaultModel, &parse_flag);
        // baseData = objData;
        baseData = parse_obj(defaultModel, &parse_flag);
        printf("baseData vertexCount %d\n", baseData.vertexCount);
        welcome_flag = 1;
    } else {
        objData = parse_obj(model_name, &parse_flag);
        // baseData = objData;
        baseData = parse_obj(model_name, &parse_flag);
    }

    if (parse_flag == 0) {
        draw_model();
    } else {
        const char defaultModel[] = "../frontend/default_models/error.obj";
        objData = parse_obj(defaultModel, &parse_flag);
        // baseData = objData;
        baseData = parse_obj(defaultModel, &parse_flag);
        parse_flag = 0;
    }
}


void GLWidget::initializeGL() {
    glClearColor(0.2, 0.2, 0.2, 1);
}

void GLWidget::paintGL() {
    draw_model();
}

//void GLWidget::draw_model() {
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glBegin(GL_LINES);
//    glClearColor(0.2, 0.2, 0.2, 1);

//    for (int i = 0; i < objData.vertexCount; ++i) {
//        for (int j = 0; j < 3; ++j) {
//            int vIndex = objData.faces[i].vIndex[j] - 1;
//            glVertex3f(objData.vertices[vIndex].x, objData.vertices[vIndex].y, objData.vertices[vIndex].z);
//        }
//    }
//    glEnd();
//}

void GLWidget::draw_model() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPointSize(3);
    glEnable(GL_POINT_SMOOTH);

    glVertexPointer(3, GL_FLOAT, 0, objData.vertices);
    glEnableClientState(GL_VERTEX_ARRAY);
    glColor3ub(255,255,0); // желтый
    glDrawArrays(GL_POINTS, 0, objData.vertexCount);
}

void GLWidget::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
}

void GLWidget::apply_transform() {
    move_operation(xMov, yMov, zMov, &objData, &baseData);
    rotate_operation(xRot, yRot, zRot, &objData, &objData);
    zoom_operation(scale, scale, scale, &objData, &objData);
}






