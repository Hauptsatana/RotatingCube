/********************************************************************************
** Form generated from reading UI file 'rotating_cube.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROTATING_CUBE_H
#define UI_ROTATING_CUBE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <render_area.h>

QT_BEGIN_NAMESPACE

class Ui_RotatingCubeClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QSplitter *splitter;
    RenderArea *renderArea;
    QWidget *settings;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QSlider *timeoutSlider;
    QWidget *widget;
    QGridLayout *gridLayout;
    QFormLayout *formLayout;
    QCheckBox *chbox_RotateX;
    QDoubleSpinBox *dspn_AngleX;
    QCheckBox *chbox_RotateY;
    QDoubleSpinBox *dspn_AngleY;
    QCheckBox *chbox_RotateZ;
    QDoubleSpinBox *dspn_AngleZ;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *rbtn_Isometric;
    QRadioButton *rbtn_Dimetric;
    QRadioButton *rbtn_Cabinet;
    QSpacerItem *verticalSpacer;

    void setupUi(QMainWindow *RotatingCubeClass)
    {
        if (RotatingCubeClass->objectName().isEmpty())
            RotatingCubeClass->setObjectName(QStringLiteral("RotatingCubeClass"));
        RotatingCubeClass->resize(752, 524);
        centralWidget = new QWidget(RotatingCubeClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy1);
        splitter->setOrientation(Qt::Horizontal);
        splitter->setHandleWidth(15);
        splitter->setChildrenCollapsible(false);
        renderArea = new RenderArea(splitter);
        renderArea->setObjectName(QStringLiteral("renderArea"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(renderArea->sizePolicy().hasHeightForWidth());
        renderArea->setSizePolicy(sizePolicy2);
        renderArea->setFrameShape(QFrame::Box);
        renderArea->setFrameShadow(QFrame::Plain);
        renderArea->setLineWidth(2);
        splitter->addWidget(renderArea);
        settings = new QWidget(splitter);
        settings->setObjectName(QStringLiteral("settings"));
        settings->setEnabled(true);
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(settings->sizePolicy().hasHeightForWidth());
        settings->setSizePolicy(sizePolicy3);
        settings->setBaseSize(QSize(0, 0));
        settings->setLayoutDirection(Qt::LeftToRight);
        settings->setAutoFillBackground(false);
        verticalLayout_3 = new QVBoxLayout(settings);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(15);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton = new QPushButton(settings);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy4);
        QFont font;
        font.setPointSize(12);
        pushButton->setFont(font);
        pushButton->setCheckable(true);
        pushButton->setChecked(false);
        pushButton->setAutoRepeat(true);

        verticalLayout->addWidget(pushButton);

        timeoutSlider = new QSlider(settings);
        timeoutSlider->setObjectName(QStringLiteral("timeoutSlider"));
        timeoutSlider->setMinimum(20);
        timeoutSlider->setMaximum(200);
        timeoutSlider->setSingleStep(10);
        timeoutSlider->setPageStep(40);
        timeoutSlider->setValue(80);
        timeoutSlider->setOrientation(Qt::Horizontal);
        timeoutSlider->setInvertedAppearance(true);

        verticalLayout->addWidget(timeoutSlider);

        widget = new QWidget(settings);
        widget->setObjectName(QStringLiteral("widget"));
        sizePolicy4.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy4);
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        chbox_RotateX = new QCheckBox(widget);
        chbox_RotateX->setObjectName(QStringLiteral("chbox_RotateX"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(chbox_RotateX->sizePolicy().hasHeightForWidth());
        chbox_RotateX->setSizePolicy(sizePolicy5);
        chbox_RotateX->setChecked(true);
        chbox_RotateX->setTristate(false);

        formLayout->setWidget(1, QFormLayout::LabelRole, chbox_RotateX);

        dspn_AngleX = new QDoubleSpinBox(widget);
        dspn_AngleX->setObjectName(QStringLiteral("dspn_AngleX"));
        dspn_AngleX->setWrapping(false);
        dspn_AngleX->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        dspn_AngleX->setMinimum(-30);
        dspn_AngleX->setMaximum(30);
        dspn_AngleX->setSingleStep(3);
        dspn_AngleX->setValue(6);

        formLayout->setWidget(1, QFormLayout::FieldRole, dspn_AngleX);

        chbox_RotateY = new QCheckBox(widget);
        chbox_RotateY->setObjectName(QStringLiteral("chbox_RotateY"));
        chbox_RotateY->setChecked(true);

        formLayout->setWidget(2, QFormLayout::LabelRole, chbox_RotateY);

        dspn_AngleY = new QDoubleSpinBox(widget);
        dspn_AngleY->setObjectName(QStringLiteral("dspn_AngleY"));
        dspn_AngleY->setMinimum(-30);
        dspn_AngleY->setMaximum(30);
        dspn_AngleY->setSingleStep(3);
        dspn_AngleY->setValue(3);

        formLayout->setWidget(2, QFormLayout::FieldRole, dspn_AngleY);

        chbox_RotateZ = new QCheckBox(widget);
        chbox_RotateZ->setObjectName(QStringLiteral("chbox_RotateZ"));
        chbox_RotateZ->setChecked(true);

        formLayout->setWidget(3, QFormLayout::LabelRole, chbox_RotateZ);

        dspn_AngleZ = new QDoubleSpinBox(widget);
        dspn_AngleZ->setObjectName(QStringLiteral("dspn_AngleZ"));
        dspn_AngleZ->setMinimum(-30);
        dspn_AngleZ->setMaximum(30);
        dspn_AngleZ->setSingleStep(3);
        dspn_AngleZ->setValue(12);

        formLayout->setWidget(3, QFormLayout::FieldRole, dspn_AngleZ);


        gridLayout->addLayout(formLayout, 0, 0, 1, 1);


        verticalLayout->addWidget(widget);

        groupBox = new QGroupBox(settings);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        sizePolicy4.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy4);
        groupBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(9, 9, 9, 9);
        rbtn_Isometric = new QRadioButton(groupBox);
        rbtn_Isometric->setObjectName(QStringLiteral("rbtn_Isometric"));
        rbtn_Isometric->setChecked(true);

        verticalLayout_2->addWidget(rbtn_Isometric);

        rbtn_Dimetric = new QRadioButton(groupBox);
        rbtn_Dimetric->setObjectName(QStringLiteral("rbtn_Dimetric"));
        rbtn_Dimetric->setChecked(false);

        verticalLayout_2->addWidget(rbtn_Dimetric);

        rbtn_Cabinet = new QRadioButton(groupBox);
        rbtn_Cabinet->setObjectName(QStringLiteral("rbtn_Cabinet"));

        verticalLayout_2->addWidget(rbtn_Cabinet);


        gridLayout_2->addLayout(verticalLayout_2, 0, 0, 1, 1);


        verticalLayout->addWidget(groupBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        verticalLayout_3->addLayout(verticalLayout);

        splitter->addWidget(settings);

        gridLayout_3->addWidget(splitter, 0, 0, 1, 1);

        RotatingCubeClass->setCentralWidget(centralWidget);

        retranslateUi(RotatingCubeClass);

        QMetaObject::connectSlotsByName(RotatingCubeClass);
    } // setupUi

    void retranslateUi(QMainWindow *RotatingCubeClass)
    {
        RotatingCubeClass->setWindowTitle(QApplication::translate("RotatingCubeClass", "RotatingCube", Q_NULLPTR));
        pushButton->setText(QApplication::translate("RotatingCubeClass", "\320\227\320\220\320\237\320\243\320\241\320\232/\320\241\320\242\320\236\320\237", Q_NULLPTR));
        chbox_RotateX->setText(QApplication::translate("RotatingCubeClass", "\320\222\321\200\320\260\321\211\320\265\320\275\320\270\320\265 \320\262\320\276\320\272\321\200\321\203\320\263 OX", Q_NULLPTR));
        chbox_RotateY->setText(QApplication::translate("RotatingCubeClass", "\320\222\321\200\320\260\321\211\320\265\320\275\320\270\320\265 \320\262\320\276\320\272\321\200\321\203\320\263 OY", Q_NULLPTR));
        chbox_RotateZ->setText(QApplication::translate("RotatingCubeClass", "\320\222\321\200\320\260\321\211\320\265\320\275\320\270\320\265 \320\262\320\276\320\272\321\200\321\203\320\263 OZ", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("RotatingCubeClass", "\320\237\321\200\320\276\320\265\320\272\321\206\320\270\321\217", Q_NULLPTR));
        rbtn_Isometric->setText(QApplication::translate("RotatingCubeClass", "\320\230\320\267\320\276\320\274\320\265\321\202\321\200\320\270\321\207\320\265\321\201\320\272\320\260\321\217", Q_NULLPTR));
        rbtn_Dimetric->setText(QApplication::translate("RotatingCubeClass", "\320\224\320\270\320\274\320\265\321\202\321\200\320\270\321\207\320\265\321\201\320\272\320\260\321\217", Q_NULLPTR));
        rbtn_Cabinet->setText(QApplication::translate("RotatingCubeClass", "\320\237\321\200\320\276\320\265\320\272\321\206\320\270\321\217 \320\232\320\260\320\261\320\270\320\275\320\265", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RotatingCubeClass: public Ui_RotatingCubeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROTATING_CUBE_H
