/********************************************************************************
** Form generated from reading UI file 'rasterisation.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RASTERISATION_H
#define UI_RASTERISATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Rasterisation
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QSpinBox *spinBox_4;
    QLabel *label_6;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QLabel *label_3;
    QSpinBox *spinBox_3;
    QLabel *label_2;
    QLabel *label_5;
    QLabel *label_8;
    QSpinBox *spinBox_5;
    QVBoxLayout *verticalLayout;
    QRadioButton *StepAlgorithm;
    QRadioButton *CDA;
    QRadioButton *Bresenhem;
    QRadioButton *radioButton_4;
    QRadioButton *Kastl_Pitway;
    QRadioButton *AlWu;
    QPushButton *pushButton;
    QLabel *label_7;
    QSlider *horizontalSlider;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Rasterisation)
    {
        if (Rasterisation->objectName().isEmpty())
            Rasterisation->setObjectName(QString::fromUtf8("Rasterisation"));
        Rasterisation->resize(800, 600);
        centralwidget = new QWidget(Rasterisation);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(250);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setScaledContents(false);

        horizontalLayout->addWidget(label);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        spinBox_4 = new QSpinBox(centralwidget);
        spinBox_4->setObjectName(QString::fromUtf8("spinBox_4"));

        gridLayout->addWidget(spinBox_4, 2, 2, 1, 1);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(label_6, 0, 0, 1, 1);

        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        gridLayout->addWidget(spinBox, 1, 1, 1, 1);

        spinBox_2 = new QSpinBox(centralwidget);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));

        gridLayout->addWidget(spinBox_2, 1, 2, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        spinBox_3 = new QSpinBox(centralwidget);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));

        gridLayout->addWidget(spinBox_3, 2, 1, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 3, 0, 1, 1);

        spinBox_5 = new QSpinBox(centralwidget);
        spinBox_5->setObjectName(QString::fromUtf8("spinBox_5"));

        gridLayout->addWidget(spinBox_5, 3, 1, 1, 2);


        verticalLayout_2->addLayout(gridLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        StepAlgorithm = new QRadioButton(centralwidget);
        StepAlgorithm->setObjectName(QString::fromUtf8("StepAlgorithm"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(StepAlgorithm->sizePolicy().hasHeightForWidth());
        StepAlgorithm->setSizePolicy(sizePolicy3);

        verticalLayout->addWidget(StepAlgorithm);

        CDA = new QRadioButton(centralwidget);
        CDA->setObjectName(QString::fromUtf8("CDA"));
        sizePolicy3.setHeightForWidth(CDA->sizePolicy().hasHeightForWidth());
        CDA->setSizePolicy(sizePolicy3);

        verticalLayout->addWidget(CDA);

        Bresenhem = new QRadioButton(centralwidget);
        Bresenhem->setObjectName(QString::fromUtf8("Bresenhem"));
        sizePolicy3.setHeightForWidth(Bresenhem->sizePolicy().hasHeightForWidth());
        Bresenhem->setSizePolicy(sizePolicy3);

        verticalLayout->addWidget(Bresenhem);

        radioButton_4 = new QRadioButton(centralwidget);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));
        sizePolicy3.setHeightForWidth(radioButton_4->sizePolicy().hasHeightForWidth());
        radioButton_4->setSizePolicy(sizePolicy3);

        verticalLayout->addWidget(radioButton_4);

        Kastl_Pitway = new QRadioButton(centralwidget);
        Kastl_Pitway->setObjectName(QString::fromUtf8("Kastl_Pitway"));
        sizePolicy3.setHeightForWidth(Kastl_Pitway->sizePolicy().hasHeightForWidth());
        Kastl_Pitway->setSizePolicy(sizePolicy3);

        verticalLayout->addWidget(Kastl_Pitway);

        AlWu = new QRadioButton(centralwidget);
        AlWu->setObjectName(QString::fromUtf8("AlWu"));
        sizePolicy3.setHeightForWidth(AlWu->sizePolicy().hasHeightForWidth());
        AlWu->setSizePolicy(sizePolicy3);

        verticalLayout->addWidget(AlWu);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_7);

        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(horizontalSlider->sizePolicy().hasHeightForWidth());
        horizontalSlider->setSizePolicy(sizePolicy4);
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider);


        verticalLayout_2->addLayout(verticalLayout);


        horizontalLayout->addLayout(verticalLayout_2);

        Rasterisation->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Rasterisation);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        Rasterisation->setMenuBar(menubar);
        statusbar = new QStatusBar(Rasterisation);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Rasterisation->setStatusBar(statusbar);

        retranslateUi(Rasterisation);

        QMetaObject::connectSlotsByName(Rasterisation);
    } // setupUi

    void retranslateUi(QMainWindow *Rasterisation)
    {
        Rasterisation->setWindowTitle(QCoreApplication::translate("Rasterisation", "Rasterisation", nullptr));
        label->setText(QString());
        label_4->setText(QCoreApplication::translate("Rasterisation", "\320\235\320\260\321\207\320\260\320\273\321\214\320\275\320\260\321\217 \321\202\320\276\321\207\320\272\320\260", nullptr));
        label_6->setText(QString());
        label_3->setText(QCoreApplication::translate("Rasterisation", "y", nullptr));
        label_2->setText(QCoreApplication::translate("Rasterisation", "x", nullptr));
        label_5->setText(QCoreApplication::translate("Rasterisation", "\320\232\320\276\320\275\320\265\321\207\320\275\320\260\321\217 \321\202\320\276\321\207\320\272\320\260", nullptr));
        label_8->setText(QCoreApplication::translate("Rasterisation", "\320\240\320\260\320\264\320\270\321\203\321\201", nullptr));
        StepAlgorithm->setText(QCoreApplication::translate("Rasterisation", "\320\237\320\276\321\210\320\260\320\263\320\276\320\262\321\213\320\271 \320\260\320\273\320\263\320\276\321\200\320\270\321\202\320\274", nullptr));
        CDA->setText(QCoreApplication::translate("Rasterisation", "\320\220\320\273\320\263\320\276\321\200\320\270\321\202\320\274 \320\246\320\224\320\220", nullptr));
        Bresenhem->setText(QCoreApplication::translate("Rasterisation", "\320\220\320\273\320\263\320\276\321\200\320\270\321\202\320\274 \320\221\321\200\320\265\320\267\320\265\320\275\321\205\320\265\320\274\320\260", nullptr));
        radioButton_4->setText(QCoreApplication::translate("Rasterisation", "\320\220\320\273\320\263\320\276\321\200\320\270\321\202\320\274 \320\221\321\200\320\265\320\267\320\265\320\275\321\205\320\265\320\274\320\260(\320\236\320\272\321\200\321\203\320\266\320\275\320\276\321\201\321\202\321\214)", nullptr));
        Kastl_Pitway->setText(QCoreApplication::translate("Rasterisation", "\320\220\320\273\320\263\320\276\321\200\320\270\321\202\320\274 \320\232\320\260\321\201\321\202\320\273\320\260-\320\237\320\270\321\202\320\262\320\265\321\217", nullptr));
        AlWu->setText(QCoreApplication::translate("Rasterisation", "\320\220\320\273\320\263\320\276\321\200\320\270\321\202\320\274 \320\222\321\203", nullptr));
        pushButton->setText(QCoreApplication::translate("Rasterisation", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 \321\210\320\260\320\263\320\260\321\205", nullptr));
        label_7->setText(QCoreApplication::translate("Rasterisation", "\320\247\320\260\321\201\321\202\320\276\321\202\320\260 \320\264\320\265\320\273\320\265\320\275\320\270\320\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Rasterisation: public Ui_Rasterisation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RASTERISATION_H
