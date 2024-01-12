#include "mainviewer.h"

#include <QDebug>
#include <QFileDialog>
#include <cstring>

#include <QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCore/QCoreApplication>

#include "ui_mainviewer.h"

MainViewer::MainViewer(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainViewer) {
  ui->setupUi(this);
  myGLW = new GLWidget;

  bind_slots();

  settings = new QSettings("21school", "3D_Viewer", this);

  // Assuming your image file is in the resource file or on the disk
  QString imagePath = "../frontend/photo.png"; // Replace with the actual path
  QString imagePath2 = "../frontend/video.png"; // Replace with the actual path

  // Load the image into a QIcon
  QIcon icon(imagePath);
  QIcon icon2(imagePath2);

  // Set the icon for the button
  ui->saveImage->setIcon(icon);
  ui->save_gif_button->setIcon(icon2);

  // Adjust the size of the button to fit the icon
  ui->saveImage->setIconSize(QSize(50, 50)); // Set the desired size
  ui->save_gif_button->setIconSize(QSize(50, 50));

  load_settings();

  update_sliders();

  QString file_name = ui->GLwidget->model_name;

  ui->model_name_and_props->setText(
      "Model name: " + QFileInfo(file_name).fileName() + " with " +
      QString::number(ui->GLwidget->objData.vertexCount) + " vertices and " +
      QString::number(ui->GLwidget->objData.faceCount) + " faces, size: " +
      QString::number(QFileInfo(file_name).size() / 1000, 'f', 3) + " kb");

  ui->GLwidget->update();
}

MainViewer::~MainViewer() {
  save_settings();
  ui->GLwidget->free_memory();
  delete ui;
}

void MainViewer::bind_slots() {
    // connect(timer, SIGNAL(timeout()), this, SLOT(saveGif()));
    QObject::connect(&timer, &QTimer::timeout, [this]{
        saveGif();
        // qDebug() << "Timer expired";
    });
}

void MainViewer::update_sliders() {
  ui->point_size_scale->setValue(ui->GLwidget->point_size);
  ui->line_type->setChecked(ui->GLwidget->line_type);
  ui->zoom_scale->setValue(ui->GLwidget->scale);
  ui->rotate_x->setValue(ui->GLwidget->xRot);
  ui->rotate_y->setValue(ui->GLwidget->yRot);
  ui->rotate_z->setValue(ui->GLwidget->zRot);
  ui->move_x->setValue(ui->GLwidget->xMov);
  ui->move_y->setValue(ui->GLwidget->yMov);
  ui->move_z->setValue(ui->GLwidget->zMov);
  ui->line_width_scale->setValue(ui->GLwidget->line_width);

  if (ui->GLwidget->isPerspective)
    ui->perspective->toggle();
  else
    ui->parallel->toggle();

  switch (ui->GLwidget->primitive_type) {
    case GL_POINTS:
      ui->noLine->toggle();
      break;
    case GL_LINES:
      ui->line->toggle();
      break;
    case GL_LINE_LOOP:
      ui->lineLoop->toggle();
      break;
    case GL_QUADS:
      ui->quads->toggle();
  }
}

void MainViewer::on_rotate_x_valueChanged() {
  ui->rotate_title_3->setText(
      "Rotate: x = " + QString::number(ui->rotate_x->value()) +
      " y = " + QString::number(ui->rotate_y->value()) +
      " z = " + QString::number(ui->rotate_z->value()));
  ui->GLwidget->xRot = ui->rotate_x->value();
  ui->GLwidget->apply_transform();
  ui->GLwidget->update();
}

void MainViewer::on_rotate_y_valueChanged() {
  ui->rotate_title_3->setText(
      "Rotate: x = " + QString::number(ui->rotate_x->value()) +
      " y = " + QString::number(ui->rotate_y->value()) +
      " z = " + QString::number(ui->rotate_z->value()));
  ui->GLwidget->yRot = ui->rotate_y->value();
  ui->GLwidget->apply_transform();
  ui->GLwidget->update();
}

void MainViewer::on_rotate_z_valueChanged() {
  ui->rotate_title_3->setText(
      "Rotate: x = " + QString::number(ui->rotate_x->value()) +
      " y = " + QString::number(ui->rotate_y->value()) +
      " z = " + QString::number(ui->rotate_z->value()));
  ui->GLwidget->zRot = ui->rotate_z->value();
  ui->GLwidget->apply_transform();
  ui->GLwidget->update();
}

void MainViewer::on_zoom_scale_valueChanged() {
  ui->rotate_title->setText("Zoom: " +
                            QString::number(ui->zoom_scale->value()));
  ui->GLwidget->scale = ui->zoom_scale->value();
  ui->GLwidget->apply_transform();
  ui->GLwidget->update();
}

void MainViewer::on_move_x_valueChanged() {
  ui->translate_title->setText(
      "Move: x = " + QString::number(ui->move_x->value()) +
      " y = " + QString::number(ui->move_y->value()) +
      " z = " + QString::number(ui->move_z->value()));
  ui->GLwidget->xMov = ui->move_x->value();
  ui->GLwidget->apply_transform();
  ui->GLwidget->update();
}

void MainViewer::on_move_y_valueChanged() {
  ui->translate_title->setText(
      "Move: x = " + QString::number(ui->move_x->value()) +
      " y = " + QString::number(ui->move_y->value()) +
      " z = " + QString::number(ui->move_z->value()));
  ui->GLwidget->yMov = ui->move_y->value();
  ui->GLwidget->apply_transform();
  ui->GLwidget->update();
}

void MainViewer::on_move_z_valueChanged() {
  ui->translate_title->setText(
      "Move: x = " + QString::number(ui->move_x->value()) +
      " y = " + QString::number(ui->move_y->value()) +
      " z = " + QString::number(ui->move_z->value()));
  ui->GLwidget->zMov = ui->move_z->value();
  ui->GLwidget->apply_transform();
  ui->GLwidget->update();
}

void MainViewer::on_reset_model_released() {
  ui->zoom_scale->setValue(ui->GLwidget->default_scale);
  ui->rotate_x->setValue(ui->GLwidget->default_xRot);
  ui->rotate_y->setValue(ui->GLwidget->default_yRot);
  ui->rotate_z->setValue(ui->GLwidget->default_zRot);
  ui->move_x->setValue(ui->GLwidget->default_xMov);
  ui->move_y->setValue(ui->GLwidget->default_yMov);
  ui->move_z->setValue(ui->GLwidget->default_zMov);

  ui->point_size_scale->setValue(ui->GLwidget->default_point_size);
  ui->line_type->setChecked(ui->GLwidget->default_line_type);
  ui->line_width_scale->setValue(ui->GLwidget->default_line_width);

  ui->GLwidget->isPerspective = ui->GLwidget->default_perspective;
  if (ui->GLwidget->isPerspective)
    ui->perspective->toggle();
  else
    ui->parallel->toggle();

  ui->GLwidget->primitive_type = ui->GLwidget->default_primitive_type;
  switch (ui->GLwidget->primitive_type) {
    case GL_POINTS:
      ui->noLine->toggle();
      break;
    case GL_LINES:
      ui->line->toggle();
      break;
    case GL_LINE_LOOP:
      ui->lineLoop->toggle();
      break;
    case GL_QUADS:
      ui->quads->toggle();
  }
  ui->GLwidget->draw_lines = 1;

  ui->GLwidget->resizeGL(ui->GLwidget->width(), ui->GLwidget->height());
  ui->GLwidget->update();
}

void MainViewer::on_fileBtm_clicked() {
  fileName = QFileDialog::getOpenFileName(this, tr("Выберите файл"), "",
                                          tr("Все файлы (*)"));
  ui->pathLine->setText(fileName);
}

void MainViewer::on_openBtm_clicked() {
  if (!fileName.isEmpty()) {
    ui->GLwidget->free_memory();  //крашит приложение при открытие не модели

    QByteArray byteArray = fileName.toUtf8();
    const char* charFileName = byteArray.constData();
    char* model_name =
        ui->GLwidget->model_name;  // Получаем указатель на массив
    if (charFileName != nullptr) {
      strncpy(model_name, charFileName, sizeof(ui->GLwidget->model_name) - 1);
      model_name[sizeof(ui->GLwidget->model_name) - 1] = '\0';
    }

    ui->GLwidget->initializeGLmodel();
    on_reset_model_released();

    QString file_name = ui->pathLine->text();
    ui->model_name_and_props->setText(
        "Model name: " + QFileInfo(file_name).fileName() + " with " +
        QString::number(ui->GLwidget->objData.vertexCount) + " vertices and " +
        QString::number(ui->GLwidget->objData.faceCount) + " faces, size: " +
        QString::number(QFileInfo(file_name).size() / 1000, 'f', 3) + " kb");
  }
}

void MainViewer::on_point_size_scale_valueChanged(int value) {
  ui->point_size_title->setText("Point size: " +
                                QString::number(ui->point_size_scale->value()));
  ui->GLwidget->point_size = value;
  ui->GLwidget->update();
}

void MainViewer::on_line_width_scale_valueChanged(int value) {
  ui->line_width_title->setText("Line width: " +
                                QString::number(ui->line_width_scale->value()));
  ui->GLwidget->line_width = value;
  ui->GLwidget->update();
}

void MainViewer::on_line_type_toggled(bool checked) {
  //    printf("\nchecked %d\n", checked);
  if (checked == 1) {
    ui->GLwidget->line_type = 1;
  } else {
    ui->GLwidget->line_type = 0;
  }
  ui->GLwidget->update();
}

void MainViewer::on_openBtm_released() { on_reset_model_released(); }

void MainViewer::on_pointColor_clicked() {
  QColor color = QColorDialog::getColor(
      QColor(ui->GLwidget->point_color_red, ui->GLwidget->point_color_green,
             ui->GLwidget->point_color_blue),
      this);
  if (color.isValid()) {
    ui->GLwidget->point_color_red = static_cast<GLubyte>(color.red());
    ui->GLwidget->point_color_blue = static_cast<GLubyte>(color.blue());
    ui->GLwidget->point_color_green = static_cast<GLubyte>(color.green());
    ui->GLwidget->update();
  }
}

void MainViewer::on_lineColor_clicked() {
  QColor color = QColorDialog::getColor(
      QColor(ui->GLwidget->line_color_red, ui->GLwidget->line_color_green,
             ui->GLwidget->line_color_blue),
      this);
  if (color.isValid()) {
    ui->GLwidget->line_color_red = static_cast<GLubyte>(color.red());
    ui->GLwidget->line_color_blue = static_cast<GLubyte>(color.blue());
    ui->GLwidget->line_color_green = static_cast<GLubyte>(color.green());
    ui->GLwidget->update();
  }
}

void MainViewer::on_BGColor_clicked() {
  QColor color =
      QColorDialog::getColor(QColor(ui->GLwidget->background_color_red,
                                    ui->GLwidget->background_color_green,
                                    ui->GLwidget->background_color_blue),
                             this);
  if (color.isValid()) {
    ui->GLwidget->background_color_red = static_cast<GLubyte>(color.red());
    ui->GLwidget->background_color_blue = static_cast<GLubyte>(color.blue());
    ui->GLwidget->background_color_green = static_cast<GLubyte>(color.green());
    ui->GLwidget->update();
  }
}

void MainViewer::on_resetColor_clicked() {
  ui->GLwidget->point_color_red = ui->GLwidget->default_point_red;
  ui->GLwidget->point_color_blue = ui->GLwidget->default_point_blue;
  ui->GLwidget->point_color_green = ui->GLwidget->default_point_green;

  ui->GLwidget->line_color_red = ui->GLwidget->default_line_red;
  ui->GLwidget->line_color_blue = ui->GLwidget->default_line_blue;
  ui->GLwidget->line_color_green = ui->GLwidget->default_line_green;

  ui->GLwidget->background_color_red = ui->GLwidget->default_background_red;
  ui->GLwidget->background_color_blue = ui->GLwidget->default_background_blue;
  ui->GLwidget->background_color_green = ui->GLwidget->default_background_green;
  ui->GLwidget->update();
}

void MainViewer::on_noLine_clicked() {
  ui->GLwidget->draw_lines = 0;
  ui->GLwidget->primitive_type = GL_POINTS;
  ui->GLwidget->update();
}

void MainViewer::on_line_clicked() {
  ui->GLwidget->draw_lines = 1;
  ui->GLwidget->primitive_type = GL_LINES;
  ui->GLwidget->update();
}

void MainViewer::on_lineLoop_clicked() {
  ui->GLwidget->draw_lines = 1;
  ui->GLwidget->primitive_type = GL_LINE_LOOP;
  ui->GLwidget->update();
}

void MainViewer::on_quads_clicked() {
  ui->GLwidget->draw_lines = 1;
  ui->GLwidget->primitive_type = GL_QUADS;
  ui->GLwidget->update();
}

void MainViewer::on_perspective_clicked() {
  ui->GLwidget->isPerspective = 1;

  ui->GLwidget->resizeGL(ui->GLwidget->width(), ui->GLwidget->height());
  ui->GLwidget->update();
}

void MainViewer::on_parallel_clicked() {
  ui->GLwidget->isPerspective = 0;

  ui->GLwidget->resizeGL(ui->GLwidget->width(), ui->GLwidget->height());
  ui->GLwidget->update();
}

void MainViewer::save_settings() {
  settings->setValue("are_settings", 1);
  settings->setValue("point_size", ui->GLwidget->point_size);
  settings->setValue("line_type", ui->GLwidget->line_type);
  settings->setValue("line_width", ui->GLwidget->line_width);
  settings->setValue("primitive_type", ui->GLwidget->primitive_type);
  settings->setValue("projection_type", ui->GLwidget->isPerspective);

  settings->setValue("line_color_red", ui->GLwidget->line_color_red);
  settings->setValue("line_color_green", ui->GLwidget->line_color_green);
  settings->setValue("line_color_blue", ui->GLwidget->line_color_blue);

  settings->setValue("point_color_red", ui->GLwidget->point_color_red);
  settings->setValue("point_color_green", ui->GLwidget->point_color_green);
  settings->setValue("point_color_blue", ui->GLwidget->point_color_blue);

  settings->setValue("background_color_red",
                     ui->GLwidget->background_color_red);
  settings->setValue("background_color_green",
                     ui->GLwidget->background_color_green);
  settings->setValue("background_color_blue",
                     ui->GLwidget->background_color_blue);

  settings->setValue("scale", ui->GLwidget->scale);
  settings->setValue("move_x", ui->GLwidget->xMov);
  settings->setValue("move_y", ui->GLwidget->yMov);
  settings->setValue("move_z", ui->GLwidget->zMov);
  settings->setValue("rotation_x", ui->GLwidget->xRot);
  settings->setValue("rotation_y", ui->GLwidget->yRot);
  settings->setValue("rotation_z", ui->GLwidget->zRot);

  settings->setValue("model_name", ui->GLwidget->model_name);
}

void MainViewer::load_settings() {
  if (settings->value("are_settings").toInt()) {
    QByteArray modelNameBytes =
        settings->value("model_name").toString().toUtf8();
    qstrncpy(ui->GLwidget->model_name, modelNameBytes.constData(),
             sizeof(ui->GLwidget->model_name));
    ui->GLwidget->model_name[sizeof(ui->GLwidget->model_name) - 1] = '\0';
    ui->GLwidget->initializeGLmodel();

    ui->GLwidget->point_size = settings->value("point_size").toInt();
    ui->GLwidget->line_type = settings->value("line_type").toInt();
    ui->GLwidget->line_width = settings->value("line_width").toInt();
    ui->GLwidget->primitive_type = settings->value("primitive_type").toInt();
    ui->GLwidget->isPerspective = settings->value("projection_type").toInt();

    ui->GLwidget->line_color_red = settings->value("line_color_red").toInt();
    ui->GLwidget->line_color_green =
        settings->value("line_color_green").toInt();
    ui->GLwidget->line_color_blue = settings->value("line_color_blue").toInt();

    ui->GLwidget->point_color_red = settings->value("point_color_red").toInt();
    ui->GLwidget->point_color_green =
        settings->value("point_color_green").toInt();
    ui->GLwidget->point_color_blue =
        settings->value("point_color_blue").toInt();

    ui->GLwidget->background_color_red =
        settings->value("background_color_red").toInt();
    ui->GLwidget->background_color_green =
        settings->value("background_color_green").toInt();
    ui->GLwidget->background_color_blue =
        settings->value("background_color_blue").toInt();

    ui->GLwidget->scale = settings->value("scale").toInt();

    ui->GLwidget->xMov = settings->value("move_x").toInt();
    ui->GLwidget->yMov = settings->value("move_y").toInt();
    ui->GLwidget->zMov = settings->value("move_z").toInt();

    ui->GLwidget->xRot = settings->value("rotation_x").toInt();
    ui->GLwidget->yRot = settings->value("rotation_y").toInt();
    ui->GLwidget->zRot = settings->value("rotation_z").toInt();

    ui->GLwidget->update();
  }
}

void MainViewer::on_pushButton_clicked() {
  char* model_name = ui->GLwidget->model_name;  // Получаем указатель на массив
  strncpy(model_name, "../frontend/default_models/welcome_3d.obj\0",
          sizeof(ui->GLwidget->model_name) - 1);
  model_name[sizeof(ui->GLwidget->model_name) - 1] = '\0';
  on_reset_model_released();
  on_resetColor_clicked();
  ui->GLwidget->initializeGLmodel();
  ui->model_name_and_props->setText(
      "Model name: " + QFileInfo(model_name).fileName() + " with " +
      QString::number(ui->GLwidget->objData.vertexCount) + " vertices and " +
      QString::number(ui->GLwidget->objData.faceCount) + " faces, size: " +
      QString::number(QFileInfo(model_name).size() / 1000, 'f', 3) + " kb");
}

void MainViewer::mousePressEvent(QMouseEvent *event) {
    cur_pos = event->globalPos();
}

void MainViewer::mouseMoveEvent(QMouseEvent* event) {
    QPoint cursorPos = QCursor::pos();

    //Параметры разрешения экрана
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    int desktop_height = screenGeometry.height();
    int desktop_width = screenGeometry.width();
    // qDebug() << "Resolution: " << desktop_height << "x" << desktop_width;

    int norm_coef_x = desktop_width / 200; //slider value: min value 100 + max value 100 = 200
    int norm_coef_y = desktop_height / 200; //slider value: min value 100 + max value 100 = 200
    // int cur_y = event->localPos().y();

    int prev_x = cur_pos.x();
    int prev_y = cur_pos.y();

    // qDebug() << "prev_x: " << prev_x;

    // int gl_widget_width = ui->GLwidget->width();
    // int gl_widget_heighy = ui->GLwidget->height();

    if (event ->buttons() & Qt::LeftButton) {
        int diff_prev_and_cur_x = prev_x - event->globalX();
        int diff_prev_and_cur_y = prev_y - event->globalY();

        // qDebug() << "diff_x: " << diff_prev_and_cur_x;

        ui->GLwidget->xMov = -diff_prev_and_cur_x / norm_coef_x;
        ui->GLwidget->yMov = diff_prev_and_cur_y / norm_coef_y;

        update_sliders();

        ui->GLwidget->apply_transform();
        ui->GLwidget->update();
    } else if (event->buttons() & Qt::RightButton) {
        // xRot = -new_pos.y();
        // yRot = new_pos.x();
        // apply_transform();
        // update();
        ui->GLwidget->xRot = -cursorPos.x();
        ui->GLwidget->yRot = cursorPos.y();
        update_sliders();
        ui->GLwidget->apply_transform();
        ui->GLwidget->update();
    }
}

void MainViewer::wheelEvent(QWheelEvent *event) {
    QPoint numDegrees = event->angleDelta() / 120;
    ui->GLwidget->scale += numDegrees.y();
    update_sliders();
    ui->GLwidget->apply_transform();
    ui->GLwidget->update();
}

// void MainViewer::mouseMoveEvent(QMouseEvent *event) {
//     QPoint cursorPos = QCursor::pos();
//     // auto mousePos = this->mapFromGlobal(QCursor::globalPos());
//     int move_x = cursorPos.x();
//     int move_y = cursorPos.y();

//     // Отправляем сигнал valueChanged с новым значением слайдера
//    emit valueChanged(move_x);
//    emit valueChanged(move_y);
// }


void MainViewer::captureOpenGLScene() {



    QString filePath = QFileDialog::getSaveFileName(this, tr("Save Image"), "", tr("All Files (*)"));
    // Create an FBO
    QOpenGLFramebufferObject fbo(ui->GLwidget->width(), ui->GLwidget->height());

    // Bind the FBO for rendering
    fbo.bind();

    // Render the scene
    ui->GLwidget->paintGL(); // Assuming your paintGL() function renders the scene

    // Release the FBO
    fbo.release();

    // Read pixels from the FBO
    QImage image = fbo.toImage();

    if(ui->jpeg->isChecked()){
        filePath+=".jpeg";
    } else {
        filePath+=".bmp";
    }

    // qDebug() << filePath;
    // Save the image to a file
    image.save(filePath); // or "output.bmp"
}


void MainViewer::on_saveImage_clicked()
{
     captureOpenGLScene();
}

void MainViewer::saveGif()
{
    QImage image = ui->GLwidget->grabFrameBuffer();
    QSize image_size(640, 480);
    QImage scaled_image = image.scaled(image_size);

    gif_frame->addFrame(scaled_image);

    if (frames_counter == 50) {
        timer.stop();
        gif_frame->save(gif_name);
        frames_counter = 0;
        QMessageBox messageBoxGif;
        messageBoxGif.information(0, "", "Gif animation saved successfully");
        delete gif_frame;
        ui->save_gif_button->setText("");
        ui->save_gif_button->setEnabled(true);
    }
    frames_counter++;
    if (!ui->save_gif_button->isEnabled()) {
        ui->save_gif_button->setText(QString::number(frames_counter / 10) + "s");
    }
}

void MainViewer::on_save_gif_button_pressed()
{

}


void MainViewer::on_save_gif_button_clicked()
{
    // gif_name = "animat.gif";
    QDateTime current_date = QDateTime::currentDateTime();
    QString formattedTime = current_date.toString("yyyy-MM-dd hh.mm.ss");
    QString name_pattern = "Screen Cast " + formattedTime + ".gif";
    gif_name = QFileDialog::getSaveFileName(this, tr("Save a gif animation"),
    name_pattern, tr("gif (*.gif)"));


   if (gif_name != "") {
    gif_frame = new QGifImage;
    gif_frame->setDefaultDelay(10);
    timer.setInterval(100);
    timer.start();

    // qDebug() << gif_name;
   }
}

