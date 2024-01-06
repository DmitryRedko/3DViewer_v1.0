/********************************************************************************
** Form generated from reading UI file 'mainviewer.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINVIEWER_H
#define UI_MAINVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "glwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainViewer
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_7;
    QLabel *header;
    GLWidget *GLwidget;
    QFrame *frame;
    QGridLayout *gridLayout;
    QFrame *open_file;
    QGridLayout *gridLayout_2;
    QPushButton *fileBtm;
    QLineEdit *pathLine;
    QPushButton *openBtm;
    QPushButton *reset_model;
    QFrame *zoom_2;
    QGridLayout *gridLayout_10;
    QLabel *label_minus_4;
    QSlider *point_size_scale;
    QLabel *label_plus_4;
    QLabel *point_size_title;
    QFrame *rotate;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *line_7;
    QLabel *label_7;
    QSlider *rotate_x;
    QHBoxLayout *line_8;
    QLabel *label_8;
    QSlider *rotate_y;
    QHBoxLayout *line_9;
    QLabel *label_9;
    QSlider *rotate_z;
    QLabel *rotate_title_3;
    QFrame *zoom;
    QGridLayout *gridLayout_3;
    QLabel *label_minus;
    QLabel *label_plus;
    QLabel *rotate_title;
    QSlider *zoom_scale;
    QFrame *translate;
    QGridLayout *gridLayout_5;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *line_16;
    QLabel *label_16;
    QSlider *move_x;
    QHBoxLayout *line_17;
    QLabel *label_17;
    QSlider *move_y;
    QHBoxLayout *line_18;
    QLabel *label_18;
    QSlider *move_z;
    QLabel *translate_title;
    QFrame *zoom_3;
    QGridLayout *gridLayout_11;
    QLabel *label_minus_5;
    QSlider *line_width_scale;
    QLabel *label_plus_5;
    QLabel *line_width_title;
    QFrame *frame_8;
    QGridLayout *gridLayout_6;
    QFrame *frame_2;
    QSpacerItem *horizontalSpacer;

    void setupUi(QMainWindow *MainViewer)
    {
        if (MainViewer->objectName().isEmpty())
            MainViewer->setObjectName(QString::fromUtf8("MainViewer"));
        MainViewer->resize(1051, 665);
        MainViewer->setStyleSheet(QString::fromUtf8("background-color: \"#737780\";"));
        centralwidget = new QWidget(MainViewer);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_7 = new QGridLayout(centralwidget);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        header = new QLabel(centralwidget);
        header->setObjectName(QString::fromUtf8("header"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(header->sizePolicy().hasHeightForWidth());
        header->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(24);
        font.setBold(true);
        header->setFont(font);
        header->setStyleSheet(QString::fromUtf8("border-radius: 10px; \n"
"\n"
"border: 5px;\n"
"padding: 5px;\n"
""));
        header->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_7->addWidget(header, 0, 0, 1, 1);

        GLwidget = new GLWidget(centralwidget);
        GLwidget->setObjectName(QString::fromUtf8("GLwidget"));
        GLwidget->setStyleSheet(QString::fromUtf8("border-radius: 10px; \n"
"background-color: \"#252628\";\n"
"border: 1px solid \"#252628\";\n"
"padding: 5px;"));

        gridLayout_7->addWidget(GLwidget, 1, 0, 1, 1);

        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setStyleSheet(QString::fromUtf8("background-color: \"#515259\";"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        open_file = new QFrame(frame);
        open_file->setObjectName(QString::fromUtf8("open_file"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(open_file->sizePolicy().hasHeightForWidth());
        open_file->setSizePolicy(sizePolicy2);
        open_file->setStyleSheet(QString::fromUtf8("background-color: \"#737780\";"));
        open_file->setFrameShape(QFrame::StyledPanel);
        open_file->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(open_file);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        fileBtm = new QPushButton(open_file);
        fileBtm->setObjectName(QString::fromUtf8("fileBtm"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(fileBtm->sizePolicy().hasHeightForWidth());
        fileBtm->setSizePolicy(sizePolicy3);
        fileBtm->setMinimumSize(QSize(40, 0));
        fileBtm->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: \"#737780\";\n"
"    border: 1px solid white;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: \"#A0A6AA\"; \n"
"    color: black; \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: \"#595E62\";\n"
"    border: 1px solid black;  \n"
"}\n"
""));

        gridLayout_2->addWidget(fileBtm, 0, 1, 1, 1);

        pathLine = new QLineEdit(open_file);
        pathLine->setObjectName(QString::fromUtf8("pathLine"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(pathLine->sizePolicy().hasHeightForWidth());
        pathLine->setSizePolicy(sizePolicy4);
        pathLine->setMinimumSize(QSize(150, 0));
        pathLine->setStyleSheet(QString::fromUtf8("padding-left: 5px;\n"
"padding-right: 5px;\n"
"color: rgb(255, 255, 255);\n"
"width: 100px;"));
        pathLine->setReadOnly(true);

        gridLayout_2->addWidget(pathLine, 0, 0, 1, 1);

        openBtm = new QPushButton(open_file);
        openBtm->setObjectName(QString::fromUtf8("openBtm"));
        openBtm->setCursor(QCursor(Qt::PointingHandCursor));
        openBtm->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: \"#737780\";\n"
"    border: 1px solid white;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: \"#A0A6AA\"; \n"
"    color: black; \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: \"#595E62\";\n"
"    border: 1px solid black;  \n"
"}\n"
""));

        gridLayout_2->addWidget(openBtm, 1, 0, 1, 2);

        reset_model = new QPushButton(open_file);
        reset_model->setObjectName(QString::fromUtf8("reset_model"));
        reset_model->setCursor(QCursor(Qt::PointingHandCursor));
        reset_model->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: \"#737780\";\n"
"    border: 1px solid white;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: \"#A0A6AA\"; \n"
"    color: black; \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: \"#595E62\";\n"
"    border: 1px solid black;  \n"
"}\n"
""));

        gridLayout_2->addWidget(reset_model, 2, 0, 1, 2);


        gridLayout->addWidget(open_file, 0, 0, 1, 2);

        zoom_2 = new QFrame(frame);
        zoom_2->setObjectName(QString::fromUtf8("zoom_2"));
        zoom_2->setEnabled(true);
        sizePolicy.setHeightForWidth(zoom_2->sizePolicy().hasHeightForWidth());
        zoom_2->setSizePolicy(sizePolicy);
        zoom_2->setStyleSheet(QString::fromUtf8("QFrame {\n"
"color: white;\n"
"margin-top: 5px;\n"
"border: 1px solid white;\n"
"border-radius: 10px;\n"
"}\n"
"\n"
"QLabel {\n"
"margin-top: 0;\n"
"border: none;\n"
"}\n"
"\n"
"QPushButton {\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"padding-top: 3px;\n"
"padding-right: 3px;\n"
"}"));
        zoom_2->setFrameShape(QFrame::StyledPanel);
        zoom_2->setFrameShadow(QFrame::Raised);
        gridLayout_10 = new QGridLayout(zoom_2);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        label_minus_4 = new QLabel(zoom_2);
        label_minus_4->setObjectName(QString::fromUtf8("label_minus_4"));

        gridLayout_10->addWidget(label_minus_4, 1, 0, 1, 1);

        point_size_scale = new QSlider(zoom_2);
        point_size_scale->setObjectName(QString::fromUtf8("point_size_scale"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(point_size_scale->sizePolicy().hasHeightForWidth());
        point_size_scale->setSizePolicy(sizePolicy5);
        point_size_scale->setMinimum(0);
        point_size_scale->setMaximum(25);
        point_size_scale->setSingleStep(1);
        point_size_scale->setPageStep(1);
        point_size_scale->setValue(5);
        point_size_scale->setOrientation(Qt::Horizontal);

        gridLayout_10->addWidget(point_size_scale, 1, 1, 1, 1);

        label_plus_4 = new QLabel(zoom_2);
        label_plus_4->setObjectName(QString::fromUtf8("label_plus_4"));

        gridLayout_10->addWidget(label_plus_4, 1, 2, 1, 1);

        point_size_title = new QLabel(zoom_2);
        point_size_title->setObjectName(QString::fromUtf8("point_size_title"));
        sizePolicy2.setHeightForWidth(point_size_title->sizePolicy().hasHeightForWidth());
        point_size_title->setSizePolicy(sizePolicy2);

        gridLayout_10->addWidget(point_size_title, 0, 0, 1, 2);


        gridLayout->addWidget(zoom_2, 1, 0, 1, 2);

        rotate = new QFrame(frame);
        rotate->setObjectName(QString::fromUtf8("rotate"));
        rotate->setStyleSheet(QString::fromUtf8("QFrame {\n"
"color: white;\n"
"margin-top: 5px;\n"
"border: 1px solid white;\n"
"border-radius: 10px;\n"
"}\n"
"\n"
"QLabel {\n"
"margin-top: 0;\n"
"border: none;\n"
"}"));
        rotate->setFrameShape(QFrame::StyledPanel);
        rotate->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(rotate);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, 5, -1, -1);
        line_7 = new QHBoxLayout();
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setContentsMargins(0, -1, -1, -1);
        label_7 = new QLabel(rotate);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setStyleSheet(QString::fromUtf8("	color: rgba(255, 255, 255, 102);"));

        line_7->addWidget(label_7);

        rotate_x = new QSlider(rotate);
        rotate_x->setObjectName(QString::fromUtf8("rotate_x"));
        rotate_x->setMinimum(-360);
        rotate_x->setMaximum(360);
        rotate_x->setSingleStep(1);
        rotate_x->setOrientation(Qt::Horizontal);

        line_7->addWidget(rotate_x);


        verticalLayout_2->addLayout(line_7);

        line_8 = new QHBoxLayout();
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setContentsMargins(0, -1, -1, -1);
        label_8 = new QLabel(rotate);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setStyleSheet(QString::fromUtf8("	color: rgba(255, 255, 255, 102);"));

        line_8->addWidget(label_8);

        rotate_y = new QSlider(rotate);
        rotate_y->setObjectName(QString::fromUtf8("rotate_y"));
        rotate_y->setMinimum(-360);
        rotate_y->setMaximum(360);
        rotate_y->setSingleStep(1);
        rotate_y->setOrientation(Qt::Horizontal);

        line_8->addWidget(rotate_y);


        verticalLayout_2->addLayout(line_8);

        line_9 = new QHBoxLayout();
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setContentsMargins(0, -1, -1, -1);
        label_9 = new QLabel(rotate);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setStyleSheet(QString::fromUtf8("	color: rgba(255, 255, 255, 102);"));

        line_9->addWidget(label_9);

        rotate_z = new QSlider(rotate);
        rotate_z->setObjectName(QString::fromUtf8("rotate_z"));
        rotate_z->setMinimum(-360);
        rotate_z->setMaximum(360);
        rotate_z->setSingleStep(1);
        rotate_z->setOrientation(Qt::Horizontal);

        line_9->addWidget(rotate_z);


        verticalLayout_2->addLayout(line_9);


        gridLayout_4->addLayout(verticalLayout_2, 1, 0, 1, 1);

        rotate_title_3 = new QLabel(rotate);
        rotate_title_3->setObjectName(QString::fromUtf8("rotate_title_3"));
        sizePolicy2.setHeightForWidth(rotate_title_3->sizePolicy().hasHeightForWidth());
        rotate_title_3->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(rotate_title_3, 0, 0, 1, 1);


        gridLayout->addWidget(rotate, 4, 0, 1, 2);

        zoom = new QFrame(frame);
        zoom->setObjectName(QString::fromUtf8("zoom"));
        zoom->setEnabled(true);
        sizePolicy.setHeightForWidth(zoom->sizePolicy().hasHeightForWidth());
        zoom->setSizePolicy(sizePolicy);
        zoom->setStyleSheet(QString::fromUtf8("QFrame {\n"
"color: white;\n"
"margin-top: 5px;\n"
"border: 1px solid white;\n"
"border-radius: 10px;\n"
"}\n"
"\n"
"QLabel {\n"
"margin-top: 0;\n"
"border: none;\n"
"}\n"
"\n"
"QPushButton {\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"padding-top: 3px;\n"
"padding-right: 3px;\n"
"}"));
        zoom->setFrameShape(QFrame::StyledPanel);
        zoom->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(zoom);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_minus = new QLabel(zoom);
        label_minus->setObjectName(QString::fromUtf8("label_minus"));

        gridLayout_3->addWidget(label_minus, 1, 0, 1, 1);

        label_plus = new QLabel(zoom);
        label_plus->setObjectName(QString::fromUtf8("label_plus"));

        gridLayout_3->addWidget(label_plus, 1, 2, 1, 1);

        rotate_title = new QLabel(zoom);
        rotate_title->setObjectName(QString::fromUtf8("rotate_title"));
        sizePolicy2.setHeightForWidth(rotate_title->sizePolicy().hasHeightForWidth());
        rotate_title->setSizePolicy(sizePolicy2);

        gridLayout_3->addWidget(rotate_title, 0, 0, 1, 2);

        zoom_scale = new QSlider(zoom);
        zoom_scale->setObjectName(QString::fromUtf8("zoom_scale"));
        sizePolicy5.setHeightForWidth(zoom_scale->sizePolicy().hasHeightForWidth());
        zoom_scale->setSizePolicy(sizePolicy5);
        zoom_scale->setMinimum(1);
        zoom_scale->setMaximum(300);
        zoom_scale->setSingleStep(1);
        zoom_scale->setPageStep(1);
        zoom_scale->setValue(100);
        zoom_scale->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(zoom_scale, 1, 1, 1, 1);


        gridLayout->addWidget(zoom, 3, 0, 1, 2);

        translate = new QFrame(frame);
        translate->setObjectName(QString::fromUtf8("translate"));
        translate->setStyleSheet(QString::fromUtf8("QFrame {\n"
"color: white;\n"
"margin-top: 5px;\n"
"border: 1px solid white;\n"
"border-radius: 10px;\n"
"}\n"
"\n"
"QLabel {\n"
"margin-top: 0;\n"
"border: none;\n"
"}"));
        translate->setFrameShape(QFrame::StyledPanel);
        translate->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(translate);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 5, -1, -1);
        line_16 = new QHBoxLayout();
        line_16->setObjectName(QString::fromUtf8("line_16"));
        line_16->setContentsMargins(0, -1, -1, -1);
        label_16 = new QLabel(translate);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setStyleSheet(QString::fromUtf8("	color: rgba(255, 255, 255, 102);"));

        line_16->addWidget(label_16);

        move_x = new QSlider(translate);
        move_x->setObjectName(QString::fromUtf8("move_x"));
        move_x->setMinimum(-100);
        move_x->setMaximum(100);
        move_x->setValue(0);
        move_x->setOrientation(Qt::Horizontal);

        line_16->addWidget(move_x);


        verticalLayout->addLayout(line_16);

        line_17 = new QHBoxLayout();
        line_17->setObjectName(QString::fromUtf8("line_17"));
        line_17->setContentsMargins(0, -1, -1, -1);
        label_17 = new QLabel(translate);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setStyleSheet(QString::fromUtf8("	color: rgba(255, 255, 255, 102);"));

        line_17->addWidget(label_17);

        move_y = new QSlider(translate);
        move_y->setObjectName(QString::fromUtf8("move_y"));
        move_y->setMinimum(-100);
        move_y->setMaximum(100);
        move_y->setValue(0);
        move_y->setOrientation(Qt::Horizontal);

        line_17->addWidget(move_y);


        verticalLayout->addLayout(line_17);

        line_18 = new QHBoxLayout();
        line_18->setObjectName(QString::fromUtf8("line_18"));
        line_18->setContentsMargins(0, -1, -1, -1);
        label_18 = new QLabel(translate);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setStyleSheet(QString::fromUtf8("	color: rgba(255, 255, 255, 102);"));

        line_18->addWidget(label_18);

        move_z = new QSlider(translate);
        move_z->setObjectName(QString::fromUtf8("move_z"));
        move_z->setMinimum(-100);
        move_z->setMaximum(100);
        move_z->setValue(0);
        move_z->setOrientation(Qt::Horizontal);

        line_18->addWidget(move_z);


        verticalLayout->addLayout(line_18);


        gridLayout_5->addLayout(verticalLayout, 1, 0, 1, 1);

        translate_title = new QLabel(translate);
        translate_title->setObjectName(QString::fromUtf8("translate_title"));
        sizePolicy2.setHeightForWidth(translate_title->sizePolicy().hasHeightForWidth());
        translate_title->setSizePolicy(sizePolicy2);

        gridLayout_5->addWidget(translate_title, 0, 0, 1, 1);


        gridLayout->addWidget(translate, 6, 0, 1, 2);

        zoom_3 = new QFrame(frame);
        zoom_3->setObjectName(QString::fromUtf8("zoom_3"));
        zoom_3->setEnabled(true);
        sizePolicy.setHeightForWidth(zoom_3->sizePolicy().hasHeightForWidth());
        zoom_3->setSizePolicy(sizePolicy);
        zoom_3->setStyleSheet(QString::fromUtf8("QFrame {\n"
"color: white;\n"
"margin-top: 5px;\n"
"border: 1px solid white;\n"
"border-radius: 10px;\n"
"}\n"
"\n"
"QLabel {\n"
"margin-top: 0;\n"
"border: none;\n"
"}\n"
"\n"
"QPushButton {\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"padding-top: 3px;\n"
"padding-right: 3px;\n"
"}"));
        zoom_3->setFrameShape(QFrame::StyledPanel);
        zoom_3->setFrameShadow(QFrame::Raised);
        gridLayout_11 = new QGridLayout(zoom_3);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        label_minus_5 = new QLabel(zoom_3);
        label_minus_5->setObjectName(QString::fromUtf8("label_minus_5"));

        gridLayout_11->addWidget(label_minus_5, 1, 0, 1, 1);

        line_width_scale = new QSlider(zoom_3);
        line_width_scale->setObjectName(QString::fromUtf8("line_width_scale"));
        sizePolicy5.setHeightForWidth(line_width_scale->sizePolicy().hasHeightForWidth());
        line_width_scale->setSizePolicy(sizePolicy5);
        line_width_scale->setMinimum(1);
        line_width_scale->setMaximum(10);
        line_width_scale->setSingleStep(1);
        line_width_scale->setPageStep(1);
        line_width_scale->setValue(1);
        line_width_scale->setOrientation(Qt::Horizontal);

        gridLayout_11->addWidget(line_width_scale, 1, 1, 1, 1);

        label_plus_5 = new QLabel(zoom_3);
        label_plus_5->setObjectName(QString::fromUtf8("label_plus_5"));

        gridLayout_11->addWidget(label_plus_5, 1, 2, 1, 1);

        line_width_title = new QLabel(zoom_3);
        line_width_title->setObjectName(QString::fromUtf8("line_width_title"));
        sizePolicy2.setHeightForWidth(line_width_title->sizePolicy().hasHeightForWidth());
        line_width_title->setSizePolicy(sizePolicy2);

        gridLayout_11->addWidget(line_width_title, 0, 0, 1, 2);


        gridLayout->addWidget(zoom_3, 2, 0, 1, 1);


        gridLayout_7->addWidget(frame, 0, 1, 3, 1);

        frame_8 = new QFrame(centralwidget);
        frame_8->setObjectName(QString::fromUtf8("frame_8"));
        sizePolicy2.setHeightForWidth(frame_8->sizePolicy().hasHeightForWidth());
        frame_8->setSizePolicy(sizePolicy2);
        frame_8->setStyleSheet(QString::fromUtf8("background-color: \"#515259\";"));
        frame_8->setFrameShape(QFrame::StyledPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        gridLayout_6 = new QGridLayout(frame_8);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        frame_2 = new QFrame(frame_8);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy6);
        frame_2->setStyleSheet(QString::fromUtf8("border-color: rgb(94, 92, 100);\n"
"border-color: rgb(61, 56, 70);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);

        gridLayout_6->addWidget(frame_2, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer, 0, 1, 1, 1);


        gridLayout_7->addWidget(frame_8, 2, 0, 1, 1);

        MainViewer->setCentralWidget(centralwidget);
        frame->raise();
        frame_8->raise();
        header->raise();
        GLwidget->raise();

        retranslateUi(MainViewer);

        QMetaObject::connectSlotsByName(MainViewer);
    } // setupUi

    void retranslateUi(QMainWindow *MainViewer)
    {
        MainViewer->setWindowTitle(QCoreApplication::translate("MainViewer", "MainViewer", nullptr));
        header->setText(QCoreApplication::translate("MainViewer", "<html><head/><body><p><span style=\" font-style:italic; color:#ffffff;\">\360\237\220\251 3D-Viewer</span></p></body></html>", nullptr));
        fileBtm->setText(QCoreApplication::translate("MainViewer", "file", nullptr));
        openBtm->setText(QCoreApplication::translate("MainViewer", "OPEN", nullptr));
        reset_model->setText(QCoreApplication::translate("MainViewer", "RESET MODEL", nullptr));
        label_minus_4->setText(QCoreApplication::translate("MainViewer", "-", nullptr));
        label_plus_4->setText(QCoreApplication::translate("MainViewer", "+", nullptr));
        point_size_title->setText(QCoreApplication::translate("MainViewer", "Point size", nullptr));
        label_7->setText(QCoreApplication::translate("MainViewer", "X", nullptr));
        label_8->setText(QCoreApplication::translate("MainViewer", "Y", nullptr));
        label_9->setText(QCoreApplication::translate("MainViewer", "Z", nullptr));
        rotate_title_3->setText(QCoreApplication::translate("MainViewer", "Rotation", nullptr));
        label_minus->setText(QCoreApplication::translate("MainViewer", "-", nullptr));
        label_plus->setText(QCoreApplication::translate("MainViewer", "+", nullptr));
        rotate_title->setText(QCoreApplication::translate("MainViewer", "Zoom", nullptr));
        label_16->setText(QCoreApplication::translate("MainViewer", "X", nullptr));
        label_17->setText(QCoreApplication::translate("MainViewer", "Y", nullptr));
        label_18->setText(QCoreApplication::translate("MainViewer", "Z", nullptr));
        translate_title->setText(QCoreApplication::translate("MainViewer", "Move", nullptr));
        label_minus_5->setText(QCoreApplication::translate("MainViewer", "-", nullptr));
        label_plus_5->setText(QCoreApplication::translate("MainViewer", "+", nullptr));
        line_width_title->setText(QCoreApplication::translate("MainViewer", "Line width", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainViewer: public Ui_MainViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINVIEWER_H
