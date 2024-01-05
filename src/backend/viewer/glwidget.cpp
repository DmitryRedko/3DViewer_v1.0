#include "glwidget.h"
#include <GL/glut.h>
#include <QDebug>
#include <cstring>


GLWidget::GLWidget(QWidget *parent) : QGLWidget(parent) {

    connect(&timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    initializeGLmodel();

}

void GLWidget::initializeGLmodel() {
    QDebug debug = qDebug();

    if(welcome_flag==0){
        const char defaultModel[] = "../frontend/default_models/welcome.obj";
        objData = parse_obj(defaultModel, &parse_flag);
        welcome_flag = 1;
    }
    else
    {
        objData = parse_obj(model_name, &parse_flag);
    }

    if(parse_flag ==0){
        draw_model();
    }
    else {
        const char defaultModel[] = "../frontend/default_models/error.obj";
        objData = parse_obj(defaultModel, &parse_flag);
        parse_flag = 0;
    }
}

void GLWidget::initializeGL() {
    glClearColor(0.2, 0.2, 0.2, 1);
//     glEnable(GL_DEPTH_TEST);
//     glEnable(GL_LIGHTING);
//     glEnable(GL_LIGHT0);

//     GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
//     glLightfv(GL_LIGHT0, GL_POSITION, light_position);

}


void GLWidget::paintGL() {

    draw_model();
}

void GLWidget::draw_model() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
    glClearColor(0.2, 0.2, 0.2, 1);
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

void GLWidget::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // gluPerspective(45.0, (GLfloat)w / (GLfloat)h, 0.1, 100.0);
}

void GLWidget::function_zoom_scale(int value) {
    scale = static_cast<float>(value)/100; // Update xRot with the slider value
    // Redraw the scene to reflect the updated transformation
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW); // устанавливает положение и ориентацию матрице моделирования

    glLoadIdentity(); // загружает единичную матрицу моделирования

    // последовательные преобразования
    // printf("%f",xRot);

    //  glTranslatef(xTra, yTra, zTra);    // трансляция

    glRotatef(xRot, 1.0f, 0.0f, 0.0f); // поворот вокруг оси X
    glRotatef(yRot, 0.0f, 1.0f, 0.0f); // поворот вокруг оси Y
    glRotatef(zRot, 0.0f, 0.0f, 1.0f); // поворот вокруг оси Z
    glScalef(scale, scale, scale);        // масштабирование по осям
    glTranslatef(xMov, yMov, zMov);

    // example_drawAxis(); // рисование осей координат

    // glTranslatef(0.0f, 0.0f, -5.0f);
}

void GLWidget::function_rotate_x(int value) {
    xRot = static_cast<float>(value); // Update xRot with the slider value
    // Redraw the scene to reflect the updated transformation
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW); // устанавливает положение и ориентацию матрице моделирования

    glLoadIdentity(); // загружает единичную матрицу моделирования

    // последовательные преобразования
    // printf("%f",xRot);
    glRotatef(xRot, 1.0f, 0.0f, 0.0f); // поворот вокруг оси X
    glRotatef(yRot, 0.0f, 1.0f, 0.0f); // поворот вокруг оси Y
    glRotatef(zRot, 0.0f, 0.0f, 1.0f); // поворот вокруг оси Z
    glScalef(scale, scale, scale);        // масштабирование по осям
    glTranslatef(xMov, yMov, zMov);

   // glRotatef(yRot, 0.0f, 1.0f, 0.0f); // поворот вокруг оси Y
   //  glRotatef(zRot, 0.0f, 0.0f, 1.0f); // поворот вокруг оси Z
   //  glTranslatef(xTra, yTra, zTra);    // трансляция
   // glScalef(xSca, ySca, zSca);        // масштабирование по осям

    // example_drawAxis(); // рисование осей координат

    // glTranslatef(0.0f, 0.0f, -5.0f);
}

void GLWidget::function_rotate_y(int value) {
    yRot = static_cast<float>(value); // Update yRot with the slider value
    // Redraw the scene to reflect the updated transformation
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW); // устанавливает положение и ориентацию матрице моделирования

    glLoadIdentity(); // загружает единичную матрицу моделирования

    // последовательные преобразования
    // printf("%f",xRot);
    glRotatef(xRot, 1.0f, 0.0f, 0.0f); // поворот вокруг оси X
    glRotatef(yRot, 0.0f, 1.0f, 0.0f); // поворот вокруг оси Y
    glRotatef(zRot, 0.0f, 0.0f, 1.0f); // поворот вокруг оси Z
    glScalef(scale, scale, scale);        // масштабирование по осям
    glTranslatef(xMov, yMov, zMov);

    // glRotatef(yRot, 0.0f, 1.0f, 0.0f); // поворот вокруг оси Y
    //  glRotatef(zRot, 0.0f, 0.0f, 1.0f); // поворот вокруг оси Z
    //  glTranslatef(xTra, yTra, zTra);    // трансляция
    // glScalef(xSca, ySca, zSca);        // масштабирование по осям

    // example_drawAxis(); // рисование осей координат

    // glTranslatef(0.0f, 0.0f, -5.0f);
}

void GLWidget::function_rotate_z(int value) {
    zRot = static_cast<float>(value); // Update zRot with the slider value
    // Redraw the scene to reflect the updated transformation
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW); // устанавливает положение и ориентацию матрице моделирования

    glLoadIdentity(); // загружает единичную матрицу моделирования

    // последовательные преобразования
    // printf("%f",xRot);
    glRotatef(xRot, 1.0f, 0.0f, 0.0f); // поворот вокруг оси X
    glRotatef(yRot, 0.0f, 1.0f, 0.0f); // поворот вокруг оси Y
    glRotatef(zRot, 0.0f, 0.0f, 1.0f); // поворот вокруг оси Z
    glScalef(scale, scale, scale);        // масштабирование по осям
    glTranslatef(xMov, yMov, zMov);
}

void GLWidget::function_move_x(int value) {
    xMov = static_cast<float>(value) / 100; // Update zRot with the slider value
    // Redraw the scene to reflect the updated transformation
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW); // устанавливает положение и ориентацию матрице моделирования

    glLoadIdentity(); // загружает единичную матрицу моделирования

    // последовательные преобразования
    // printf("%f",xRot);
    glScalef(scale, scale, scale);        // масштабирование по осям
    glRotatef(xRot, 1.0f, 0.0f, 0.0f); // поворот вокруг оси X
    glRotatef(yRot, 0.0f, 1.0f, 0.0f); // поворот вокруг оси Y
    glRotatef(zRot, 0.0f, 0.0f, 1.0f); // поворот вокруг оси Z
    glTranslatef(xMov, yMov, zMov);   // трансляция
}

void GLWidget::function_move_y(int value) {
    yMov = static_cast<float>(value) / 100; // Update zRot with the slider value
    // Redraw the scene to reflect the updated transformation
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW); // устанавливает положение и ориентацию матрице моделирования

    glLoadIdentity(); // загружает единичную матрицу моделирования

    // последовательные преобразования
    // printf("%f",xRot);
    glScalef(scale, scale, scale);        // масштабирование по осям
    glRotatef(xRot, 1.0f, 0.0f, 0.0f); // поворот вокруг оси X
    glRotatef(yRot, 0.0f, 1.0f, 0.0f); // поворот вокруг оси Y
    glRotatef(zRot, 0.0f, 0.0f, 1.0f); // поворот вокруг оси Z
    glTranslatef(xMov, yMov, zMov);   // трансляция
}

void GLWidget::function_move_z(int value) {
    zMov = static_cast<float>(value) / 100; // Update zRot with the slider value
    // Redraw the scene to reflect the updated transformation
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW); // устанавливает положение и ориентацию матрице моделирования

    glLoadIdentity(); // загружает единичную матрицу моделирования

    // последовательные преобразования
    // printf("%f",xRot);
    glScalef(scale, scale, scale);        // масштабирование по осям
    glRotatef(xRot, 1.0f, 0.0f, 0.0f); // поворот вокруг оси X
    glRotatef(yRot, 0.0f, 1.0f, 0.0f); // поворот вокруг оси Y
    glRotatef(zRot, 0.0f, 0.0f, 1.0f); // поворот вокруг оси Z
    glTranslatef(xMov, yMov, zMov);   // трансляция
}
