#include "mainwindow.h"

#include <memory>

#include <QApplication>

#include "model/graph_model.h"
#include "view_model/graph_view_model.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  auto graphModel = std::make_unique<GraphModel>();
  auto graphViewModel = std::make_unique<GraphViewModel>(std::move(graphModel));
  MainWindow w(std::move(graphViewModel));

  w.showNormal();
  //w.show();

  return a.exec();
}
