#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtCharts>
#include <QMainWindow>
#include "sinusoidales.h"
#include "circulo_u.h"
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
Circulo_u *circulo;



    QChartView* temp;
    int count = 0;
    Ui::Fondo *ui;
    sinusoidal seno;
    sinusoidal coseno;
    QChart* chart_sinusoidal= new QChart();
    QLineSeries* series_sinusoidal = new QLineSeries; //Puede mantenrse
     //Puede mantenerse
    QChartView* chartView_seno = new QChartView(chart_sinusoidal);
    QChartView* chartView_coseno = new QChartView(chart_sinusoidal);
    QChartView* graficar(sinusoidal S);


    void actualizarCirculo();



};



#endif // MAINWINDOW_H
