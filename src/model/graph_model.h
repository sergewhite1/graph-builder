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

  size_t pointCount() const;

  double x(size_t index) const {
    return x_.at(index);
  }

  double y(size_t index) const {
    return y_.at(index);
  }

  void Update();

private:
  double x_min_ = -4.0;
  double x_max_ = 4.0;
  double step_ = 0.01;
  std::vector<double> x_;
  std::vector<double> y_;
};

#endif // ! GRAPH_MODEL_H_
