/*
 * beta_generator_test.h
 * Copyright (C) 2017 zhangyule <zyl2336709@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef BETA_GENERATOR_TEST_H
#define BETA_GENERATOR_TEST_H

#define public public
#define private public
#define protected public

#include "gtest/gtest.h"
#include "include/beta_generator.h"
#include <iostream>

using namespace std;

namespace bandit {
class BetaGenTest : public ::testing::Test {
  public:
    void SetUp() {}
    void TearDown() {}
};

TEST_F(BetaGenTest, ConstTest) {
  EXPECT_EQ((Generator<Const<1, 1>>()()), (1.0));
  EXPECT_EQ((Generator<Const<1, 10>>()()), (0.1));
}

TEST_F(BetaGenTest, UniformTest) {
  for (int i = 0; i < 10; ++i)
    std::cout << "0 1:" << z01uni()() << std::endl;
  for (int i = 0; i < 10; ++i)
    std::cout << "-10, 10:" << Generator<Uniform<-10, 10, 1>>()() << std::endl;
}

TEST_F(BetaGenTest, BetaTest) {
  auto k = Generator<Beta<1, 1, 1>>::Alpha();
  EXPECT_EQ(k, 1.0);
  EXPECT_EQ((Generator<Beta<1, 1, 1>>::Beta()), 1.0);
  for (int i = 0; i < 10; ++i)
    std::cout << "beta:" << Generator<Beta<10, 12, 1>>()() << std::endl;
}

}

#endif /* !BETA_GENERATOR_TEST_H */
