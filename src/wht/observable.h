#ifndef WHT_OBSERVABLE_H_
#define WHT_OBSERVABLE_H_

#include <list>

namespace wht {
  class Listener;

  class Observable {
  public:
    virtual ~Observable() = default;

    void reg_listener(Listener*);
    void unreg_listener(Listener*);
    bool is_reg(const Listener*);

  protected:
    void notify_listeners();

  public:
    std::list<Listener*> listeners_;
  };
} // namespace wht

#endif // ! WHT_OBSERVABLE_H_

