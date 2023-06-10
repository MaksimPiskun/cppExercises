#include <gtest/gtest.h>
#include "test.hpp"

struct Impl
{
  int number = -1;
};

void TestClass::Set(int num)
{
  pimpl->number = num;
}

int TestClass::Get()
{
  return pimpl->number;
}


TEST(SimplyTest, BasicAssertions)
{
  TestClass t;
  EXPECT_EQ(t.Get(), -1);
  t.Set(11);
  EXPECT_EQ(t.Get(), 11);
}
