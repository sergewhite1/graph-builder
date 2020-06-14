#include "graph_model.h"

#include <limits>

GraphModel::GraphModel() {
  Update();
}

size_t GraphModel::pointCount() const {
  return static_cast<size_t>((x_max_ - x_min_) / step_);
}

void GraphModel::Update() {
  x_.clear();
  y_.clear();
  y_min_ = 0.0;
  y_max_ = 0.0;

  size_t pc = pointCount();

  x_.reserve(pc);
  y_.reserve(pc);

  if (pc > 0) {
    y_min_ = std::numeric_limits<double>::max();
    y_max_ = std::numeric_limits<double>::min();
  }

  double x, y;
  for (size_t i = 0; i < pc; ++i) {
    x = x_min_ + i * step_;
    y = x * x;

    if (y_min_ > y) {
      y_min_ = y;
    }

    if (y_max_ < y) {
      y_max_ = y;
    }

    x_.push_back(x);
    y_.push_back(y);
  }
}
