#include <iostream>

#include "wht/listener/listenable.h"
#include "wht/listener/listener.h"

typedef int (*UnitTestProc)();

class TestListenable : public wht::Listenable {
};

class TestListener : public wht::Listener {
public:
  // wht::Listener interface
  virtual void wht_listener_on_update() override {
  }
};

static int UnitTest1() {
  TestListenable testListenable;
  TestListener testListener;
  return 1;
}
static int UnitTest2() {
  return 1;
}

static const UnitTestProc UNIT_TESTS[] = {nullptr, UnitTest1, UnitTest2};

int main(int argc, const char* argv[]) {
  if (argc < 2) {
    std::cout << "Error! No test case number in command line arg!";
    return 1;
  }

  return UNIT_TESTS[atoi(argv[1])]();
}
