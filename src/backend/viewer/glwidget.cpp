#include "glwidget.h"
#include <GL/glut.h>
#include <QDebug>

GLWidget::GLWidget(QWidget *parent) : QGLWidget(parent) {
    timer.start(16);
    const char *file_path = "/home/dmitry/Desktop/School21/Viewer/src/models/model1.obj";
    ObjData objData = parse_obj(file_path);

    qDebug() << "Vertex count: " << objData.vertexCount;
    qDebug() << "Texture count: " << objData.textureCount;
    qDebug() << "Normal count: " << objData.normalCount;
    qDebug() << "Face count: " << objData.faceCount;



    qDebug() << objData.vertices[1].x;
    qDebug() << objData.vertices[1].y;
    qDebug() << objData.vertices[1].z;
    // Выводим данные для проверки в консоль
    qDebug() << "\nVertices:";
    for (int i = 0; i < objData.vertexCount; ++i) {
        qDebug() << "v " << objData.vertices[i].x << " " << objData.vertices[i].y << " " << objData.vertices[i].z;
    }

    printf("Vertices:\n");
    for (int i = 0; i < objData.vertexCount;i++) {
        qDebug() << "v"<< objData.vertices[i].x<< objData.vertices[i].y<< objData.vertices[i].z;
    }

    qDebug() << "\nNormals:";
    for (int i = 0; i < objData.normalCount; ++i) {
        qDebug() << "vn " << objData.normals[i].x << " " << objData.normals[i].y << " " << objData.normals[i].z;
    }
}

void GLWidget::initializeGL() {
    glClearColor(0.2, 0.2, 0.2, 1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
}

void GLWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0.0f, 0.0f, -5.0f);

    glBegin(GL_TRIANGLES);
    for (int i = 0; i < objData.vertexCount; ++i) {
        glVertex3f(objData.vertices[i].x, objData.vertices[i].y, objData.vertices[i].z);
    }


    for (int i = 0; i < objData.normalCount; ++i) {
        glNormal3f(objData.normals[i].x, objData.normals[i].y, objData.normals[i].z);

    }

    glEnd();

    glFlush();
}

void GLWidget::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (GLfloat)w / (GLfloat)h, 0.1, 100.0);
}
