/*
 * beta_generator.h
 * Copyright (C) 2017 zhangyule <zyl2336709@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef BETA_GENERATOR_H
#define BETA_GENERATOR_H

#include <time.h>
#include <stdlib.h>
#include <math.h>

namespace bandit {
template <typename T> struct Generator;

template <int base, int val>
struct Float {
  static const int Base = base;
  static const int Value = val;
};

template <typename T> struct Generator;

template <int a, int base> struct Const;
template <int a1, int a2, int base> struct Alpha;
template <int a1, int a2, int base> struct Beta;
template <int a1, int a2, int base> struct Gauss;
template <int a1, int a2, int base> struct Uniform;

template <int a, int base>
struct Generator<Const<a, base>> {
  float operator()() const {
    return (float)a / base;
  }
};

template <int a1, int a2, int base>
struct Generator<Uniform<a1, a2, base>> {
  using P1 = Float<a1, base>;
  using P2 = Float<a2, base>;
  float operator()() const {
    srand(time(NULL));
    const float low = (float)P1::Value / P1::Base;
    const float up  = (float)P2::Value / P2::Base;
    return rand() / RAND_MAX * (up - low) + (low + up) / 2;
  }
};

using z01uni = Generator<Uniform<0, 1, 1>>;

template <int a1, int a2, int base>
struct Generator<Beta<a1, a2, base>> {

  using P1 = Float<a1, base>;
  using P2 = Float<a2, base>;

  static float Alpha() {
    return (float)a1 / base;
  }
  static float Beta() {
    return (float)a2 / base;
  }

  float operator()() const {
    const float alpha = (float)a1 / base;
    const float beta = (float)a2 / base;
    float x;
    float y;
    do {
      x = pow(z01uni()(), alpha);
      y = pow(z01uni()(), beta);
    } while (x + y > 1);
    return x / (x + y);
  }
};

}


#endif /* !BETA_GENERATOR_H */
