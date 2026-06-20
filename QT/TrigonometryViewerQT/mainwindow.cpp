#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCharts>
#include <QApplication>
//#include <QPainter>


//Voy a trabajar Aquí
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Fondo)
{

    ui->setupUi(this);
    this->setCentralWidget(ui->Tab_principal);


    ui->GraficoSeno->addWidget(chartView_seno);


QObject::connect(ui->GraficarSeno, &QPushButton::clicked, this,[this](){


    //Dentro de Connect
    ui->GraficoSeno->removeWidget(chartView_seno);

    seno.set_A(ui->spinBox_A_seno->value());
    seno.set_B(ui->spinBox_B_seno->value());
    seno.set_C(ui->spinBox_C_seno->value());
    seno.dom[0] = 0;
    seno.dom[1] = 2*pi;
    seno.set_tipo(1);
    seno.cos_sen();
    QLineSeries* series_temp = new QLineSeries;
    for (int ind = 0; ind < seno.grafico.size(); ind ++){
        series_temp->append(seno.grafico[ind][0],seno.grafico[ind][1]);
    }
    series_seno = series_temp;//Cree la serie

    chart_seno->addSeries(series_seno);
    chart_seno->legend()->hide();
    chart_seno->createDefaultAxes();
    chart_seno->setTitle("Función Seno");
    chartView_seno = new QChartView(chart_seno);
    //ui->Grafico->addWidget(chartView);
    //chartView->setRenderHint(QPainter::Antialiasing);
    ui->GraficoSeno->addWidget(chartView_seno);

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
