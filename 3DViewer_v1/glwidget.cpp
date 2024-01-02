#include "glwidget.h"
#include <GL/glut.h>

GLWidget::GLWidget(QWidget *parent) : QGLWidget(parent)
{
    connect(&timer,SIGNAL(timeout()),this,SLOT(updateGL()));
    timer.start(16);

}

void GLWidget::initializeGL(){
    glClearColor(0.2,0.2,0.2,1);
//    glEnable(GL_DEPTH_TEST);
//    glEnable(GL_LIGHT0);
//    glEnable(GL_LIGHTING);


}
void GLWidget::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT);

    glRotatef(0.5,1,1,1);
    glutWireTeapot(0.6);

}
void GLWidget::resizeGL(int w, int h){
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}