#ifndef WHT_LISTENER_H_
#define  WHT_LISTENER_H_

namespace wht{
  class Listener {
  public:
    virtual ~Listener() = default;
    virtual void wht_listener_on_update() = 0;
  };
} // namespace wht

#endif // ! WHT_LISTENER_H_
