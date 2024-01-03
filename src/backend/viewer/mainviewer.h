#ifndef MAINVIEWER_H
#define MAINVIEWER_H

#include <QMainWindow>
#include "glwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainViewer; }
QT_END_NAMESPACE

class MainViewer : public QMainWindow
{
    Q_OBJECT

public:
    MainViewer(QWidget *parent = nullptr);
    ~MainViewer();

private:
    Ui::MainViewer *ui;
    GLWidget *myGLW;

private slots:
    void updateLabelText(int value);
    void on_rotate_x_valueChanged(int value);
};
#endif // MAINVIEWER_H
