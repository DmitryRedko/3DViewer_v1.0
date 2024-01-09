#include "glwidget.h"
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <QDebug>
#include <cstring>
#include <GL/gl.h>


GLWidget::GLWidget(QWidget *parent) : QGLWidget(parent) {
    initializeGLmodel();
}

void GLWidget::normalize_model(ObjData *data) {
    float maxX = -10000000;
    float maxY = -10000000;
    float maxZ = -10000000;
    float minX = 10000000;
    float minY = 10000000;
    float minZ = 10000000;
    float maxVal = -100000000;

    for(unsigned int i = 0; i < data->vertexCount*3; i=i+3){
        if (data->vertices[i] > maxX)
            maxX = data->vertices[i];
        if (data->vertices[i+1] > maxY)
            maxY = data->vertices[i+1];
        if (data->vertices[i+2] > maxZ)
            maxZ = data->vertices[i+2];

        if (data->vertices[i] < minX)
            minX = data->vertices[i];
        if (data->vertices[i+1] < minY)
            minY = data->vertices[i+1];
        if (data->vertices[i+2] < minZ)
            minZ = data->vertices[i+2];
    }
    float moveX = -(maxX + minX)/2;
    float moveY = -(maxY + minY)/2;
    float moveZ = -(maxZ + minZ)/2;
    move_operation(moveX*100,moveY*100,moveZ*100,data,data);

    for(unsigned int i = 0; i < data->vertexCount*3; i = i+3){
        if (data->vertices[i] > maxVal)
            maxVal = data->vertices[i];
        if (data->vertices[i+1] > maxVal)
            maxVal = data->vertices[i+1];
    }

    zoom_operation(1.3*scale/maxVal, 1.3*scale/maxVal, 1.3*scale/maxVal, data, data);

}

void GLWidget::initializeGLmodel() {
    if (welcome_flag == 0) {
        const char defaultModel[] = "../frontend/default_models/welcome_3d.obj";
        objData = parse_obj(defaultModel, &parse_flag);
        baseData = parse_obj(defaultModel, &parse_flag);
        welcome_flag = 1;
    } else {
        objData = parse_obj(model_name, &parse_flag);
        baseData = parse_obj(model_name, &parse_flag);
    }

    if (parse_flag == 0) {
        normalize_model(&baseData);
        normalize_model(&objData);
        draw_model();
    } else {
        strcpy(model_name, "../frontend/default_models/error_3d.obj");
        parse_flag = 0;
        initializeGLmodel();
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
     glDrawElements(GL_LINES, objData.faceCount, GL_UNSIGNED_INT, objData.faces);

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
    move_operation(xMov/scale*250, yMov/scale*250, zMov/scale*250, &objData, &baseData);
    rotate_operation(xRot, yRot, zRot, &objData, &objData);
    zoom_operation(scale, scale, scale, &objData, &objData);
}

void GLWidget::free_memory() {
    model_destructor(&objData);
    model_destructor(&baseData);
}
