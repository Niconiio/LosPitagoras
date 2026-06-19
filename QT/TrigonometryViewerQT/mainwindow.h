#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtCharts>
#include <QMainWindow>
//#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui {
class Fondo;
}
QT_END_NAMESPACE

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
};





#endif // MAINWINDOW_H
