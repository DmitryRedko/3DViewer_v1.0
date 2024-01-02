#ifndef MAINVIEWER_H
#define MAINVIEWER_H

#include <QMainWindow>

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
};
#endif // MAINVIEWER_H
