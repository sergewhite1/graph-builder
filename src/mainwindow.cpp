#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <cassert>

#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>

#include <QList>

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  // Create Chart Series
  QtCharts::QLineSeries * lineSeries = new QtCharts::QLineSeries;

  // Create Chart
  QtCharts::QChart * chart = new QtCharts::QChart();
  chart->setTitle("Chart");
  chart->setParent(ui->centralwidget);
  chart->addSeries(lineSeries);
  chart->createDefaultAxes();
  chart->legend()->setVisible(false);

  // Create Chart View
  QtCharts::QChartView * chartView = new QtCharts::QChartView;
  ui->verticalLayout->addWidget(chartView);
  chartView->setChart(chart);

  {
    // Add sample data
    const double x_min = -3.0;
    const double x_max =  3.0;
    const double step = 0.01;
    const int point_count = static_cast<int>((x_max - x_min) / step);
    double x, y;
    for (int i = 0; i < point_count; ++i) {
      x = x_min + i * step;
      y = x * x;
      lineSeries->append(x, y);
    }

    QList<QtCharts::QAbstractAxis*> hAxes = chart->axes(Qt::Horizontal, lineSeries);
    assert(hAxes.count() == 1);
    hAxes.first()->setRange(x_min, x_max);

    QList<QtCharts::QAbstractAxis*> vAxes = chart->axes(Qt::Vertical, lineSeries);
    assert(vAxes.count() == 1);
    vAxes.first()->setRange(0.0, 9.0);
  }
}

MainWindow::~MainWindow()
{
  delete ui;
}

