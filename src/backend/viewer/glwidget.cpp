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
        baseobjData = parse_obj(defaultModel, &parse_flag);
        welcome_flag = 1;
    }
    else
    {
        objData = parse_obj(model_name, &parse_flag);
        baseobjData = parse_obj(model_name, &parse_flag);
    }

    if(parse_flag ==0){
        printf("PARSEFLAG\n");
        draw_model();
    }
    else {
        const char defaultModel[] = "../frontend/default_models/error.obj";
        objData = parse_obj(defaultModel, &parse_flag);
        baseobjData = parse_obj(defaultModel, &parse_flag);
        parse_flag = 0;
    }
}

void GLWidget::initializeGL() {
    glClearColor(0.2, 0.2, 0.2, 1);
    printf("INICIALIGEGLMODEL");
//     glEnable(GL_DEPTH_TEST);
//     glEnable(GL_LIGHTING);
//     glEnable(GL_LIGHT0);

//     GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
//     glLightfv(GL_LIGHT0, GL_POSITION, light_position);

}


void GLWidget::paintGL() {
    glMatrixMode(GL_PROJECTION);
    // draw_model();
}




void GLWidget::draw_model() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // glEnableClientState(GL_VERTEX_ARRAY); //На практике инициализация vertex arrays выполняется с помощью glEnableClientState()
    // glVertexPointer(3, GL_FLOAT, 0, objData.vertices);
    // glBegin(GL_LINES);
    //     glDrawElements(GL_LINES, objData.faceCount, GL_FLOAT, objData.faces);
    // glEnd();

    // Установка массива для вершинных координат происходит функцией glVertexPointer():
    // glVertexPointer(3, GL_FLOAT, 0, pVerts);
    // Первый параметр в этой функции говорит, сколько координат идёт на одну вершину, возможные значения - 2,3,4. Второй параметр отвечает за тип координат. Третий параметр равен шагу в байтах между данными с координатами для каждой вершины. 0 в нашем случае означает, что координаты лежат плотно друг за другом. Четвёртый параметр - собственно сам указатель на массив с координатами.
    glVertexPointer(3, GL_FLOAT, 0, objData.vertices);

    // Кроме того, что мы выставили указатель на массив, необходимо выставить состояние для OpenGL, означающее, что мы будем использовать указатель на массив вершин. Это состояние выставляется функцией glEnableClientState().
    glEnableClientState(GL_VERTEX_ARRAY);


    // glDrawArrays()
    //     Выводит примитивы по данным в массивах.
    //             glDrawArrays(mode, first, count);
    // mode - режим, отвечающий за тип примитива,
    // first - индекс вершины, с которой мы будем выводить объект,
    // count - количество вершин.
    glColor3ub(255,255,0); // желтый
    glDrawArrays(GL_LINES, 0, objData.vertexCount);


    // Однако индексы также можно задавать массивом и выводить объект одним вызовом без пары glBegin() и glEnd().
    // Это можно сделать функцией:
    // glDrawElements()
    // glDrawElements(mode, count, type, indices);
    // Здесь
    // mode - как всегда выставляет режим типа полигонов,
    // count - количество индексов, берущихся из массива,
    // type - тип элементов в индексном массиве, может принимать значения: GL_UNSIGNED_BYTE, GL_UNSIGNED_SHORT или GL_UNSIGNED_INT. Обычно под индексы используют unsigned short.
    // indices - указатель на массив с индексами. Заметьте, что этот указатель можно расценить, как указатель на элемент, с которого будет происходить расчёт объекта. То есть вы можете поставить указатель на любой элемент в массиве.
    // Для ясности новый пример:
    // glDrawElements(GL_TRIANGLES, objData.faceCount, GL_FLOAT, objData.faces);




    // glBegin(GL_LINES);
    // glColor3ub(255,255,0); // желтый

    printf("\nChanged2: %f %f %f\n", objData.vertices[0].x, objData.vertices[0].y, objData.vertices[0].z);

    // for (int i = 0; i < objData.faceCount; ++i) {
    //     for (int j = 0; j < 3; ++j) {
    //         int vIndex = objData.faces[i].vIndex[j] - 1; // Массивы в .obj начинаются с 1
    //         glVertex3f(objData.vertices[vIndex].x, objData.vertices[vIndex].y, objData.vertices[vIndex].z);
    //     }
    // }
    printf("\nChanged3: %f %f %f\n", objData.vertices[0].x, objData.vertices[0].y, objData.vertices[0].z);
    // glEnd();

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
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW); // устанавливает положение и ориентацию матрице моделирования

//    glLoadIdentity(); // загружает единичную матрицу моделирования

    rotate_operation(value,0.0,0.0,&objData,baseobjData);

    printf("\nChanged1: %f %f %f\n", objData.vertices[0].x, objData.vertices[0].y, objData.vertices[0].z);

    draw_model();

}

//void GLWidget::function_rotate_y(int value) {
//    yRot = static_cast<float>(value); // Update yRot with the slider value
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

//    // glRotatef(yRot, 0.0f, 1.0f, 0.0f); // поворот вокруг оси Y
//    //  glRotatef(zRot, 0.0f, 0.0f, 1.0f); // поворот вокруг оси Z
//    //  glTranslatef(xTra, yTra, zTra);    // трансляция
//    // glScalef(xSca, ySca, zSca);        // масштабирование по осям

//    // example_drawAxis(); // рисование осей координат

//    // glTranslatef(0.0f, 0.0f, -5.0f);
//}

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
