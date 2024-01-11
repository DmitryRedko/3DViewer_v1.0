#ifndef MAINVIEWER_H
#define MAINVIEWER_H

#include <QColorDialog>
#include <QMainWindow>
#include <QSettings>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QPoint>
#include <QObject>
#include <QScreen>
#include <QDateTime>

#include <QImage>
#include <QOpenGLFramebufferObject>
#include <QIcon>
#include <QPushButton>
#include <QImageReader>
#include <QMessageBox>

// #include <gif_lib.h>e
// #include <libgif/encoder.h>
// #include <iostream>
#include <3rdparty/QtGifImage/src/gifimage/qgifimage.h>


#include "glwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainViewer;
}
QT_END_NAMESPACE

class MainViewer : public QMainWindow {
  Q_OBJECT

 public:
  MainViewer(QWidget *parent = nullptr);
  ~MainViewer();
  QString fileName;

 private:
  Ui::MainViewer *ui;
  GLWidget *myGLW;
  void captureOpenGLScene();
  void bind_slots();
  //gif
  QString gif_name;
  QGifImage *gif_frame;
  int frames_counter = 0;
  QTimer timer;

 public:
  QSettings *settings;
     QPoint cur_pos;
     QPoint new_pos;

 signals:
     void valueChanged(int);


 private slots:
  void on_rotate_x_valueChanged();
  void on_rotate_y_valueChanged();
  void on_rotate_z_valueChanged();
  void on_zoom_scale_valueChanged();
  void on_move_x_valueChanged();
  void on_move_y_valueChanged();
  void on_move_z_valueChanged();
  void on_reset_model_released();
  void on_fileBtm_clicked();
  void on_openBtm_clicked();
  void on_point_size_scale_valueChanged(int value);
  void on_line_width_scale_valueChanged(int value);
  void on_line_type_toggled(bool checked);
  void on_openBtm_released();
  void on_pointColor_clicked();
  void on_lineColor_clicked();
  void on_BGColor_clicked();
  void on_resetColor_clicked();
  void on_noLine_clicked();
  void on_line_clicked();
  void on_lineLoop_clicked();
  void on_quads_clicked();
  void on_perspective_clicked();
  void on_parallel_clicked();
  void update_sliders();
  void save_settings();
  void load_settings();
  void mouseMoveEvent (QMouseEvent* event) override;
   void wheelEvent(QWheelEvent *event) override;

  void on_pushButton_clicked();
  void on_saveImage_clicked();



  // void saveGif(QGLWidget *widget, const QString &fileName);
  void saveGif();
  void on_save_gif_button_pressed();
  void on_save_gif_button_clicked();
};
#endif  // MAINVIEWER_H
