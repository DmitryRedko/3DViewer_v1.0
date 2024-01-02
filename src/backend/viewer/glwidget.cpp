#include "glwidget.h"
#include <GL/glut.h>
#include <QDebug>

GLWidget::GLWidget(QWidget *parent) : QGLWidget(parent) {
    timer.start(16);
//    const char *file_path = "/home/dmitry/Desktop/School21/Viewer/src/models/katana.obj";
//    ObjData objData = parse_obj(file_path);

//    qDebug() << "Vertex count: " << objData.vertexCount;
//    qDebug() << "Texture count: " << objData.textureCount;
//    qDebug() << "Normal count: " << objData.normalCount;
//    qDebug() << "Face count: " << objData.faceCount;



//    qDebug() << objData.vertices[1].x;
//    qDebug() << objData.vertices[1].y;
//    qDebug() << objData.vertices[1].z;
//    // Выводим данные для проверки в консоль
//    qDebug() << "\nVertices:";
//    for (int i = 0; i < objData.vertexCount; ++i) {
//        qDebug() << "v " << objData.vertices[i].x << " " << objData.vertices[i].y << " " << objData.vertices[i].z;
//    }

//    printf("Vertices:\n");
//    for (int i = 0; i < objData.vertexCount;i++) {
//        qDebug() << "v"<< objData.vertices[i].x<< objData.vertices[i].y<< objData.vertices[i].z;
//    }

//    qDebug() << "\nNormals:";
//    for (int i = 0; i < objData.normalCount; ++i) {
//        qDebug() << "vn " << objData.normals[i].x << " " << objData.normals[i].y << " " << objData.normals[i].z;
//    }
}

void GLWidget::initializeGL() {
    glClearColor(0.2, 0.2, 0.2, 1);
    // glEnable(GL_DEPTH_TEST);
    // glEnable(GL_LIGHTING);
    // glEnable(GL_LIGHT0);

    // GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
    // glLightfv(GL_LIGHT0, GL_POSITION, light_position);
}

inline float ndc(float f)
{
    return f / 250.0f - 1.0f;
}

void GLWidget::example_drawCube()
{
static const GLfloat LightAmbient[]=  { 0.25f, 0.25f, 0.25f, 1.0f };    // Ambient Light Values
static const GLfloat LightDiffuse[]=  { 0.1f, 0.1f, 0.1f, 1.0f };    // Diffuse Light Values
static const GLfloat LightPosition[]= { 0.0f, 0.0f, 2.0f, 1.0f };    // Light Position

glPushAttrib(GL_COLOR_BUFFER_BIT | GL_CURRENT_BIT | GL_ENABLE_BIT | GL_LIGHTING_BIT | GL_POLYGON_BIT);

glColor4f(0.2f,0.35f,0.3f,0.75f);         // Full Brightness, 50% Alpha ( NEW )
glBlendFunc(GL_ONE,GL_ONE_MINUS_SRC_ALPHA);       // Blending Function For Translucency Based On Source Alpha
glEnable(GL_BLEND);

glShadeModel(GL_SMOOTH);

glEnable(GL_LIGHTING);
glDisable(GL_LIGHT0);
glEnable(GL_LIGHT1);
glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);
glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);
glLightfv(GL_LIGHT1, GL_POSITION, LightPosition);
glEnable(GL_COLOR_MATERIAL);

glScalef(0.25,0.25, 0.25);
glTranslatef(0,0, 1);

glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
glBegin(GL_QUADS);
// Front Face
glNormal3f( 0.0f, 0.0f, 1.0f);    // Normal Pointing Towards Viewer
glVertex3f(-1.0f, -1.0f,  1.0f);  // Point 1 (Front)
glVertex3f( 1.0f, -1.0f,  1.0f);  // Point 2 (Front)
glVertex3f( 1.0f,  1.0f,  1.0f);  // Point 3 (Front)
glVertex3f(-1.0f,  1.0f,  1.0f);  // Point 4 (Front)
// Back Face
glNormal3f( 0.0f, 0.0f,-1.0f);    // Normal Pointing Away From Viewer
glVertex3f(-1.0f, -1.0f, -1.0f);  // Point 1 (Back)
glVertex3f(-1.0f,  1.0f, -1.0f);  // Point 2 (Back)
glVertex3f( 1.0f,  1.0f, -1.0f);  // Point 3 (Back)
glVertex3f( 1.0f, -1.0f, -1.0f);  // Point 4 (Back)
// Top Face
glNormal3f( 0.0f, 1.0f, 0.0f);    // Normal Pointing Up
glVertex3f(-1.0f,  1.0f, -1.0f);  // Point 1 (Top)
glVertex3f(-1.0f,  1.0f,  1.0f);  // Point 2 (Top)
glVertex3f( 1.0f,  1.0f,  1.0f);  // Point 3 (Top)
glVertex3f( 1.0f,  1.0f, -1.0f);  // Point 4 (Top)
// Bottom Face
glNormal3f( 0.0f,-1.0f, 0.0f);    // Normal Pointing Down
glVertex3f(-1.0f, -1.0f, -1.0f);  // Point 1 (Bottom)
glVertex3f( 1.0f, -1.0f, -1.0f);  // Point 2 (Bottom)
glVertex3f( 1.0f, -1.0f,  1.0f);  // Point 3 (Bottom)
glVertex3f(-1.0f, -1.0f,  1.0f);  // Point 4 (Bottom)
// Right face
glNormal3f( 1.0f, 0.0f, 0.0f);    // Normal Pointing Right
glVertex3f( 1.0f, -1.0f, -1.0f);  // Point 1 (Right)
glVertex3f( 1.0f,  1.0f, -1.0f);  // Point 2 (Right)
glVertex3f( 1.0f,  1.0f,  1.0f);  // Point 3 (Right)
glVertex3f( 1.0f, -1.0f,  1.0f);  // Point 4 (Right)
// Left Face
glNormal3f(-1.0f, 0.0f, 0.0f);    // Normal Pointing Left
glVertex3f(-1.0f, -1.0f, -1.0f);  // Point 1 (Left)
glVertex3f(-1.0f, -1.0f,  1.0f);  // Point 2 (Left)
glVertex3f(-1.0f,  1.0f,  1.0f);  // Point 3 (Left)
glVertex3f(-1.0f,  1.0f, -1.0f);  // Point 4 (Left)
glEnd();

glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
glColor4f(0.2f,0.65f,0.3f,0.35f); // Full Brightness, 50% Alpha ( NEW )
glBegin(GL_QUADS);
// Front Face
glNormal3f( 0.0f, 0.0f, 1.0f);    // Normal Pointing Towards Viewer
glVertex3f(-1.0f, -1.0f,  1.0f);  // Point 1 (Front)
glVertex3f( 1.0f, -1.0f,  1.0f);  // Point 2 (Front)
glVertex3f( 1.0f,  1.0f,  1.0f);  // Point 3 (Front)
glVertex3f(-1.0f,  1.0f,  1.0f);  // Point 4 (Front)
// Back Face
glNormal3f( 0.0f, 0.0f,-1.0f);    // Normal Pointing Away From Viewer
glVertex3f(-1.0f, -1.0f, -1.0f);  // Point 1 (Back)
glVertex3f(-1.0f,  1.0f, -1.0f);  // Point 2 (Back)
glVertex3f( 1.0f,  1.0f, -1.0f);  // Point 3 (Back)
glVertex3f( 1.0f, -1.0f, -1.0f);  // Point 4 (Back)
// Top Face
glNormal3f( 0.0f, 1.0f, 0.0f);    // Normal Pointing Up
glVertex3f(-1.0f,  1.0f, -1.0f);  // Point 1 (Top)
glVertex3f(-1.0f,  1.0f,  1.0f);  // Point 2 (Top)
glVertex3f( 1.0f,  1.0f,  1.0f);  // Point 3 (Top)
glVertex3f( 1.0f,  1.0f, -1.0f);  // Point 4 (Top)
// Bottom Face
glNormal3f( 0.0f,-1.0f, 0.0f);    // Normal Pointing Down
glVertex3f(-1.0f, -1.0f, -1.0f);  // Point 1 (Bottom)
glVertex3f( 1.0f, -1.0f, -1.0f);  // Point 2 (Bottom)
glVertex3f( 1.0f, -1.0f,  1.0f);  // Point 3 (Bottom)
glVertex3f(-1.0f, -1.0f,  1.0f);  // Point 4 (Bottom)
// Right face
glNormal3f( 1.0f, 0.0f, 0.0f);    // Normal Pointing Right
glVertex3f( 1.0f, -1.0f, -1.0f);  // Point 1 (Right)
glVertex3f( 1.0f,  1.0f, -1.0f);  // Point 2 (Right)
glVertex3f( 1.0f,  1.0f,  1.0f);  // Point 3 (Right)
glVertex3f( 1.0f, -1.0f,  1.0f);  // Point 4 (Right)
// Left Face
glNormal3f(-1.0f, 0.0f, 0.0f);    // Normal Pointing Left
glVertex3f(-1.0f, -1.0f, -1.0f);  // Point 1 (Left)
glVertex3f(-1.0f, -1.0f,  1.0f);  // Point 2 (Left)
glVertex3f(-1.0f,  1.0f,  1.0f);  // Point 3 (Left)
glVertex3f(-1.0f,  1.0f, -1.0f);  // Point 4 (Left)
glEnd();

glPopAttrib();
}

void GLWidget::example_drawAxis()
{
    glLineWidth(1.0f); // устанавливаю ширину линии приближённо в пикселях
    // до вызова здесь команды ширина была равна 1 пикселю по умолчанию

    glColor4f(1.00f, 0.00f, 0.00f, 1.0f); // устанавливается цвет последующих примитивов
    // ось x красного цвета
    glBegin(GL_LINES); // построение линии
    glVertex3f( 1.0f,  0.0f,  0.0f); // первая точка
    glVertex3f(-1.0f,  0.0f,  0.0f); // вторая точка
    glEnd();

    QColor halfGreen(0, 128, 0, 255);
    qglColor(halfGreen);
    glBegin(GL_LINES);
    // ось y зеленого цвета
    glVertex3f( 0.0f,  1.0f,  0.0f);
    glVertex3f( 0.0f, -1.0f,  0.0f);

    glColor4f(0.00f, 0.00f, 1.00f, 1.0f);
    // ось z синего цвета
    glVertex3f( 0.0f,  0.0f,  1.0f);
    glVertex3f( 0.0f,  0.0f, -1.0f);
    glEnd();
}

void GLWidget::paintGL() {

    // const char *file_path = "/home/dmitry/Desktop/School21/Viewer/src/models/model2.obj";
    const char *file_path = "../models/cube.obj";
    ObjData objData = parse_obj(file_path);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW); // устанавливает положение и ориентацию матрице моделирования

    glLoadIdentity(); // загружает единичную матрицу моделирования

    // последовательные преобразования
   // glRotatef(0, 1.0f, 0.0f, 0.0f); // поворот вокруг оси X
   // glRotatef(yRot, 0.0f, 1.0f, 0.0f); // поворот вокруг оси Y
   //  glRotatef(zRot, 0.0f, 0.0f, 1.0f); // поворот вокруг оси Z
   //  glTranslatef(xTra, yTra, zTra);    // трансляция
   // glScalef(xSca, ySca, zSca);        // масштабирование по осям

    example_drawAxis(); // рисование осей координат

    // glTranslatef(0.0f, 0.0f, -5.0f);

    glBegin(GL_TRIANGLES);
    // printf("faceCount %d\n", objData.faceCount);
    // for (int i = 0; i < objData.faceCount; ++i) {
    //     for (int j = 0; j < 3; ++j) {
    //         int vIndex = objData.faces[i].vIndex[j] - 1; // Массивы в .obj начинаются с 1
    //         int vnIndex = objData.faces[i].vnIndex[j] - 1;

    //         glNormal3f(objData.normals[vnIndex].x, objData.normals[vnIndex].y, objData.normals[vnIndex].z);
    //         printf("glNormal3f %f %f %f\n", objData.normals[vnIndex].x, objData.normals[vnIndex].y, objData.normals[vnIndex].z);
    //         glVertex3f(objData.vertices[vIndex].x, objData.vertices[vIndex].y, objData.vertices[vIndex].z);
    //         printf("glVertex3f %f %f %f\n", objData.vertices[vIndex].x, objData.vertices[vIndex].y, objData.vertices[vIndex].z);
    //         // glNormal3f(ndc(objData.normals[vnIndex].x), ndc(objData.normals[vnIndex].y), ndc(objData.normals[vnIndex].z));
    //         // glVertex3f(ndc(objData.vertices[vIndex].x), ndc(objData.vertices[vIndex].y), ndc(objData.vertices[vIndex].z));
    //     }
    // }
    glEnd();

    glFlush();

    // Отрисовка куба
    example_drawCube();

}

void GLWidget::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // gluPerspective(45.0, (GLfloat)w / (GLfloat)h, 0.1, 100.0);
}
