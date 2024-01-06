#include "glwidget.h"
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <QDebug>
#include <cstring>
#include <GL/gl.h>


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

    glPointSize(2);
    glEnable(GL_POINT_SMOOTH);

    glVertexPointer(3, GL_FLOAT, 0, objData.vertices);
    glEnableClientState(GL_VERTEX_ARRAY);
    glColor3ub(255,255,0); // желтый
    glDrawArrays(GL_POINTS, 0, objData.vertexCount);
    // glDisableClientState(GL_VERTEX_ARRAY);

    draw_model_lines();
}

void GLWidget::draw_model_lines() {
    // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x00FF);
    glLineWidth(1);
    glColor3ub(255,0,0); // красный

    // glIndexPointer(GL_INT, 2, objData.faces);
    // glEnableClientState(GL_INDEX_ARRAY);
    // glDrawElements(GL_LINES, objData.faceCount * 2, GL_UNSIGNED_INT, objData.faceCount);
    glDrawElements(GL_LINES, objData.faceCount * 2, GL_UNSIGNED_INT, reinterpret_cast<const GLvoid*>(objData.faces));

    // glDisableClientState(GL_INDEX_ARRAY);
}

void GLWidget::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
}

void GLWidget::apply_transform() {
    move_operation(xMov, yMov, zMov, &objData, &baseData);
    rotate_operation(xRot, yRot, zRot, &objData, &objData);
    zoom_operation(scale, scale, scale, &objData, &objData);
}






