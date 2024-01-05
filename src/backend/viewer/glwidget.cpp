#include "glwidget.h"
#include <GL/glut.h>
#include <QDebug>
#include <cstring>

GLWidget::GLWidget(QWidget *parent) : QGLWidget(parent) {
//    connect(&timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    initializeGLmodel();
}

void GLWidget::initializeGLmodel() {
    QDebug debug = qDebug();
    printf("%d\n",welcome_flag);
    printf("initializeGLmodel\n");
    if(welcome_flag==0){
        const char defaultModel[] = "../frontend/default_models/welcome.obj";
        objData = parse_obj(defaultModel, &parse_flag);
        baseobjData = parse_obj(defaultModel, &parse_flag);
        printf("IN WELCOME FLAG = 0\n");
    }
    else
    {
//        printf("if welcome_flag = 1\n");
        clear_obj_data(&objData);
        clear_obj_data(&baseobjData);
        printf("%s\n",model_name);
        objData = parse_obj(model_name, &parse_flag);
        baseobjData = parse_obj(model_name, &parse_flag);
    }

    if(parse_flag ==0){
//        printf("PARSEFLAG\n");
        draw_model();
        update();
    }
//    else {
//        const char defaultModel[] = "../frontend/default_models/error.obj";
//        objData = parse_obj(defaultModel, &parse_flag);
//        baseobjData = parse_obj(defaultModel, &parse_flag);
//        parse_flag = 0; Soon not here
//        draw_model();
//    }
}

void GLWidget::initializeGL() {
    printf("initializeGL\n");
    glClearColor(0.2, 0.2, 0.2, 1);
}


void GLWidget::paintGL() {
    printf("paintGL\n");
    glMatrixMode(GL_PROJECTION);

     draw_model();
}




void GLWidget::draw_model() {
    printf("draw_model\n");
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glVertexPointer(3, GL_FLOAT, 0, objData.vertices);
    glEnableClientState(GL_VERTEX_ARRAY);

    glColor3ub(255,255,0); // желтый
    glDrawArrays(GL_LINES, 0, objData.vertexCount);
}

void GLWidget::resizeGL(int w, int h) {
    printf("resizeGL\n");
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // gluPerspective(45.0, (GLfloat)w / (GLfloat)h, 0.1, 100.0);


}

void GLWidget::function_zoom_scale(int value) {
    printf("zoom_scale\n");
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    zoom_operation(value,value,value,&objData,baseobjData);

    draw_model();
}

void GLWidget::function_rotate_x(int value) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW); // устанавливает положение и ориентацию матрице моделирования

    rotate_operation(value,0.0,0.0,&objData,baseobjData);


    draw_model();

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

//void GLWidget::function_rotate_z(int value) {
//    zRot = static_cast<float>(value); // Update zRot with the slider value
//    // Redraw the scene to reflect the updated transformation
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//    glMatrixMode(GL_MODELVIEW); // устанавливает положение и ориентацию матрице моделирования

//    glLoadIdentity(); // загружает единичную матрицу моделирования

//    // последовательные преобразования
//    // printf("%f",xRot);
//    glRotatef(xRot, 1.0f, 0.0f, 0.0f); // поворот вокруг оси X
//    glRotatef(yRot, 0.0f, 1.0f, 0.0f); // поворот вокруг оси Y
//    glRotatef(zRot, 0.0f, 0.0f, 1.0f); // поворот вокруг оси Z
//    glScalef(scale, scale, scale);        // масштабирование по осям
//    glTranslatef(xMov, yMov, zMov);
//}

//void GLWidget::function_move_x(int value) {
//    xMov = static_cast<float>(value) / 100; // Update zRot with the slider value
//    // Redraw the scene to reflect the updated transformation
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//    glMatrixMode(GL_MODELVIEW); // устанавливает положение и ориентацию матрице моделирования

//    glLoadIdentity(); // загружает единичную матрицу моделирования

//    // последовательные преобразования
//    // printf("%f",xRot);
//    glScalef(scale, scale, scale);        // масштабирование по осям
//    glRotatef(xRot, 1.0f, 0.0f, 0.0f); // поворот вокруг оси X
//    glRotatef(yRot, 0.0f, 1.0f, 0.0f); // поворот вокруг оси Y
//    glRotatef(zRot, 0.0f, 0.0f, 1.0f); // поворот вокруг оси Z
//    glTranslatef(xMov, yMov, zMov);   // трансляция
//}

//void GLWidget::function_move_y(int value) {
//    yMov = static_cast<float>(value) / 100; // Update zRot with the slider value
//    // Redraw the scene to reflect the updated transformation
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//    glMatrixMode(GL_MODELVIEW); // устанавливает положение и ориентацию матрице моделирования

//    glLoadIdentity(); // загружает единичную матрицу моделирования

//    // последовательные преобразования
//    // printf("%f",xRot);
//    glScalef(scale, scale, scale);        // масштабирование по осям
//    glRotatef(xRot, 1.0f, 0.0f, 0.0f); // поворот вокруг оси X
//    glRotatef(yRot, 0.0f, 1.0f, 0.0f); // поворот вокруг оси Y
//    glRotatef(zRot, 0.0f, 0.0f, 1.0f); // поворот вокруг оси Z
//    glTranslatef(xMov, yMov, zMov);   // трансляция
//}

//void GLWidget::function_move_z(int value) {
//    zMov = static_cast<float>(value) / 100; // Update zRot with the slider value
//    // Redraw the scene to reflect the updated transformation
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//    glMatrixMode(GL_MODELVIEW); // устанавливает положение и ориентацию матрице моделирования

//    glLoadIdentity(); // загружает единичную матрицу моделирования

//    // последовательные преобразования
//    // printf("%f",xRot);
//    glScalef(scale, scale, scale);        // масштабирование по осям
//    glRotatef(xRot, 1.0f, 0.0f, 0.0f); // поворот вокруг оси X
//    glRotatef(yRot, 0.0f, 1.0f, 0.0f); // поворот вокруг оси Y
//    glRotatef(zRot, 0.0f, 0.0f, 1.0f); // поворот вокруг оси Z
//    glTranslatef(xMov, yMov, zMov);   // трансляция
//}
