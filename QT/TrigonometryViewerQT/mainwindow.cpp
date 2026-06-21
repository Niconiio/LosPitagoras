#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCharts>
#include <QApplication>
//#include <QPainter>


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

    //No tienen mucho sentido estos metodos, deberian estar en privado estos atributos, para que tengan sentido
    S.dom[0] = 0;
    S.dom[1] = 2*pi;
    S.cos_sen();
    QLineSeries* eje_x = new QLineSeries;
    eje_x->append(S.dom[0],0);
    eje_x->append(S.dom[1],0);
    QLineSeries* eje_y = new QLineSeries;
    eje_y->append(0,S.rec[0]);
    eje_y->append(0,S.rec[1]);
    QLineSeries* series_temp = new QLineSeries;
    for (int ind = 0; ind < S.grafico.size(); ind ++){
        series_temp->append(S.grafico[ind][0],S.grafico[ind][1]);
    }
    series_sinusoidal = series_temp;//Cree la serie
    chart_sinusoidal = new QChart();
    chart_sinusoidal->addSeries(series_sinusoidal);
    chart_sinusoidal->addSeries(eje_x);
    chart_sinusoidal->addSeries(eje_y);
    chart_sinusoidal->legend()->hide();
    chart_sinusoidal->createDefaultAxes();
    chart_sinusoidal->setTitle("Función sinusoidal");
    return new QChartView(chart_sinusoidal);
}


//Voy a trabajar Aquí
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Fondo)
{
    seno.set_tipo(1);
    coseno.set_tipo(2);

    ui->setupUi(this);
    //this->setCentralWidget(ui->Tab_principal);
    ui->GraficoSeno->addWidget(chartView_seno);
    ui->GraficoCoseno->addWidget(chartView_coseno);


QObject::connect(ui->GraficarSeno, &QPushButton::clicked, this,[this](){
    //Dentro de Connect
    //ui->GraficoSeno->removeWidget(chartView_sinusoidal); //El char view alamacena la un grafico
    //ui->Grafico->addWidget(chartView);
    //chartView->setRenderHint(QPainter::Antialiasing);
    ui->GraficoSeno->removeWidget(chartView_seno);
    chartView_seno = graficar(seno);
    ui->GraficoSeno->addWidget(chartView_seno);

});


QObject::connect(ui->GraficarCoseno, &QPushButton::clicked, this,[this](){
    //Dentro de Connect
    //ui->GraficoSeno->removeWidget(chartView_sinusoidal); //El char view alamacena la un grafico
    //ui->Grafico->addWidget(chartView);
    //chartView->setRenderHint(QPainter::Antialiasing);
    ui->GraficoCoseno->removeWidget(chartView_coseno);
    chartView_coseno = graficar(coseno);
    ui->GraficoCoseno->addWidget(chartView_coseno);
});





/*

    QObject::connect(ui->GraficarSeno, &QPushButton::clicked, this,[this](){



    //Dentro de Connect
    ui->GraficoSeno->removeWidget(chartView_seno);
     QLineSeries* series = new QLineSeries;
     series->append(1,2);
     series->append(2,3);
     series->append(4,5);
     QChart*chart=new QChart();
     chart->addSeries(series);
     chart->legend()->hide();
     chart->createDefaultAxes();
     chart->setTitle("Función Seno");
     QChartView *chartView = new QChartView(chart);
     //ui->Grafico->addWidget(chartView);
     //chartView->setRenderHint(QPainter::Antialiasing);
     ui->GraficoSeno->addWidget(chartView);
     temp = chartView;
     count+=1;

    });
*/
}

MainWindow::~MainWindow()
{
    delete ui;
}
