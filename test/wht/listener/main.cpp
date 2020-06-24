#include <iostream>

#include "wht/listener/listenable.h"
#include "wht/listener/listener.h"

typedef int (*UnitTestProc)();

class TestListenable : public wht::Listenable {
public:
  void do_something() {
    wht_notify_listeners();
  }
};

class TestListener : public wht::Listener {
public:
  // wht::Listener interface
  virtual void wht_listener_on_update() override {
    ++x;
  }

  int x = 0;
};

static int UnitTest1() {
  // Standard Flow

  TestListenable testListenable;
  TestListener testListener;

  if (testListenable.wht_is_reg(&testListener) == true) {
    return 1;
  }

  testListenable.wht_reg_listener(&testListener);

  if (testListenable.wht_is_reg(&testListener) == false) {
    return 1;
  }

  testListenable.do_something();

  if (testListener.x != 1) {
    return 1;
  }

  return 0;
}

static int UnitTest2() {
  // Register one listener many times

  TestListenable testListenable;
  TestListener testListener;

  testListenable.wht_reg_listener(&testListener);
  testListenable.wht_reg_listener(&testListener);

  testListenable.do_something();

  if (testListener.x != 1) {
    return 1;
  }

  return 0;
}

static int UnitTest3() {
  // Unreg listener

  TestListenable testListenable;
  TestListener testListener;

  testListenable.wht_reg_listener(&testListener);
  testListenable.wht_unreg_listener(&testListener);

  testListenable.do_something();

  if (testListener.x != 0) {
    return 1;
  }

  return 0;
}

static int UnitTest4() {
  // Unreg listener from middle

  TestListenable testListenable;
  TestListener testListenerA, testListenerB, testListenerC;

  testListenable.wht_reg_listener(&testListenerA);
  testListenable.wht_reg_listener(&testListenerB);
  testListenable.wht_reg_listener(&testListenerC);

  testListenable.do_something();

  if (((testListenerA.x == 1) &&
       (testListenerB.x == 1) &&
       (testListenerC.x == 1)) == false) {
    return 1;
  }

  testListenable.wht_unreg_listener(&testListenerB);

  testListenable.do_something();

  if (((testListenerA.x == 2) &&
       (testListenerB.x == 1) &&
       (testListenerC.x == 2)) == false) {
    return 1;
  }


  return 0;
}

static const UnitTestProc UNIT_TESTS[] = {nullptr, UnitTest1, UnitTest2,
  UnitTest3, UnitTest4};

int main(int argc, const char* argv[]) {
  if (argc < 2) {
    std::cout << "Error! No test case number in command line arg!";
    return 1;
  }

  return UNIT_TESTS[atoi(argv[1])]();
}
