#include "observable.h"

#include <algorithm>

#include "listener.h"

namespace wht {

void Observable::reg_listener(Listener * listener) {
  if(!is_reg(listener)) {
    listeners_.push_back(listener);
  }
}

void Observable::unreg_listener(Listener * listener) {
 listeners_.remove(listener);
}

bool Observable::is_reg(const Listener * listener) {
  return std::find(listeners_.cbegin(), listeners_.cend(), listener) != listeners_.cend();
}

void Observable::notify_listeners() {
  for (auto& l : listeners_) {
    l->wht_listener_on_update();
  }
}

} // namespace wht
