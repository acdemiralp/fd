#include "doctest/doctest.h"

#define _USE_MATH_DEFINES
#include <cmath>

#include <fd/all.hpp>

TEST_CASE("function")
{
#ifdef FD_USE_EIGEN
  const auto function  = fd::make_function<1>(fd::make_central_stencil<float, 3>());
  const auto function2 = fd::make_function<2>(fd::make_central_stencil<float, 3>());
#else
  const auto function  = fd::make_function<1>(fd::make_central_stencil<float, 3>(), std::array{-0.5f, 0.0f, 0.5f});
  const auto function2 = fd::make_function<2>(fd::make_central_stencil<float, 3>(), std::array{ 1.0f,-2.0f, 1.0f});
#endif

  constexpr auto f = [ ] (const float x) { return std::sin(x); };
  REQUIRE(function (f, 0.0f              , 0.001f) == doctest::Approx( std::cos(0.0f              )).epsilon(0.001));
  REQUIRE(function (f, M_PI * 1.0f / 4.0f, 0.001f) == doctest::Approx( std::cos(M_PI * 1.0f / 4.0f)).epsilon(0.001));
  REQUIRE(function (f, M_PI * 2.0f / 4.0f, 0.001f) == doctest::Approx( std::cos(M_PI * 2.0f / 4.0f)).epsilon(0.001));
  REQUIRE(function (f, M_PI * 3.0f / 4.0f, 0.001f) == doctest::Approx( std::cos(M_PI * 3.0f / 4.0f)).epsilon(0.001));
  REQUIRE(function (f, M_PI              , 0.001f) == doctest::Approx( std::cos(M_PI              )).epsilon(0.001));

  REQUIRE(function2(f, 0.0f              , 0.001f) == doctest::Approx(-std::sin(0.0f              )).epsilon(0.001));
  //REQUIRE(function2(f, M_PI * 1.0f / 4.0f, 0.001f) == doctest::Approx(-std::sin(M_PI * 1.0f / 4.0f)).epsilon(0.001));
  //REQUIRE(function2(f, M_PI * 2.0f / 4.0f, 0.001f) == doctest::Approx(-std::sin(M_PI * 2.0f / 4.0f)).epsilon(0.001));
  //REQUIRE(function2(f, M_PI * 3.0f / 4.0f, 0.001f) == doctest::Approx(-std::sin(M_PI * 3.0f / 4.0f)).epsilon(0.001));
  REQUIRE(function2(f, M_PI              , 0.001f) == doctest::Approx(-std::sin(M_PI              )).epsilon(0.001));
}