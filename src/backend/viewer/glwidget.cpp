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
        // const char defaultModel[] = "../frontend/default_models/welcome.obj";
        const char defaultModel[] = "../models/cube.obj";
        objData = parse_obj(defaultModel, &parse_flag);
        // baseData = objData;
        baseData = parse_obj(defaultModel, &parse_flag);
        // printf("baseData vertexCount %d\n", baseData.vertexCount);
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
    glEnable(GL_DEPTH_TEST);
}

void GLWidget::paintGL() {
    if (draw_lines == 1) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        draw_model_lines();
        draw_model();
    }
    else{
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        draw_model();
    }
}


void GLWidget::draw_model() {

    glPointSize(point_size);
    glEnable(GL_POINT_SMOOTH);

    glVertexPointer(3, GL_FLOAT, 0, objData.vertices);
    glEnableClientState(GL_VERTEX_ARRAY);
    glColor3ub(255,255,0); // желтый
    glDrawArrays(GL_POINTS, 0, objData.vertexCount);
    // glDisableClientState(GL_VERTEX_ARRAY);
}

void GLWidget::draw_model_lines() {
    glEnable(GL_DEPTH_TEST); // Включить z-буферизацию для удаления скрытых граней
    glEnable(GL_CULL_FACE); // Включить back-face culling для удаления невидимых граней

    glCullFace(GL_BACK); // Оставить только грани, обращенные наружу
    glFrontFace(GL_CCW); // Указать порядок обхода вершин для передней грани (CCW - против часовой стрелки)
    if (line_type == 1) {
        glDisable(GL_LINE_SMOOTH);
        glEnable(GL_LINE_STIPPLE);
        glLineStipple(1, 0x00FF);
    } else {
        glDisable(GL_LINE_STIPPLE);
        glEnable(GL_LINE_SMOOTH);
    }
    glLineWidth(line_width);
    glColor3ub(255,0,0); // красный

    // glIndexPointer(GL_INT, 2, objData.faces);
    // glEnableClientState(GL_INDEX_ARRAY);
     glDrawElements(GL_QUADS, objData.faceCount, GL_UNSIGNED_INT, objData.faces);

//    glDrawElements(GL_LINE_STRIP, objData.faceCount, GL_UNSIGNED_INT, reinterpret_cast<const GLvoid*>(objData.faces));

    // glDisableClientState(GL_INDEX_ARRAY);
}

void GLWidget::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45,(float)w/h, 0.01, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0,0,5,0,0,0,0,1,0);
}

void GLWidget::apply_transform() {
    move_operation(xMov, yMov, zMov, &objData, &baseData);
    rotate_operation(xRot, yRot, zRot, &objData, &objData);
    zoom_operation(scale, scale, scale, &objData, &objData);
}






