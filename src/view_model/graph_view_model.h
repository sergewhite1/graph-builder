#ifndef GRAPH_VIEW_MODEL_H_
#define GRAPH_VIEW_MODEL_H_

#include <memory>

#include "model/graph_model.h"

class GraphViewModel {
public:
  explicit GraphViewModel(std::unique_ptr<GraphModel> graph_model);
  ~GraphViewModel() = default;

  double x_min() const {
    return graph_model_->x_min();
  }

  double x_max() const {
    return graph_model_->x_max();
  }

  double step() const {
    return graph_model_->step();
  }

  double y_min() const {
    return graph_model_->y_min();
  }

  double y_max() const {
    return graph_model_->y_max();
  }

  const std::string& x_min_str() const {
    return x_min_str_;
  }

  const std::string& x_max_str() const {
    return x_max_str_;
  }

  const std::string& step_str() const {
    return step_str_;
  }

  size_t pointCount() {
    return graph_model_->pointCount();
  }

  double x(size_t index) {
    return graph_model_->x(index);
  }

  double y(size_t index) {
    return graph_model_->y(index);
  }

private:
  std::unique_ptr<GraphModel> graph_model_;
  std::string x_min_str_;
  std::string x_max_str_;
  std::string step_str_;
};

#endif // !GRAPH_VIEW_MODEL_H_
