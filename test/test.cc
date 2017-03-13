/*
 * test.cc
 * Copyright (C) 2017 zhangyule <zyl2336709@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#define public public
#define private public
#define protected public

#include "gtest/gtest.h"
#include "../include/beta_generator_test.h"


int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
