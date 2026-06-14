#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCharts>
#include <QApplication>






MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Fondo)
{

    ui->setupUi(this);


    QObject::connect(ui->SenoBtn, &QPushButton::clicked, this,[this](){




    if (count > 0) {ui->Grafico->removeWidget(temp);}

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
     chartView->setRenderHint(QPainter::Antialiasing);
     ui->Grafico->addWidget(chartView);
     temp = chartView;
     count+=1;

    });

}

MainWindow::~MainWindow()
{
    delete ui;
}


