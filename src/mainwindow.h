#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <memory>

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

namespace QtCharts {
class QChart;
class QLineSeries;
}

class GraphViewModel;

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(std::unique_ptr<GraphViewModel> graphViewModel, QWidget *parent = nullptr);
  ~MainWindow();

  void ShowData();

private:
  Ui::MainWindow *ui;
  std::unique_ptr<GraphViewModel> graphViewModel_;
  QtCharts::QLineSeries * lineSeries_ = nullptr;
  QtCharts::QChart * chart_ = nullptr;
};
#endif // MAINWINDOW_H
