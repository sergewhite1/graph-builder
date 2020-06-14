#include "graph_view_model.h"

GraphViewModel::GraphViewModel(std::unique_ptr<GraphModel> graph_model)
  : graph_model_(std::move(graph_model)) {

  //TODO: format output of double variables
  x_min_str_ = std::to_string(graph_model_->x_min());
  x_max_str_ = std::to_string(graph_model_->x_max());
  step_str_ = std::to_string(graph_model_->step());
}
