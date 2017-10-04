#include "webLib/base_class/base_class.h"
#include "gtest/gtest.h"

TEST(BaseClassTest, basicTest) {
  auto bc = new BaseClass("x.txt");
  delete bc;
}
