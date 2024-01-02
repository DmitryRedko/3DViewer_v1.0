/********************************************************************************
** Form generated from reading UI file 'mainviewer.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
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
    QFrame *frame;
    QGridLayout *gridLayout;
    QFrame *translate;
    QGridLayout *gridLayout_5;
    QLabel *translate_title;
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
    QFrame *open_file;
    QGridLayout *gridLayout_2;
    QLineEdit *pathLine;
    QPushButton *fileBtm;
    QPushButton *pathBtm;
    QFrame *zoom;
    QGridLayout *gridLayout_3;
    QLabel *rotate_title;
    QSlider *zoom_scale;
    QLabel *label_plus;
    QLabel *label_minus;
    QFrame *rotate;
    QGridLayout *gridLayout_4;
    QLabel *rotate_title_3;
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
    QFrame *frame_8;
    QGridLayout *gridLayout_6;
    QFrame *frame_2;
    QSpacerItem *horizontalSpacer;
    GLWidget *widget;

    void setupUi(QMainWindow *MainViewer)
    {
        if (MainViewer->objectName().isEmpty())
            MainViewer->setObjectName(QString::fromUtf8("MainViewer"));
        MainViewer->resize(1000, 600);
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
        translate_title = new QLabel(translate);
        translate_title->setObjectName(QString::fromUtf8("translate_title"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(translate_title->sizePolicy().hasHeightForWidth());
        translate_title->setSizePolicy(sizePolicy2);

        gridLayout_5->addWidget(translate_title, 0, 0, 1, 1);

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


        gridLayout->addWidget(translate, 3, 0, 1, 2);

        open_file = new QFrame(frame);
        open_file->setObjectName(QString::fromUtf8("open_file"));
        sizePolicy2.setHeightForWidth(open_file->sizePolicy().hasHeightForWidth());
        open_file->setSizePolicy(sizePolicy2);
        open_file->setStyleSheet(QString::fromUtf8("background-color: \"#737780\";"));
        open_file->setFrameShape(QFrame::StyledPanel);
        open_file->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(open_file);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pathLine = new QLineEdit(open_file);
        pathLine->setObjectName(QString::fromUtf8("pathLine"));
        pathLine->setStyleSheet(QString::fromUtf8("padding-left: 5px;\n"
"padding-right: 5px;\n"
"color: rgb(255, 255, 255);\n"
"width: 100px;"));
        pathLine->setReadOnly(true);

        gridLayout_2->addWidget(pathLine, 0, 0, 1, 1);

        fileBtm = new QPushButton(open_file);
        fileBtm->setObjectName(QString::fromUtf8("fileBtm"));
        fileBtm->setStyleSheet(QString::fromUtf8("background-color: \"#737780\";\n"
"border: 1px solid white;\n"
"width: 80px;\n"
"color: white;\n"
"border-radius: 5px;"));

        gridLayout_2->addWidget(fileBtm, 0, 1, 1, 1);

        pathBtm = new QPushButton(open_file);
        pathBtm->setObjectName(QString::fromUtf8("pathBtm"));
        pathBtm->setStyleSheet(QString::fromUtf8("background-color: \"#737780\";\n"
"border: 1px solid white;\n"
"color: white;\n"
"border-radius: 5px;"));

        gridLayout_2->addWidget(pathBtm, 1, 0, 1, 2);


        gridLayout->addWidget(open_file, 0, 0, 1, 2);

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
        rotate_title = new QLabel(zoom);
        rotate_title->setObjectName(QString::fromUtf8("rotate_title"));
        sizePolicy2.setHeightForWidth(rotate_title->sizePolicy().hasHeightForWidth());
        rotate_title->setSizePolicy(sizePolicy2);

        gridLayout_3->addWidget(rotate_title, 0, 0, 1, 2);

        zoom_scale = new QSlider(zoom);
        zoom_scale->setObjectName(QString::fromUtf8("zoom_scale"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(zoom_scale->sizePolicy().hasHeightForWidth());
        zoom_scale->setSizePolicy(sizePolicy3);
        zoom_scale->setMinimum(1);
        zoom_scale->setMaximum(200);
        zoom_scale->setValue(50);
        zoom_scale->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(zoom_scale, 1, 1, 1, 1);

        label_plus = new QLabel(zoom);
        label_plus->setObjectName(QString::fromUtf8("label_plus"));

        gridLayout_3->addWidget(label_plus, 1, 2, 1, 1);

        label_minus = new QLabel(zoom);
        label_minus->setObjectName(QString::fromUtf8("label_minus"));

        gridLayout_3->addWidget(label_minus, 1, 0, 1, 1);


        gridLayout->addWidget(zoom, 1, 0, 1, 2);

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
        rotate_title_3 = new QLabel(rotate);
        rotate_title_3->setObjectName(QString::fromUtf8("rotate_title_3"));
        sizePolicy2.setHeightForWidth(rotate_title_3->sizePolicy().hasHeightForWidth());
        rotate_title_3->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(rotate_title_3, 0, 0, 1, 1);

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
        rotate_y->setSingleStep(0);
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
        rotate_z->setSingleStep(0);
        rotate_z->setOrientation(Qt::Horizontal);

        line_9->addWidget(rotate_z);


        verticalLayout_2->addLayout(line_9);


        gridLayout_4->addLayout(verticalLayout_2, 1, 0, 1, 1);


        gridLayout->addWidget(rotate, 2, 0, 1, 2);


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
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy4);
        frame_2->setStyleSheet(QString::fromUtf8("border-color: rgb(94, 92, 100);\n"
"border-color: rgb(61, 56, 70);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);

        gridLayout_6->addWidget(frame_2, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer, 0, 1, 1, 1);


        gridLayout_7->addWidget(frame_8, 2, 0, 1, 1);

        widget = new GLWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8("border-radius: 10px; \n"
"background-color: \"#252628\";\n"
"border: 1px solid \"#252628\";\n"
"padding: 5px;"));

        gridLayout_7->addWidget(widget, 1, 0, 1, 1);

        MainViewer->setCentralWidget(centralwidget);
        frame->raise();
        frame_8->raise();
        header->raise();
        widget->raise();

        retranslateUi(MainViewer);

        QMetaObject::connectSlotsByName(MainViewer);
    } // setupUi

    void retranslateUi(QMainWindow *MainViewer)
    {
        MainViewer->setWindowTitle(QCoreApplication::translate("MainViewer", "MainViewer", nullptr));
        header->setText(QCoreApplication::translate("MainViewer", "<html><head/><body><p><span style=\" font-style:italic; color:#ffffff;\">\360\237\220\251 3D-Viewer</span></p></body></html>", nullptr));
        translate_title->setText(QCoreApplication::translate("MainViewer", "Move", nullptr));
        label_16->setText(QCoreApplication::translate("MainViewer", "X", nullptr));
        label_17->setText(QCoreApplication::translate("MainViewer", "Y", nullptr));
        label_18->setText(QCoreApplication::translate("MainViewer", "Z", nullptr));
        fileBtm->setText(QCoreApplication::translate("MainViewer", "file", nullptr));
        pathBtm->setText(QCoreApplication::translate("MainViewer", "OPEN", nullptr));
        rotate_title->setText(QCoreApplication::translate("MainViewer", "Zoom", nullptr));
        label_plus->setText(QCoreApplication::translate("MainViewer", "+", nullptr));
        label_minus->setText(QCoreApplication::translate("MainViewer", "-", nullptr));
        rotate_title_3->setText(QCoreApplication::translate("MainViewer", "Rotation", nullptr));
        label_7->setText(QCoreApplication::translate("MainViewer", "X", nullptr));
        label_8->setText(QCoreApplication::translate("MainViewer", "Y", nullptr));
        label_9->setText(QCoreApplication::translate("MainViewer", "Z", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainViewer: public Ui_MainViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINVIEWER_H
