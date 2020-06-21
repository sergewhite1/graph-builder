#include "listenable.h"

#include <algorithm>

#include "listener.h"

namespace wht {

void Listenable::wht_reg_listener(Listener * listener) {
  if(!wht_is_reg(listener)) {
    wht_listeners_.push_back(listener);
  }
}

void Listenable::wht_unreg_listener(Listener * listener) {
 wht_listeners_.remove(listener);
}

bool Listenable::wht_is_reg(const Listener * listener) {
  return std::find(
                   wht_listeners_.cbegin(),
                   wht_listeners_.cend(),
                   listener) != wht_listeners_.cend();
}

void Listenable::wht_notify_listeners() {
  for (auto& l : wht_listeners_) {
    l->wht_listener_on_update();
  }
}

} // namespace wht
