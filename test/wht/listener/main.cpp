#include <iostream>

typedef int (*UnitTestProc)();

static int UnitTest1() {
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
