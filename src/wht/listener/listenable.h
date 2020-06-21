#ifndef WHT_LISTENABLE_H_
#define WHT_LISTENABLE_H_

#include <list>

namespace wht {
  class Listener;

  class Listenable {
  public:
    virtual ~Listenable() = default;

    void wht_reg_listener(Listener*);
    void wht_unreg_listener(Listener*);
    bool wht_is_reg(const Listener*);

  protected:
    void wht_notify_listeners();

  public:
    std::list<Listener*> wht_listeners_;
  };
} // namespace wht

#endif // ! WHT_LISTENABLE_H_

