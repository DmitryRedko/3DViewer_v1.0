#include <GL/glut.h>

#include <QApplication>

#include "mainviewer.h"

extern "C" {
#include "../parser/s21_parser.h"
}

#include <QDebug>

int main(int argc, char *argv[]) {

  glutInit(&argc, argv);
  QApplication a(argc, argv);
  //указание локали, т.к. русская убунту может не давать грузить нормально
  //моедль с вещественными числами из-за точки и запятой
  // "C" - модель для точки в вещественных числах в качетсве разделителя
  setlocale(LC_NUMERIC, "C");

  MainViewer w;
  w.show();

  return a.exec();
}
