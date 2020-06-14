#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <memory>

#include <QMainWindow>

#include "wht/listener.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

namespace QtCharts {
class QChart;
class QLineSeries;
}

class GraphViewModel;

class MainWindow : public QMainWindow, public wht::Listener
{
  Q_OBJECT

public:
  MainWindow(std::unique_ptr<GraphViewModel> graphViewModel, QWidget *parent = nullptr);
  ~MainWindow();

  // wht::Listener interface
  virtual void wht_listener_on_update() override;

  void ShowData();

private slots:
  void on_lineEditXMin_textEdited(const QString &arg1);

  void on_pushButtonBuild_clicked();

private:
  Ui::MainWindow *ui;
  std::unique_ptr<GraphViewModel> graphViewModel_;
  QtCharts::QLineSeries * lineSeries_ = nullptr;
  QtCharts::QChart * chart_ = nullptr;
};
#endif // MAINWINDOW_H
