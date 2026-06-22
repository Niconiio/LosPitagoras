#include "circulo_u.h"
#include <cmath>

Circulo_u::Circulo_u(QWidget *parent):QChartView(parent), angulo(0.0) {
    Grafico= new QChart();

    circuloSeries= new QLineSeries();
    hipotenusaSeries= new QLineSeries();
    cosSeries= new QLineSeries();
    senSeries= new QLineSeries();
    puntosSeries= new QScatterSeries();
    puntosSeries->setMarkerSize(12);

    circulo();
    Grafico->addSeries(circuloSeries);
    Grafico->addSeries(hipotenusaSeries);
    Grafico->addSeries(cosSeries);
    Grafico->addSeries(senSeries);
    Grafico->addSeries(puntosSeries);

    Grafico->legend()->hide();

    auto *axisX = new QValueAxis();
    auto *axisY = new QValueAxis();

    axisX->setRange(-1.2,1.2);
    axisY->setRange(-1.2,1.2);

    Grafico->addAxis(axisX, Qt::AlignBottom);
    Grafico->addAxis(axisY, Qt::AlignLeft);

    for(QAbstractSeries *s : Grafico->series())
    {
        s->attachAxis(axisX);
        s->attachAxis(axisY);
    }

    setChart(Grafico);

    mostrarInfo();
}
void Circulo_u::circulo()
{
    circuloSeries->clear();

    for(int i=0;i<=360;i++)
    {
        double rad = i * M_PI / 180.0;//usar funcion para transformar de grad a rad

        double x = cos(rad);
        double y = sin(rad);

        circuloSeries->append(x,y);
    }
}
void Circulo_u::ponerAngulo(double grados){
    angulo= grados;
    mostrarInfo();
}

void Circulo_u::mostrarInfo()
{
    hipotenusaSeries->clear();
    cosSeries->clear();
    senSeries->clear();
    puntosSeries->clear();

    double rad = angulo * M_PI / 180.0;

    double x = cos(rad);
    double y = sin(rad);

    hipotenusaSeries->append(0,0);
    hipotenusaSeries->append(x,y);

    cosSeries->append(0,0);
    cosSeries->append(x,0);

    senSeries->append(x,0);
    senSeries->append(x,y);

    puntosSeries->append(x,y);
}




