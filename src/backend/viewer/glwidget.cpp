#include "glwidget.h"
#include <GL/glut.h>
#include <QDebug>

GLWidget::GLWidget(QWidget *parent) : QGLWidget(parent), xRot(0.0f) {

    connect(&timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    // const char *file_path = "/home/dmitry/Desktop/School21/Viewer/src/models/model2.obj";
    const char *file_path = "../models/katana2.obj";
    objData = parse_obj(file_path);
}

void GLWidget::initializeGL() {
    glClearColor(0.2, 0.2, 0.2, 1);
    // glEnable(GL_DEPTH_TEST);
    // glEnable(GL_LIGHTING);
    // glEnable(GL_LIGHT0);

    // GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
    // glLightfv(GL_LIGHT0, GL_POSITION, light_position);

}


void GLWidget::paintGL() {

//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//    glMatrixMode(GL_MODELVIEW); // устанавливает положение и ориентацию матрице моделирования

//    glLoadIdentity(); // загружает единичную матрицу моделирования

//    // последовательные преобразования
//    printf("%f",xRot);
//    glRotatef(xRot, 1.0f, 0.0f, 0.0f); // поворот вокруг оси X


//   // glRotatef(yRot, 0.0f, 1.0f, 0.0f); // поворот вокруг оси Y
//   //  glRotatef(zRot, 0.0f, 0.0f, 1.0f); // поворот вокруг оси Z
//   //  glTranslatef(xTra, yTra, zTra);    // трансляция
//   // glScalef(xSca, ySca, zSca);        // масштабирование по осям

//    // example_drawAxis(); // рисование осей координат

//    // glTranslatef(0.0f, 0.0f, -5.0f);

//    glBegin(GL_TRIANGLES);
//    // printf("faceCount %d\n", objData.faceCount);
//    for (int i = 0; i < objData.faceCount; ++i) {
//        for (int j = 0; j < 3; ++j) {
//            int vIndex = objData.faces[i].vIndex[j] - 1; // Массивы в .obj начинаются с 1
////            int vnIndex = objData.faces[i].vnIndex[j] - 1;

////            glNormal3f(objData.normals[vnIndex].x, objData.normals[vnIndex].y, objData.normals[vnIndex].z);
//            // printf("glNormal3f %f %f %f\n", objData.normals[vnIndex].x, objData.normals[vnIndex].y, objData.normals[vnIndex].z);
//            glVertex3f(objData.vertices[vIndex].x, objData.vertices[vIndex].y, objData.vertices[vIndex].z);
//            // printf("glVertex3f %f %f %f\n", objData.vertices[vIndex].x, objData.vertices[vIndex].y, objData.vertices[vIndex].z);
//            // glNormal3f(ndc(objData.normals[vnIndex].x), ndc(objData.normals[vnIndex].y), ndc(objData.normals[vnIndex].z));
//            // glVertex3f(ndc(objData.vertices[vIndex].x), ndc(objData.vertices[vIndex].y), ndc(objData.vertices[vIndex].z));
//        }
//    }
//    glEnd();

//    glFlush();

//    // Отрисовка куба
//    // example_drawCube();
//    // glRotatef(0.2,1,1,1);

}

void GLWidget::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // gluPerspective(45.0, (GLfloat)w / (GLfloat)h, 0.1, 100.0);
}


void GLWidget::function_rotate_x(int value) {
    xRot += static_cast<float>(value); // Update xRot with the slider value
    // Redraw the scene to reflect the updated transformation
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW); // устанавливает положение и ориентацию матрице моделирования

    glLoadIdentity(); // загружает единичную матрицу моделирования

    // последовательные преобразования
    printf("%f",xRot);
    glRotatef(xRot, 1.0f, 0.0f, 0.0f); // поворот вокруг оси X


   // glRotatef(yRot, 0.0f, 1.0f, 0.0f); // поворот вокруг оси Y
   //  glRotatef(zRot, 0.0f, 0.0f, 1.0f); // поворот вокруг оси Z
   //  glTranslatef(xTra, yTra, zTra);    // трансляция
   // glScalef(xSca, ySca, zSca);        // масштабирование по осям

    // example_drawAxis(); // рисование осей координат

    // glTranslatef(0.0f, 0.0f, -5.0f);

    glBegin(GL_TRIANGLES);
    // printf("faceCount %d\n", objData.faceCount);
    for (int i = 0; i < objData.faceCount; ++i) {
        for (int j = 0; j < 3; ++j) {
            int vIndex = objData.faces[i].vIndex[j] - 1; // Массивы в .obj начинаются с 1
//            int vnIndex = objData.faces[i].vnIndex[j] - 1;

//            glNormal3f(objData.normals[vnIndex].x, objData.normals[vnIndex].y, objData.normals[vnIndex].z);
            // printf("glNormal3f %f %f %f\n", objData.normals[vnIndex].x, objData.normals[vnIndex].y, objData.normals[vnIndex].z);
            glVertex3f(objData.vertices[vIndex].x, objData.vertices[vIndex].y, objData.vertices[vIndex].z);
            // printf("glVertex3f %f %f %f\n", objData.vertices[vIndex].x, objData.vertices[vIndex].y, objData.vertices[vIndex].z);
            // glNormal3f(ndc(objData.normals[vnIndex].x), ndc(objData.normals[vnIndex].y), ndc(objData.normals[vnIndex].z));
            // glVertex3f(ndc(objData.vertices[vIndex].x), ndc(objData.vertices[vIndex].y), ndc(objData.vertices[vIndex].z));
        }
    }
    glEnd();

    glFlush();
}
