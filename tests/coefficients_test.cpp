#include "doctest/doctest.h"

#include <fd/all.hpp>

#ifdef FD_USE_EIGEN
TEST_CASE("coefficients")
{
  auto coefficients1 = fd::make_coefficients<1>(fd::make_forward_stencil <float, 2>());
  auto coefficients2 = fd::make_coefficients<2>(fd::make_forward_stencil <float, 3>());
  auto coefficients3 = fd::make_coefficients<1>(fd::make_backward_stencil<float, 2>());
  auto coefficients4 = fd::make_coefficients<2>(fd::make_backward_stencil<float, 3>());
  auto coefficients5 = fd::make_coefficients<1>(fd::make_central_stencil <float, 2>());
  auto coefficients6 = fd::make_coefficients<2>(fd::make_central_stencil <float, 3>());
  auto coefficients7 = fd::make_coefficients<1>(fd::make_central_stencil <float, 5>());
  auto coefficients8 = fd::make_coefficients<2>(fd::make_central_stencil <float, 5>());

  auto control1      = std::array {-1.0f,  1.0f      };
  auto control2      = std::array { 1.0f, -2.0f, 1.0f};
  auto control3      = std::array {-1.0f,  1.0f      };
  auto control4      = std::array { 1.0f, -2.0f, 1.0f};
  auto control5      = std::array {-1.0f,  1.0f      };
  auto control6      = std::array { 1.0f, -2.0f, 1.0f};
  auto control7      = std::array { 1.0f / 12.0f, -8.0f  / 12.0f,  0.0f         , 8.0f  / 12.0f, -1.0f / 12.0f};
  auto control8      = std::array {-1.0f / 12.0f,  16.0f / 12.0f, -30.0f / 12.0f, 16.0f / 12.0f, -1.0f / 12.0f};

  REQUIRE(coefficients1 == control1);
  REQUIRE(coefficients2 == control2);
  REQUIRE(coefficients3 == control3);
  REQUIRE(coefficients4 == control4);
  REQUIRE(coefficients5 == control5);
  REQUIRE(coefficients6 == control6);
  for (std::size_t i = 0; i < coefficients7.size(); ++i)
    REQUIRE(coefficients7[i] == doctest::Approx(control7[i]));
  for (std::size_t i = 0; i < coefficients8.size(); ++i)
    REQUIRE(coefficients8[i] == doctest::Approx(control8[i]));
}
#endif