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
    QFrame *frame;
    QGridLayout *gridLayout;
    QFrame *translate_3;
    QGridLayout *gridLayout_5;
    QLabel *translate_title_6;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *line_16;
    QLabel *label_16;
    QSlider *translate_x_val_3;
    QHBoxLayout *line_17;
    QLabel *label_17;
    QSlider *translate_y_val_3;
    QHBoxLayout *line_18;
    QLabel *label_18;
    QSlider *translate_z_val_3;
    QFrame *open_file_layer_3;
    QGridLayout *gridLayout_2;
    QLineEdit *pathObj_3;
    QPushButton *openObjBtn_3;
    QPushButton *renderBtn_3;
    QFrame *scale_3;
    QGridLayout *gridLayout_3;
    QLabel *rotate_title_6;
    QSlider *scale_val_3;
    QLabel *label_2;
    QLabel *label;
    QFrame *rotate_3;
    QGridLayout *gridLayout_4;
    QLabel *rotate_title_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *line_7;
    QLabel *label_7;
    QSlider *rotate_x_val_3;
    QHBoxLayout *line_8;
    QLabel *label_8;
    QSlider *rotate_y_val_3;
    QHBoxLayout *line_9;
    QLabel *label_9;
    QSlider *rotate_z_val_3;
    GLWidget *widget;
    QFrame *frame_8;
    QGridLayout *gridLayout_6;
    QFrame *frame_9;
    QSpacerItem *horizontalSpacer;
    QLabel *header;

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
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setStyleSheet(QString::fromUtf8("background-color: \"#515259\";"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        translate_3 = new QFrame(frame);
        translate_3->setObjectName(QString::fromUtf8("translate_3"));
        translate_3->setStyleSheet(QString::fromUtf8("QFrame {\n"
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
        translate_3->setFrameShape(QFrame::StyledPanel);
        translate_3->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(translate_3);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        translate_title_6 = new QLabel(translate_3);
        translate_title_6->setObjectName(QString::fromUtf8("translate_title_6"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(translate_title_6->sizePolicy().hasHeightForWidth());
        translate_title_6->setSizePolicy(sizePolicy1);

        gridLayout_5->addWidget(translate_title_6, 0, 0, 1, 1);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(-1, 5, -1, -1);
        line_16 = new QHBoxLayout();
        line_16->setObjectName(QString::fromUtf8("line_16"));
        line_16->setContentsMargins(0, -1, -1, -1);
        label_16 = new QLabel(translate_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setStyleSheet(QString::fromUtf8("	color: rgba(255, 255, 255, 102);"));

        line_16->addWidget(label_16);

        translate_x_val_3 = new QSlider(translate_3);
        translate_x_val_3->setObjectName(QString::fromUtf8("translate_x_val_3"));
        translate_x_val_3->setMinimum(-100);
        translate_x_val_3->setMaximum(100);
        translate_x_val_3->setValue(0);
        translate_x_val_3->setOrientation(Qt::Horizontal);

        line_16->addWidget(translate_x_val_3);


        verticalLayout_6->addLayout(line_16);

        line_17 = new QHBoxLayout();
        line_17->setObjectName(QString::fromUtf8("line_17"));
        line_17->setContentsMargins(0, -1, -1, -1);
        label_17 = new QLabel(translate_3);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setStyleSheet(QString::fromUtf8("	color: rgba(255, 255, 255, 102);"));

        line_17->addWidget(label_17);

        translate_y_val_3 = new QSlider(translate_3);
        translate_y_val_3->setObjectName(QString::fromUtf8("translate_y_val_3"));
        translate_y_val_3->setMinimum(-100);
        translate_y_val_3->setMaximum(100);
        translate_y_val_3->setValue(0);
        translate_y_val_3->setOrientation(Qt::Horizontal);

        line_17->addWidget(translate_y_val_3);


        verticalLayout_6->addLayout(line_17);

        line_18 = new QHBoxLayout();
        line_18->setObjectName(QString::fromUtf8("line_18"));
        line_18->setContentsMargins(0, -1, -1, -1);
        label_18 = new QLabel(translate_3);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setStyleSheet(QString::fromUtf8("	color: rgba(255, 255, 255, 102);"));

        line_18->addWidget(label_18);

        translate_z_val_3 = new QSlider(translate_3);
        translate_z_val_3->setObjectName(QString::fromUtf8("translate_z_val_3"));
        translate_z_val_3->setMinimum(-100);
        translate_z_val_3->setMaximum(100);
        translate_z_val_3->setValue(0);
        translate_z_val_3->setOrientation(Qt::Horizontal);

        line_18->addWidget(translate_z_val_3);


        verticalLayout_6->addLayout(line_18);


        gridLayout_5->addLayout(verticalLayout_6, 1, 0, 1, 1);


        gridLayout->addWidget(translate_3, 3, 0, 1, 2);

        open_file_layer_3 = new QFrame(frame);
        open_file_layer_3->setObjectName(QString::fromUtf8("open_file_layer_3"));
        sizePolicy1.setHeightForWidth(open_file_layer_3->sizePolicy().hasHeightForWidth());
        open_file_layer_3->setSizePolicy(sizePolicy1);
        open_file_layer_3->setStyleSheet(QString::fromUtf8("background-color: \"#737780\";"));
        open_file_layer_3->setFrameShape(QFrame::StyledPanel);
        open_file_layer_3->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(open_file_layer_3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pathObj_3 = new QLineEdit(open_file_layer_3);
        pathObj_3->setObjectName(QString::fromUtf8("pathObj_3"));
        pathObj_3->setStyleSheet(QString::fromUtf8("padding-left: 5px;\n"
"padding-right: 5px;\n"
"color: rgb(255, 255, 255);\n"
"width: 100px;"));
        pathObj_3->setReadOnly(true);

        gridLayout_2->addWidget(pathObj_3, 0, 0, 1, 1);

        openObjBtn_3 = new QPushButton(open_file_layer_3);
        openObjBtn_3->setObjectName(QString::fromUtf8("openObjBtn_3"));
        openObjBtn_3->setStyleSheet(QString::fromUtf8("background-color: \"#737780\";\n"
"border: 1px solid white;\n"
"width: 80px;\n"
"color: white;\n"
"border-radius: 5px;"));

        gridLayout_2->addWidget(openObjBtn_3, 0, 1, 1, 1);

        renderBtn_3 = new QPushButton(open_file_layer_3);
        renderBtn_3->setObjectName(QString::fromUtf8("renderBtn_3"));
        renderBtn_3->setStyleSheet(QString::fromUtf8("background-color: \"#737780\";\n"
"border: 1px solid white;\n"
"color: white;\n"
"border-radius: 5px;"));

        gridLayout_2->addWidget(renderBtn_3, 1, 0, 1, 2);


        gridLayout->addWidget(open_file_layer_3, 0, 0, 1, 2);

        scale_3 = new QFrame(frame);
        scale_3->setObjectName(QString::fromUtf8("scale_3"));
        scale_3->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(scale_3->sizePolicy().hasHeightForWidth());
        scale_3->setSizePolicy(sizePolicy2);
        scale_3->setStyleSheet(QString::fromUtf8("QFrame {\n"
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
        scale_3->setFrameShape(QFrame::StyledPanel);
        scale_3->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(scale_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        rotate_title_6 = new QLabel(scale_3);
        rotate_title_6->setObjectName(QString::fromUtf8("rotate_title_6"));
        sizePolicy1.setHeightForWidth(rotate_title_6->sizePolicy().hasHeightForWidth());
        rotate_title_6->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(rotate_title_6, 0, 0, 1, 2);

        scale_val_3 = new QSlider(scale_3);
        scale_val_3->setObjectName(QString::fromUtf8("scale_val_3"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(scale_val_3->sizePolicy().hasHeightForWidth());
        scale_val_3->setSizePolicy(sizePolicy3);
        scale_val_3->setMinimum(1);
        scale_val_3->setMaximum(200);
        scale_val_3->setValue(50);
        scale_val_3->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(scale_val_3, 1, 1, 1, 1);

        label_2 = new QLabel(scale_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_3->addWidget(label_2, 1, 2, 1, 1);

        label = new QLabel(scale_3);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_3->addWidget(label, 1, 0, 1, 1);


        gridLayout->addWidget(scale_3, 1, 0, 1, 2);

        rotate_3 = new QFrame(frame);
        rotate_3->setObjectName(QString::fromUtf8("rotate_3"));
        rotate_3->setStyleSheet(QString::fromUtf8("QFrame {\n"
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
        rotate_3->setFrameShape(QFrame::StyledPanel);
        rotate_3->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(rotate_3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        rotate_title_3 = new QLabel(rotate_3);
        rotate_title_3->setObjectName(QString::fromUtf8("rotate_title_3"));
        sizePolicy1.setHeightForWidth(rotate_title_3->sizePolicy().hasHeightForWidth());
        rotate_title_3->setSizePolicy(sizePolicy1);

        gridLayout_4->addWidget(rotate_title_3, 0, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, 5, -1, -1);
        line_7 = new QHBoxLayout();
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setContentsMargins(0, -1, -1, -1);
        label_7 = new QLabel(rotate_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setStyleSheet(QString::fromUtf8("	color: rgba(255, 255, 255, 102);"));

        line_7->addWidget(label_7);

        rotate_x_val_3 = new QSlider(rotate_3);
        rotate_x_val_3->setObjectName(QString::fromUtf8("rotate_x_val_3"));
        rotate_x_val_3->setMinimum(-360);
        rotate_x_val_3->setMaximum(360);
        rotate_x_val_3->setSingleStep(1);
        rotate_x_val_3->setOrientation(Qt::Horizontal);

        line_7->addWidget(rotate_x_val_3);


        verticalLayout_3->addLayout(line_7);

        line_8 = new QHBoxLayout();
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setContentsMargins(0, -1, -1, -1);
        label_8 = new QLabel(rotate_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setStyleSheet(QString::fromUtf8("	color: rgba(255, 255, 255, 102);"));

        line_8->addWidget(label_8);

        rotate_y_val_3 = new QSlider(rotate_3);
        rotate_y_val_3->setObjectName(QString::fromUtf8("rotate_y_val_3"));
        rotate_y_val_3->setMinimum(-360);
        rotate_y_val_3->setMaximum(360);
        rotate_y_val_3->setSingleStep(0);
        rotate_y_val_3->setOrientation(Qt::Horizontal);

        line_8->addWidget(rotate_y_val_3);


        verticalLayout_3->addLayout(line_8);

        line_9 = new QHBoxLayout();
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setContentsMargins(0, -1, -1, -1);
        label_9 = new QLabel(rotate_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setStyleSheet(QString::fromUtf8("	color: rgba(255, 255, 255, 102);"));

        line_9->addWidget(label_9);

        rotate_z_val_3 = new QSlider(rotate_3);
        rotate_z_val_3->setObjectName(QString::fromUtf8("rotate_z_val_3"));
        rotate_z_val_3->setMinimum(-360);
        rotate_z_val_3->setMaximum(360);
        rotate_z_val_3->setSingleStep(0);
        rotate_z_val_3->setOrientation(Qt::Horizontal);

        line_9->addWidget(rotate_z_val_3);


        verticalLayout_3->addLayout(line_9);


        gridLayout_4->addLayout(verticalLayout_3, 1, 0, 1, 1);


        gridLayout->addWidget(rotate_3, 2, 0, 1, 2);


        gridLayout_7->addWidget(frame, 0, 1, 3, 1);

        widget = new GLWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8("border-radius: 10px; \n"
"background-color: \"#252628\";\n"
"border: 1px solid \"#252628\";\n"
"padding: 5px;"));

        gridLayout_7->addWidget(widget, 1, 0, 1, 1);

        frame_8 = new QFrame(centralwidget);
        frame_8->setObjectName(QString::fromUtf8("frame_8"));
        sizePolicy1.setHeightForWidth(frame_8->sizePolicy().hasHeightForWidth());
        frame_8->setSizePolicy(sizePolicy1);
        frame_8->setStyleSheet(QString::fromUtf8("background-color: \"#515259\";"));
        frame_8->setFrameShape(QFrame::StyledPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        gridLayout_6 = new QGridLayout(frame_8);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        frame_9 = new QFrame(frame_8);
        frame_9->setObjectName(QString::fromUtf8("frame_9"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(frame_9->sizePolicy().hasHeightForWidth());
        frame_9->setSizePolicy(sizePolicy4);
        frame_9->setStyleSheet(QString::fromUtf8("border-color: rgb(94, 92, 100);\n"
"border-color: rgb(61, 56, 70);"));
        frame_9->setFrameShape(QFrame::StyledPanel);
        frame_9->setFrameShadow(QFrame::Raised);

        gridLayout_6->addWidget(frame_9, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer, 0, 1, 1, 1);


        gridLayout_7->addWidget(frame_8, 2, 0, 1, 1);

        header = new QLabel(centralwidget);
        header->setObjectName(QString::fromUtf8("header"));
        sizePolicy2.setHeightForWidth(header->sizePolicy().hasHeightForWidth());
        header->setSizePolicy(sizePolicy2);
        QFont font;
        font.setPointSize(24);
        font.setBold(true);
        font.setWeight(75);
        header->setFont(font);
        header->setStyleSheet(QString::fromUtf8("border-radius: 10px; \n"
"\n"
"border: 5px;\n"
"padding: 5px;\n"
""));
        header->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_7->addWidget(header, 0, 0, 1, 1);

        MainViewer->setCentralWidget(centralwidget);

        retranslateUi(MainViewer);

        QMetaObject::connectSlotsByName(MainViewer);
    } // setupUi

    void retranslateUi(QMainWindow *MainViewer)
    {
        MainViewer->setWindowTitle(QCoreApplication::translate("MainViewer", "MainViewer", nullptr));
        translate_title_6->setText(QCoreApplication::translate("MainViewer", "Move", nullptr));
        label_16->setText(QCoreApplication::translate("MainViewer", "X", nullptr));
        label_17->setText(QCoreApplication::translate("MainViewer", "Y", nullptr));
        label_18->setText(QCoreApplication::translate("MainViewer", "Z", nullptr));
        openObjBtn_3->setText(QCoreApplication::translate("MainViewer", "file", nullptr));
        renderBtn_3->setText(QCoreApplication::translate("MainViewer", "OPEN", nullptr));
        rotate_title_6->setText(QCoreApplication::translate("MainViewer", "Zoom", nullptr));
        label_2->setText(QCoreApplication::translate("MainViewer", "+", nullptr));
        label->setText(QCoreApplication::translate("MainViewer", "-", nullptr));
        rotate_title_3->setText(QCoreApplication::translate("MainViewer", "Rotation", nullptr));
        label_7->setText(QCoreApplication::translate("MainViewer", "X", nullptr));
        label_8->setText(QCoreApplication::translate("MainViewer", "Y", nullptr));
        label_9->setText(QCoreApplication::translate("MainViewer", "Z", nullptr));
        header->setText(QCoreApplication::translate("MainViewer", "<html><head/><body><p><span style=\" font-style:italic; color:#ffffff;\">\360\237\220\251 3D-Viewer</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainViewer: public Ui_MainViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINVIEWER_H
