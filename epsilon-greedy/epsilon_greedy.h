/*
 * epsilon_greedy.h
 * Copyright (C) 2017 zhangyule <zyl2336709@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef EPSILON_GREEDY_H
#define EPSILON_GREEDY_H

#include "../beta_generator.h"

namespace bandit {
template <int N>
struct EpsilonGreedyClosure {
  float epislon;
  // paly arms times
  std::vector<int> count(N);
  // average amount of reward
  std::vector<float> values(N);
};

template <int N>
class EpsilongGreedyAction {
  bool SelectArm(EpsilonGreedyClosure<N>* closure, int* selected) const {

  }
  bool Update(EpsilonGreedyClosure<N>* closure, int mostly_choosen_arm, float reward) const;
};
}

#endif /* !EPSILON_GREEDY_H */
