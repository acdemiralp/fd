#include "doctest/doctest.h"

#define _USE_MATH_DEFINES
#include <cmath>

#include <fd/all.hpp>

TEST_CASE("finite_differences")
{
  constexpr auto f = [ ] (const float x) { return std::sin(x); };
  REQUIRE(fd::forward_difference <1>(f, static_cast<float>(0.0f              ), 0.001f) == doctest::Approx( std::cos(0.0f              )).epsilon(0.001));
  REQUIRE(fd::forward_difference <1>(f, static_cast<float>(M_PI * 1.0f / 4.0f), 0.001f) == doctest::Approx( std::cos(M_PI * 1.0f / 4.0f)).epsilon(0.001));
  REQUIRE(fd::forward_difference <1>(f, static_cast<float>(M_PI * 2.0f / 4.0f), 0.001f) == doctest::Approx( std::cos(M_PI * 2.0f / 4.0f)).epsilon(0.001));
  REQUIRE(fd::forward_difference <1>(f, static_cast<float>(M_PI * 3.0f / 4.0f), 0.001f) == doctest::Approx( std::cos(M_PI * 3.0f / 4.0f)).epsilon(0.001));
  REQUIRE(fd::forward_difference <1>(f, static_cast<float>(M_PI              ), 0.001f) == doctest::Approx( std::cos(M_PI              )).epsilon(0.001));

  REQUIRE(fd::backward_difference<1>(f, static_cast<float>(0.0f              ), 0.001f) == doctest::Approx( std::cos(0.0f              )).epsilon(0.001));
  REQUIRE(fd::backward_difference<1>(f, static_cast<float>(M_PI * 1.0f / 4.0f), 0.001f) == doctest::Approx( std::cos(M_PI * 1.0f / 4.0f)).epsilon(0.001));
  REQUIRE(fd::backward_difference<1>(f, static_cast<float>(M_PI * 2.0f / 4.0f), 0.001f) == doctest::Approx( std::cos(M_PI * 2.0f / 4.0f)).epsilon(0.001));
  REQUIRE(fd::backward_difference<1>(f, static_cast<float>(M_PI * 3.0f / 4.0f), 0.001f) == doctest::Approx( std::cos(M_PI * 3.0f / 4.0f)).epsilon(0.001));
  REQUIRE(fd::backward_difference<1>(f, static_cast<float>(M_PI              ), 0.001f) == doctest::Approx( std::cos(M_PI              )).epsilon(0.001));

  REQUIRE(fd::central_difference <1>(f, static_cast<float>(0.0f              ), 0.001f) == doctest::Approx( std::cos(0.0f              )).epsilon(0.001));
  REQUIRE(fd::central_difference <1>(f, static_cast<float>(M_PI * 1.0f / 4.0f), 0.001f) == doctest::Approx( std::cos(M_PI * 1.0f / 4.0f)).epsilon(0.001));
  REQUIRE(fd::central_difference <1>(f, static_cast<float>(M_PI * 2.0f / 4.0f), 0.001f) == doctest::Approx( std::cos(M_PI * 2.0f / 4.0f)).epsilon(0.001));
  REQUIRE(fd::central_difference <1>(f, static_cast<float>(M_PI * 3.0f / 4.0f), 0.001f) == doctest::Approx( std::cos(M_PI * 3.0f / 4.0f)).epsilon(0.001));
  REQUIRE(fd::central_difference <1>(f, static_cast<float>(M_PI              ), 0.001f) == doctest::Approx( std::cos(M_PI              )).epsilon(0.001));

  REQUIRE(fd::forward_difference    (f, static_cast<float>(0.0f              ), 0.001f) == doctest::Approx( std::cos(0.0f              )).epsilon(0.001));
  REQUIRE(fd::forward_difference    (f, static_cast<float>(M_PI * 1.0f / 4.0f), 0.001f) == doctest::Approx( std::cos(M_PI * 1.0f / 4.0f)).epsilon(0.001));
  REQUIRE(fd::forward_difference    (f, static_cast<float>(M_PI * 2.0f / 4.0f), 0.001f) == doctest::Approx( std::cos(M_PI * 2.0f / 4.0f)).epsilon(0.001));
  REQUIRE(fd::forward_difference    (f, static_cast<float>(M_PI * 3.0f / 4.0f), 0.001f) == doctest::Approx( std::cos(M_PI * 3.0f / 4.0f)).epsilon(0.001));
  REQUIRE(fd::forward_difference    (f, static_cast<float>(M_PI              ), 0.001f) == doctest::Approx( std::cos(M_PI              )).epsilon(0.001));

  REQUIRE(fd::backward_difference   (f, static_cast<float>(0.0f              ), 0.001f) == doctest::Approx( std::cos(0.0f              )).epsilon(0.001));
  REQUIRE(fd::backward_difference   (f, static_cast<float>(M_PI * 1.0f / 4.0f), 0.001f) == doctest::Approx( std::cos(M_PI * 1.0f / 4.0f)).epsilon(0.001));
  REQUIRE(fd::backward_difference   (f, static_cast<float>(M_PI * 2.0f / 4.0f), 0.001f) == doctest::Approx( std::cos(M_PI * 2.0f / 4.0f)).epsilon(0.001));
  REQUIRE(fd::backward_difference   (f, static_cast<float>(M_PI * 3.0f / 4.0f), 0.001f) == doctest::Approx( std::cos(M_PI * 3.0f / 4.0f)).epsilon(0.001));
  REQUIRE(fd::backward_difference   (f, static_cast<float>(M_PI              ), 0.001f) == doctest::Approx( std::cos(M_PI              )).epsilon(0.001));

  REQUIRE(fd::central_difference    (f, static_cast<float>(0.0f              ), 0.001f) == doctest::Approx( std::cos(0.0f              )).epsilon(0.001));
  REQUIRE(fd::central_difference    (f, static_cast<float>(M_PI * 1.0f / 4.0f), 0.001f) == doctest::Approx( std::cos(M_PI * 1.0f / 4.0f)).epsilon(0.001));
  REQUIRE(fd::central_difference    (f, static_cast<float>(M_PI * 2.0f / 4.0f), 0.001f) == doctest::Approx( std::cos(M_PI * 2.0f / 4.0f)).epsilon(0.001));
  REQUIRE(fd::central_difference    (f, static_cast<float>(M_PI * 3.0f / 4.0f), 0.001f) == doctest::Approx( std::cos(M_PI * 3.0f / 4.0f)).epsilon(0.001));
  REQUIRE(fd::central_difference    (f, static_cast<float>(M_PI              ), 0.001f) == doctest::Approx( std::cos(M_PI              )).epsilon(0.001));
}