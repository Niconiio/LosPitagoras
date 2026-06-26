#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCharts>
#include <QApplication>



QChartView* MainWindow::graficar(sinusoidal S){



    if (S.get_tipo() == 1){
        S.set_A(ui->spinBox_A_seno->value());
        S.rec[0] = ui->spinBox_A_seno->value();
        S.rec[1] = -ui->spinBox_A_seno->value();
        S.set_B(ui->spinBox_B_seno->value());
        S.set_C(ui->spinBox_C_seno->value());
    }else if (S.get_tipo() == 2){
        S.set_A(ui->spinBox_A_coseno->value());
        S.rec[0] = ui->spinBox_A_coseno->value();
        S.rec[1] = -ui->spinBox_A_coseno->value();
        S.set_B(ui->spinBox_B_coseno->value());
        S.set_C(ui->spinBox_C_coseno->value());
    }

    S.cos_sen();
    QLineSeries* eje_x = new QLineSeries;
    eje_x->append(S.dom[0],0);
    eje_x->append(S.dom[1],0);
    QLineSeries* series_temp = new QLineSeries;
    for (int ind = 0; ind < S.grafico.size(); ind ++){
        series_temp->append(S.grafico[ind][0],S.grafico[ind][1]);
    }
    series_sinusoidal = series_temp;//Cree la serie
    chart_sinusoidal = new QChart();
    chart_sinusoidal->addSeries(series_sinusoidal);
    chart_sinusoidal->addSeries(eje_x);

    chart_sinusoidal->legend()->hide();
    chart_sinusoidal->createDefaultAxes();
    QString texto;
    if (S.tipo == 1){
        if (ui->spinBox_A_seno->value() == 1 && ui->spinBox_B_seno->value() == 1 && ui->spinBox_C_seno->value() == 0){texto = QString("sen(x)");}
        else{texto = QString("%1seno(%2x + %3)").arg(ui->spinBox_A_seno->value()).arg(ui->spinBox_B_seno->value()).arg(ui->spinBox_C_seno->value());}
    } else if (S.tipo == 2){
        if (ui->spinBox_A_coseno->value() == 1 && ui->spinBox_B_coseno->value() == 1 && ui->spinBox_C_coseno->value() == 0){texto = QString("cos(x)");}
        else{texto = QString("%1coseno(%2x + %3)").arg(ui->spinBox_A_coseno->value()).arg(ui->spinBox_B_coseno->value()).arg(ui->spinBox_C_coseno->value());}
    }

    chart_sinusoidal->setTitle(texto);
    return new QChartView(chart_sinusoidal);
}


//Voy a trabajar Aquí
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Fondo)
{
    ui->setupUi(this);

    seno.set_tipo(1);
    coseno.set_tipo(2);
    seno.dom[0] = -2*pi;
    seno.dom[1] = 2*pi;
    coseno.dom[0] = -2*pi;
    coseno.dom[1] = 2*pi;


    ui->GraficoSeno->addWidget(chartView_seno);
    ui->GraficoCoseno->addWidget(chartView_coseno);



QObject::connect(ui->spinBox_A_seno, &QSpinBox::valueChanged, this,[this](){

    ui->GraficoSeno->removeWidget(chartView_seno);
    chartView_seno = graficar(seno);
    ui->GraficoSeno->addWidget(chartView_seno);

});


QObject::connect(ui->spinBox_B_seno, &QSpinBox::valueChanged, this,[this](){

    ui->GraficoSeno->removeWidget(chartView_seno);
    chartView_seno = graficar(seno);
    ui->GraficoSeno->addWidget(chartView_seno);

});

QObject::connect(ui->spinBox_C_seno, &QSpinBox::valueChanged, this,[this](){

    ui->GraficoSeno->removeWidget(chartView_seno);
    chartView_seno = graficar(seno);
    ui->GraficoSeno->addWidget(chartView_seno);

});

QObject::connect(ui->spinBox_A_coseno, &QSpinBox::valueChanged, this,[this](){

    ui->GraficoCoseno->removeWidget(chartView_coseno);
    chartView_coseno = graficar(coseno);
    ui->GraficoCoseno->addWidget(chartView_coseno);

});


QObject::connect(ui->spinBox_B_coseno, &QSpinBox::valueChanged, this,[this](){

    ui->GraficoCoseno->removeWidget(chartView_coseno);
    chartView_coseno = graficar(coseno);
    ui->GraficoCoseno->addWidget(chartView_coseno);

});

QObject::connect(ui->spinBox_C_coseno, &QSpinBox::valueChanged, this,[this](){

    ui->GraficoCoseno->removeWidget(chartView_coseno);
    chartView_coseno = graficar(coseno);
    ui->GraficoCoseno->addWidget(chartView_coseno);

});


QObject::connect(ui->Desplazamiento_horizontal_seno, &QSlider::valueChanged, this,[this](){


    seno.dom[0] = -2*pi + ui->Desplazamiento_horizontal_seno->value();
    seno.dom[1] = 2*pi + ui->Desplazamiento_horizontal_seno->value();
    ui->GraficoSeno->removeWidget(chartView_seno);
    chartView_seno = graficar(seno);
    ui->GraficoSeno->addWidget(chartView_seno);
});


QObject::connect(ui->Desplazamiento_horizontal_coseno, &QSlider::valueChanged, this,[this](){


    coseno.dom[0] = -2*pi + ui->Desplazamiento_horizontal_coseno->value();
    coseno.dom[1] = 2*pi + ui->Desplazamiento_horizontal_coseno->value();
    ui->GraficoCoseno->removeWidget(chartView_coseno);
    chartView_coseno = graficar(coseno);
    ui->GraficoCoseno->addWidget(chartView_coseno);
});

QObject::connect(ui->anguloSpinBox,qOverload<double>(&QDoubleSpinBox::valueChanged),ui->circuloWidget, &Circulo_u::ponerAngulo);




}

MainWindow::~MainWindow()
{
    delete ui;
}

