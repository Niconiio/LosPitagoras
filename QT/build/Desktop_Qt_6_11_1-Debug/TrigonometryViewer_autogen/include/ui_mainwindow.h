/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Fondo
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *Grafico;
    QPushButton *SenoBtn;
    QWidget *widget;
    QPushButton *aaaa;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Fondo)
    {
        if (Fondo->objectName().isEmpty())
            Fondo->setObjectName("Fondo");
        Fondo->resize(713, 600);
        QPalette palette;
        QBrush brush(QColor(87, 112, 110, 255));
        brush.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Highlight, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Highlight, brush);
        Fondo->setPalette(palette);
        QFont font;
        font.setBold(false);
        font.setUnderline(false);
        font.setStrikeOut(false);
        font.setKerning(false);
        Fondo->setFont(font);
        Fondo->setAutoFillBackground(false);
        centralwidget = new QWidget(Fondo);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(40, 60, 321, 241));
        Grafico = new QVBoxLayout(verticalLayoutWidget);
        Grafico->setObjectName("Grafico");
        Grafico->setContentsMargins(0, 0, 0, 0);
        SenoBtn = new QPushButton(centralwidget);
        SenoBtn->setObjectName("SenoBtn");
        SenoBtn->setGeometry(QRect(400, 80, 259, 24));
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(120, 290, 120, 80));
        aaaa = new QPushButton(centralwidget);
        aaaa->setObjectName("aaaa");
        aaaa->setGeometry(QRect(480, 260, 80, 24));
        Fondo->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Fondo);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 713, 22));
        Fondo->setMenuBar(menubar);
        statusbar = new QStatusBar(Fondo);
        statusbar->setObjectName("statusbar");
        Fondo->setStatusBar(statusbar);

        retranslateUi(Fondo);

        QMetaObject::connectSlotsByName(Fondo);
    } // setupUi

    void retranslateUi(QMainWindow *Fondo)
    {
        Fondo->setWindowTitle(QCoreApplication::translate("Fondo", "Trigonometry Viewer", nullptr));
        SenoBtn->setText(QCoreApplication::translate("Fondo", "Seno", nullptr));
        aaaa->setText(QCoreApplication::translate("Fondo", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Fondo: public Ui_Fondo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
