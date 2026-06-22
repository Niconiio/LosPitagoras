#ifndef CIRCULO_U_H
#define CIRCULO_U_H
#include <QtCharts>
#include <QtCharts/QPolarChart>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include <cmath>
#include <QMainWindow>
#include <QObject>
#include <QWidget>

class Circulo_u: public QChartView{
    Q_OBJECT
public:
    Circulo_u(QWidget *parent = nullptr);
    void ponerAngulo(double grados);
private:
    void circulo();
    void mostrarInfo();

    QChart *Grafico;

    QLineSeries *circuloSeries;
    QLineSeries *hipotenusaSeries;
    QLineSeries *cosSeries;
    QLineSeries *senSeries;

    QScatterSeries *puntosSeries;

    double angulo;

};

#endif // CIRCULO_U_H
