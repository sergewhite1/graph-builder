#include "graph_model.h"

#include <limits>

#include "wht/same_value.h"

GraphModel::GraphModel() {
  update();
}

size_t GraphModel::point_count() const {
  return static_cast<size_t>((x_max_ - x_min_) / step_);
}

void GraphModel::update() {

  if(!need_update_) {
    return;
  }

  // clear
  x_.clear();
  y_.clear();
  y_min_ = 0.0;
  y_max_ = 0.0;

  size_t pc = point_count();

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

  need_update_ = false;
}

void GraphModel::set_x_min(double value) {
  if (!wht::same_value(x_min_, value)) {
    x_min_ = value;
    need_update_ = true;
  }
}

void GraphModel::set_x_max(double value) {
  if (!wht::same_value(x_max_, value)) {
    x_max_ = value;
    need_update_ = true;
  }
}
