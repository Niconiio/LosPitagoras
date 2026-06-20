#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtCharts>
#include <QMainWindow>
#include "sinusoidales.h"
//#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui {
class Fondo;
}
QT_END_NAMESPACE



//Aquí
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
private slots:


private:



    QChartView* temp;
    int count = 0;
    Ui::Fondo *ui;
    sinusoidal seno;
    sinusoidal coseno;
    QLineSeries* series_seno = new QLineSeries; //Puede mantenrse
    QChart* chart_seno= new QChart(); //Puede mantenerse
    QChartView* chartView_seno = new QChartView(chart_seno);


};





#endif // MAINWINDOW_H
