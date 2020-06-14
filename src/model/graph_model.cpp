#include "graph_model.h"

GraphModel::GraphModel() {
  Update();
}

size_t GraphModel::pointCount() const {
  return static_cast<size_t>((x_max_ - x_min_) / step_);
}

void GraphModel::Update() {
  x_.clear();
  y_.clear();

  size_t pc = pointCount();

  x_.reserve(pc);
  y_.reserve(pc);

  double x;
  for (size_t i = 0; i < pc; ++i) {
    x = x_min_ + i * step_;
    x_.push_back(x);
    y_.push_back(x * x);
  }
}
