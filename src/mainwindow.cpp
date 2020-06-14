#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <cassert>
#include <string>

#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>

#include <QList>

#include "view_model/graph_view_model.h"

#include <iostream>

MainWindow::MainWindow(std::unique_ptr<GraphViewModel> graphViewModel, QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow),
    graphViewModel_(std::move(graphViewModel))
{
  ui->setupUi(this);

  // Create Chart Series
  lineSeries_ = new QtCharts::QLineSeries;

  // Create Chart
  chart_ = new QtCharts::QChart();
  chart_->setTitle("Chart");
  chart_->setParent(ui->centralwidget);
  chart_->addSeries(lineSeries_);
  chart_->createDefaultAxes();
  chart_->legend()->setVisible(false);

  // Create Chart View
  QtCharts::QChartView * chartView = new QtCharts::QChartView;
  ui->verticalLayout->addWidget(chartView);
  chartView->setChart(chart_);

  ShowData();

  {
    // Add sample data
 /*
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
*/
  }
}

MainWindow::~MainWindow()
{
  delete ui;
}


void MainWindow::ShowData() {
  ui->lineEditXMin->setText(graphViewModel_->x_min_str().c_str());
  ui->lineEditXMax->setText(graphViewModel_->x_max_str().c_str());
  ui->lineEditStep->setText(graphViewModel_->step_str().c_str());

  // build chart
  lineSeries_->clear();
  size_t pointCount = graphViewModel_->pointCount();
  for (size_t i = 0; i < pointCount; ++i) {
    lineSeries_->append(graphViewModel_->x(i), graphViewModel_->y(i));
  }

  QList<QtCharts::QAbstractAxis*> hAxes = chart_->axes(Qt::Horizontal, lineSeries_);
    assert(hAxes.count() == 1);
    hAxes.first()->setRange(graphViewModel_->x_min(), graphViewModel_->x_max());

   std::cout << "x_min       : " << graphViewModel_->x_min() << std::endl;
   std::cout << "x_max       : " << graphViewModel_->x_max() << std::endl;
   std::cout << "step        : " << graphViewModel_->step() << std::endl;
   std::cout << "point count : " << graphViewModel_->pointCount() << std::endl;

    QList<QtCharts::QAbstractAxis*> vAxes = chart_->axes(Qt::Vertical, lineSeries_);
    assert(vAxes.count() == 1);
    vAxes.first()->setRange(0.0, 9.0);

}
