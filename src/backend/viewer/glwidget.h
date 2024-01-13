#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <GL/glut.h>

#include <QGLWidget>
#include <QTimer>
#include <QWheelEvent>

extern "C" {
#include "../backend.h"  // Include your OBJ parser header
}

class GLWidget : public QGLWidget {
 public:
  explicit GLWidget(QWidget *parent = nullptr);
  void initializeGL() override;
  void paintGL() override;
  ;
  void resizeGL(int w, int h) override;
  ;
  void draw_model();
  void draw_model_lines();
  void initializeGLmodel();
  void apply_transform();
  void free_memory();

  char model_name[100] = "../frontend/default_models/welcome_3d.obj";
  int parse_flag = 0;
  //  int before_parse_flag = 0;
  ObjData objData;
  ObjData baseData;
  void normalize_model(ObjData *data);

  float default_scale = 100, default_xRot = 0.0f, default_yRot = 0.0f,
        default_zRot = 0.0f, default_xMov = 0.0f, default_yMov = 0.0f,
        default_zMov = 0.0f;

  int default_point_size = 2;
  int default_line_width = 1;
  int default_line_type = 1;

  GLenum default_primitive_type = GL_LINES;

  int default_perspective = 0;

  int default_point_red = 255;
  int default_point_green = 255;
  int default_point_blue = 0;

  int default_line_red = 255;
  int default_line_green = 0;
  int default_line_blue = 0;

  int default_background_red = 51;
  int default_background_green = 51;
  int default_background_blue = 51;

  int point_size = default_point_size;
  int line_width = default_line_width;
  int line_type = default_line_type;

  int draw_lines = 1;
  int isPerspective = default_perspective;

  int point_color_red = default_point_red;
  int point_color_green = default_point_green;
  int point_color_blue = default_point_blue;
  int background_color_red = default_background_red;
  int background_color_green = default_background_green;
  int background_color_blue = default_background_blue;

  int line_color_red = default_line_red;
  int line_color_green = default_line_green;
  int line_color_blue = default_line_blue;

  GLenum primitive_type = default_primitive_type;

  float scale = default_scale, xRot = default_xRot, yRot = default_yRot,
        zRot = default_zRot, xMov = default_xMov, yMov = default_yMov,
        zMov = default_zMov;

  // void mouseMoveEvent(QMouseEvent *event);
  // void wheelEvent(QWheelEvent *event) override;
  QPoint cur_pos;
  QPoint new_pos;

 private:
  int many_retry_error = 0;
};

#endif  // GLWIDGET_H
