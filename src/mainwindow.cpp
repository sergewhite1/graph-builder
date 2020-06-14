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

  graphViewModel_->reg_listener(this);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::ShowData() {
  ui->lineEditXMin->setText(graphViewModel_->x_min_str().c_str());
  ui->lineEditXMax->setText(graphViewModel_->x_max_str().c_str());
  ui->lineEditStep->setText(graphViewModel_->step_str().c_str());

  ui->pushButtonBuild->setEnabled(graphViewModel_->need_update());

  if (graphViewModel_->need_update() == false) {
    // build chart
    lineSeries_->clear();
    size_t pointCount = graphViewModel_->point_count();
    for (size_t i = 0; i < pointCount; ++i) {
      lineSeries_->append(graphViewModel_->x(i), graphViewModel_->y(i));
    }

    std::cout << "x_min       : " << graphViewModel_->x_min() << std::endl;
    std::cout << "x_max       : " << graphViewModel_->x_max() << std::endl;
    std::cout << "step        : " << graphViewModel_->step() << std::endl;
    std::cout << "point count : " << graphViewModel_->point_count() << std::endl;
    std::cout << "y_min       : " << graphViewModel_->y_min() << std::endl;
    std::cout << "y_max       : " << graphViewModel_->y_max() << std::endl;

    QList<QtCharts::QAbstractAxis*> hAxes = chart_->axes(Qt::Horizontal, lineSeries_);
    assert(hAxes.count() == 1);
    hAxes.first()->setRange(graphViewModel_->x_min(), graphViewModel_->x_max());

    QList<QtCharts::QAbstractAxis*> vAxes = chart_->axes(Qt::Vertical, lineSeries_);
    assert(vAxes.count() == 1);
    vAxes.first()->setRange(graphViewModel_->y_min(), graphViewModel_->y_max());
  }
}

void MainWindow::on_lineEditXMin_textEdited(const QString &arg1)
{
  graphViewModel_->set_x_min_str(arg1.toStdString());
}

void MainWindow::wht_listener_on_update() {
  ShowData();
}

void MainWindow::on_pushButtonBuild_clicked()
{
  graphViewModel_->update();
}

void MainWindow::on_lineEditXMax_textEdited(const QString &arg1)
{
  graphViewModel_->set_x_max_str(arg1.toStdString());
}
