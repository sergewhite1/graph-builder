#ifndef GRAPH_MODEL_H_
#define GRAPH_MODEL_H_

#include <cstdio>
#include <vector>

class GraphModel {
public:
  GraphModel();
 ~GraphModel() = default;

  double x_min() const {
    return x_min_;
  }

  double x_max() const {
    return x_max_;
  }

  double step() const {
    return step_;
  }

  double y_min() const {
    return y_min_;
  }

  double y_max() const {
    return y_max_;
  }

  size_t point_count() const;

  double x(size_t index) const {
    return x_.at(index);
  }

  double y(size_t index) const {
    return y_.at(index);
  }

  void set_x_min(double value);
  void set_x_max(double value);
  void set_step(double value);

  void update();

  bool need_update() const {
    return need_update_;
  }

private:
  double x_min_ = -4.0;
  double x_max_ = 4.0;
  double step_ = 0.01;
  double y_min_ = 0.0;
  double y_max_ = 0.0;
  std::vector<double> x_;
  std::vector<double> y_;
  bool need_update_ = true;
};

#endif // ! GRAPH_MODEL_H_
