#include "graph_view_model.h"

GraphViewModel::GraphViewModel(std::unique_ptr<GraphModel> graph_model)
  : graph_model_(std::move(graph_model)) {

  //TODO: format output of double variables
  x_min_str_ = std::to_string(graph_model_->x_min());
  x_max_str_ = std::to_string(graph_model_->x_max());
  step_str_ = std::to_string(graph_model_->step());

  need_update_ = graph_model_->need_update();
}


void GraphViewModel::set_x_min_str(const std::string& value) {
  if (x_min_str_ != value) {
    x_min_str_ = value;
    need_update_ = true;
    notify_listeners();
  }
}

void GraphViewModel::set_x_max_str(const std::string& value) {
  if (x_max_str_ != value) {
    x_max_str_ = value;
    need_update_ = true;
    notify_listeners();
  }

}

void GraphViewModel::update() {
  if (need_update_) {
    graph_model_->set_x_min(std::stod(x_min_str_));
    graph_model_->set_x_max(std::stod(x_max_str_));
    graph_model_->update();
    need_update_ = false;
    notify_listeners();
  }

}
