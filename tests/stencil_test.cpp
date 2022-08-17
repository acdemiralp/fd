#include "doctest/doctest.h"

#include <fd/all.hpp>

TEST_CASE("stencil")
{
  {
    auto stencil1 = fd::make_forward_stencil<float, 1>();
    auto stencil2 = fd::make_forward_stencil<float, 2>();
    auto stencil3 = fd::make_forward_stencil<float, 3>();
    auto stencil4 = fd::make_forward_stencil<float, 4>();
    auto stencil5 = fd::make_forward_stencil<float, 5>();

    auto control1 = std::array {0.0f                        };
    auto control2 = std::array {0.0f, 1.0f                  };
    auto control3 = std::array {0.0f, 1.0f, 2.0f            };
    auto control4 = std::array {0.0f, 1.0f, 2.0f, 3.0f      };
    auto control5 = std::array {0.0f, 1.0f, 2.0f, 3.0f, 4.0f};

    REQUIRE(stencil1 == control1);
    REQUIRE(stencil2 == control2);
    REQUIRE(stencil3 == control3);
    REQUIRE(stencil4 == control4);
    REQUIRE(stencil5 == control5);
  }
  
  {
    auto stencil1 = fd::make_backward_stencil<float, 1>();
    auto stencil2 = fd::make_backward_stencil<float, 2>();
    auto stencil3 = fd::make_backward_stencil<float, 3>();
    auto stencil4 = fd::make_backward_stencil<float, 4>();
    auto stencil5 = fd::make_backward_stencil<float, 5>();

    auto control1 = std::array {                            0.0f};
    auto control2 = std::array {                     -1.0f, 0.0f};
    auto control3 = std::array {              -2.0f, -1.0f, 0.0f};
    auto control4 = std::array {       -3.0f, -2.0f, -1.0f, 0.0f};
    auto control5 = std::array {-4.0f, -3.0f, -2.0f, -1.0f, 0.0f};

    REQUIRE(stencil1 == control1);
    REQUIRE(stencil2 == control2);
    REQUIRE(stencil3 == control3);
    REQUIRE(stencil4 == control4);
    REQUIRE(stencil5 == control5);
  }
  
  {
    auto stencil1 = fd::make_central_stencil<float, 1>();
    auto stencil2 = fd::make_central_stencil<float, 2>();
    auto stencil3 = fd::make_central_stencil<float, 3>();
    auto stencil4 = fd::make_central_stencil<float, 4>();
    auto stencil5 = fd::make_central_stencil<float, 5>();

    auto control1 = std::array {              0.0f              };
    auto control2 = std::array {          -0.5f, +0.5f          };
    auto control3 = std::array {       -1.0f, 0.0f, +1.0f       };
    auto control4 = std::array {   -1.5f, -0.5f, +0.5f, +1.5f   };
    auto control5 = std::array {-2.0f, -1.0f, 0.0f, +1.0f, +2.0f};

    REQUIRE(stencil1 == control1);
    REQUIRE(stencil2 == control2);
    REQUIRE(stencil3 == control3);
    REQUIRE(stencil4 == control4);
    REQUIRE(stencil5 == control5);
  }
}