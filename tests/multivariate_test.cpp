#include "doctest/doctest.h"

#ifdef FD_USE_EIGEN
#include <Eigen/Core>
#endif

#include <fd/all.hpp>

#ifdef FD_USE_EIGEN
TEST_CASE("multivariate")
{
  {
    REQUIRE(fd::make_von_neumann_stencil<float, 1, 1>()[0 ] == std::array<float, 1>{ 0.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 1, 1>()[1 ] == std::array<float, 1>{-1.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 1, 1>()[2 ] == std::array<float, 1>{ 1.0f});

    REQUIRE(fd::make_von_neumann_stencil<float, 2, 1>()[0 ] == std::array<float, 2>{ 0.0f,  0.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 2, 1>()[1 ] == std::array<float, 2>{-1.0f,  0.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 2, 1>()[2 ] == std::array<float, 2>{ 1.0f,  0.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 2, 1>()[3 ] == std::array<float, 2>{ 0.0f, -1.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 2, 1>()[4 ] == std::array<float, 2>{ 0.0f,  1.0f});

    REQUIRE(fd::make_von_neumann_stencil<float, 3, 1>()[0 ] == std::array<float, 3>{ 0.0f,  0.0f,  0.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 3, 1>()[1 ] == std::array<float, 3>{-1.0f,  0.0f,  0.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 3, 1>()[2 ] == std::array<float, 3>{ 1.0f,  0.0f,  0.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 3, 1>()[3 ] == std::array<float, 3>{ 0.0f, -1.0f,  0.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 3, 1>()[4 ] == std::array<float, 3>{ 0.0f,  1.0f,  0.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 3, 1>()[5 ] == std::array<float, 3>{ 0.0f,  0.0f, -1.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 3, 1>()[6 ] == std::array<float, 3>{ 0.0f,  0.0f,  1.0f});

    REQUIRE(fd::make_von_neumann_stencil<float, 1, 2>()[0 ] == std::array<float, 1>{ 0.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 1, 2>()[1 ] == std::array<float, 1>{-2.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 1, 2>()[2 ] == std::array<float, 1>{-1.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 1, 2>()[3 ] == std::array<float, 1>{ 1.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 1, 2>()[4 ] == std::array<float, 1>{ 2.0f});

    REQUIRE(fd::make_von_neumann_stencil<float, 2, 2>()[0 ] == std::array<float, 2>{ 0.0f,  0.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 2, 2>()[1 ] == std::array<float, 2>{-2.0f,  0.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 2, 2>()[2 ] == std::array<float, 2>{-1.0f,  0.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 2, 2>()[3 ] == std::array<float, 2>{ 1.0f,  0.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 2, 2>()[4 ] == std::array<float, 2>{ 2.0f,  0.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 2, 2>()[5 ] == std::array<float, 2>{ 0.0f, -2.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 2, 2>()[6 ] == std::array<float, 2>{ 0.0f, -1.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 2, 2>()[7 ] == std::array<float, 2>{ 0.0f,  1.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 2, 2>()[8 ] == std::array<float, 2>{ 0.0f,  2.0f});

    REQUIRE(fd::make_von_neumann_stencil<float, 3, 2>()[0 ] == std::array<float, 3>{ 0.0f,  0.0f,  0.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 3, 2>()[1 ] == std::array<float, 3>{-2.0f,  0.0f,  0.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 3, 2>()[2 ] == std::array<float, 3>{-1.0f,  0.0f,  0.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 3, 2>()[3 ] == std::array<float, 3>{ 1.0f,  0.0f,  0.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 3, 2>()[4 ] == std::array<float, 3>{ 2.0f,  0.0f,  0.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 3, 2>()[5 ] == std::array<float, 3>{ 0.0f, -2.0f,  0.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 3, 2>()[6 ] == std::array<float, 3>{ 0.0f, -1.0f,  0.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 3, 2>()[7 ] == std::array<float, 3>{ 0.0f,  1.0f,  0.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 3, 2>()[8 ] == std::array<float, 3>{ 0.0f,  2.0f,  0.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 3, 2>()[9 ] == std::array<float, 3>{ 0.0f,  0.0f, -2.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 3, 2>()[10] == std::array<float, 3>{ 0.0f,  0.0f, -1.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 3, 2>()[11] == std::array<float, 3>{ 0.0f,  0.0f,  1.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 3, 2>()[12] == std::array<float, 3>{ 0.0f,  0.0f,  2.0f});

    REQUIRE(fd::make_von_neumann_stencil<float, 1, 3>()[0 ] == std::array<float, 1>{ 0.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 1, 3>()[1 ] == std::array<float, 1>{-3.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 1, 3>()[2 ] == std::array<float, 1>{-2.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 1, 3>()[3 ] == std::array<float, 1>{-1.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 1, 3>()[4 ] == std::array<float, 1>{ 1.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 1, 3>()[5 ] == std::array<float, 1>{ 2.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 1, 3>()[6 ] == std::array<float, 1>{ 3.0f});

    REQUIRE(fd::make_von_neumann_stencil<float, 2, 3>()[0 ] == std::array<float, 2>{ 0.0f,  0.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 2, 3>()[1 ] == std::array<float, 2>{-3.0f,  0.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 2, 3>()[2 ] == std::array<float, 2>{-2.0f,  0.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 2, 3>()[3 ] == std::array<float, 2>{-1.0f,  0.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 2, 3>()[4 ] == std::array<float, 2>{ 1.0f,  0.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 2, 3>()[5 ] == std::array<float, 2>{ 2.0f,  0.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 2, 3>()[6 ] == std::array<float, 2>{ 3.0f,  0.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 2, 3>()[7 ] == std::array<float, 2>{ 0.0f, -3.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 2, 3>()[8 ] == std::array<float, 2>{ 0.0f, -2.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 2, 3>()[9 ] == std::array<float, 2>{ 0.0f, -1.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 2, 3>()[10] == std::array<float, 2>{ 0.0f,  1.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 2, 3>()[11] == std::array<float, 2>{ 0.0f,  2.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 2, 3>()[12] == std::array<float, 2>{ 0.0f,  3.0f});

    REQUIRE(fd::make_von_neumann_stencil<float, 3, 3>()[0 ] == std::array<float, 3>{ 0.0f,  0.0f,  0.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 3, 3>()[1 ] == std::array<float, 3>{-3.0f,  0.0f,  0.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 3, 3>()[2 ] == std::array<float, 3>{-2.0f,  0.0f,  0.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 3, 3>()[3 ] == std::array<float, 3>{-1.0f,  0.0f,  0.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 3, 3>()[4 ] == std::array<float, 3>{ 1.0f,  0.0f,  0.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 3, 3>()[5 ] == std::array<float, 3>{ 2.0f,  0.0f,  0.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 3, 3>()[6 ] == std::array<float, 3>{ 3.0f,  0.0f,  0.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 3, 3>()[7 ] == std::array<float, 3>{ 0.0f, -3.0f,  0.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 3, 3>()[8 ] == std::array<float, 3>{ 0.0f, -2.0f,  0.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 3, 3>()[9 ] == std::array<float, 3>{ 0.0f, -1.0f,  0.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 3, 3>()[10] == std::array<float, 3>{ 0.0f,  1.0f,  0.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 3, 3>()[11] == std::array<float, 3>{ 0.0f,  2.0f,  0.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 3, 3>()[12] == std::array<float, 3>{ 0.0f,  3.0f,  0.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 3, 3>()[13] == std::array<float, 3>{ 0.0f,  0.0f, -3.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 3, 3>()[14] == std::array<float, 3>{ 0.0f,  0.0f, -2.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 3, 3>()[15] == std::array<float, 3>{ 0.0f,  0.0f, -1.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 3, 3>()[16] == std::array<float, 3>{ 0.0f,  0.0f,  1.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 3, 3>()[17] == std::array<float, 3>{ 0.0f,  0.0f,  2.0f});
    REQUIRE(fd::make_von_neumann_stencil<float, 3, 3>()[18] == std::array<float, 3>{ 0.0f,  0.0f,  3.0f});
  }

  {
    REQUIRE(fd::make_moore_stencil      <float, 1, 1>()[0 ] == std::array<float, 1>{ 0.0f});

    REQUIRE(fd::make_moore_stencil      <float, 2, 1>()[0 ] == std::array<float, 2>{ 0.0f,  0.0f});

    REQUIRE(fd::make_moore_stencil      <float, 3, 1>()[0 ] == std::array<float, 3>{ 0.0f,  0.0f,  0.0f});

    REQUIRE(fd::make_moore_stencil      <float, 1, 2>()[0 ] == std::array<float, 1>{-0.5f});
    REQUIRE(fd::make_moore_stencil      <float, 1, 2>()[1 ] == std::array<float, 1>{ 0.5f});

    REQUIRE(fd::make_moore_stencil      <float, 2, 2>()[0 ] == std::array<float, 2>{-0.5f, -0.5f});
    REQUIRE(fd::make_moore_stencil      <float, 2, 2>()[1 ] == std::array<float, 2>{-0.5f,  0.5f});
    REQUIRE(fd::make_moore_stencil      <float, 2, 2>()[2 ] == std::array<float, 2>{ 0.5f, -0.5f});
    REQUIRE(fd::make_moore_stencil      <float, 2, 2>()[3 ] == std::array<float, 2>{ 0.5f,  0.5f});

    REQUIRE(fd::make_moore_stencil      <float, 3, 2>()[0 ] == std::array<float, 3>{-0.5f, -0.5f, -0.5f});
    REQUIRE(fd::make_moore_stencil      <float, 3, 2>()[1 ] == std::array<float, 3>{-0.5f, -0.5f,  0.5f});
    REQUIRE(fd::make_moore_stencil      <float, 3, 2>()[2 ] == std::array<float, 3>{-0.5f,  0.5f, -0.5f});
    REQUIRE(fd::make_moore_stencil      <float, 3, 2>()[3 ] == std::array<float, 3>{-0.5f,  0.5f,  0.5f});
    REQUIRE(fd::make_moore_stencil      <float, 3, 2>()[4 ] == std::array<float, 3>{ 0.5f, -0.5f, -0.5f});
    REQUIRE(fd::make_moore_stencil      <float, 3, 2>()[5 ] == std::array<float, 3>{ 0.5f, -0.5f,  0.5f});
    REQUIRE(fd::make_moore_stencil      <float, 3, 2>()[6 ] == std::array<float, 3>{ 0.5f,  0.5f, -0.5f});
    REQUIRE(fd::make_moore_stencil      <float, 3, 2>()[7 ] == std::array<float, 3>{ 0.5f,  0.5f,  0.5f});

    REQUIRE(fd::make_moore_stencil      <float, 1, 3>()[0 ] == std::array<float, 1>{-1.0f});
    REQUIRE(fd::make_moore_stencil      <float, 1, 3>()[1 ] == std::array<float, 1>{ 0.0f});
    REQUIRE(fd::make_moore_stencil      <float, 1, 3>()[2 ] == std::array<float, 1>{ 1.0f});

    REQUIRE(fd::make_moore_stencil      <float, 2, 3>()[0 ] == std::array<float, 2>{-1.0f, -1.0f});
    REQUIRE(fd::make_moore_stencil      <float, 2, 3>()[1 ] == std::array<float, 2>{-1.0f,  0.0f});
    REQUIRE(fd::make_moore_stencil      <float, 2, 3>()[2 ] == std::array<float, 2>{-1.0f,  1.0f});
    REQUIRE(fd::make_moore_stencil      <float, 2, 3>()[3 ] == std::array<float, 2>{ 0.0f, -1.0f});
    REQUIRE(fd::make_moore_stencil      <float, 2, 3>()[4 ] == std::array<float, 2>{ 0.0f,  0.0f});
    REQUIRE(fd::make_moore_stencil      <float, 2, 3>()[5 ] == std::array<float, 2>{ 0.0f,  1.0f});
    REQUIRE(fd::make_moore_stencil      <float, 2, 3>()[6 ] == std::array<float, 2>{ 1.0f, -1.0f});
    REQUIRE(fd::make_moore_stencil      <float, 2, 3>()[7 ] == std::array<float, 2>{ 1.0f,  0.0f});
    REQUIRE(fd::make_moore_stencil      <float, 2, 3>()[8 ] == std::array<float, 2>{ 1.0f,  1.0f});

    REQUIRE(fd::make_moore_stencil      <float, 3, 3>()[0 ] == std::array<float, 3>{-1.0f, -1.0f, -1.0f});
    REQUIRE(fd::make_moore_stencil      <float, 3, 3>()[1 ] == std::array<float, 3>{-1.0f, -1.0f,  0.0f});
    REQUIRE(fd::make_moore_stencil      <float, 3, 3>()[2 ] == std::array<float, 3>{-1.0f, -1.0f,  1.0f});
    REQUIRE(fd::make_moore_stencil      <float, 3, 3>()[3 ] == std::array<float, 3>{-1.0f,  0.0f, -1.0f});
    REQUIRE(fd::make_moore_stencil      <float, 3, 3>()[4 ] == std::array<float, 3>{-1.0f,  0.0f,  0.0f});
    REQUIRE(fd::make_moore_stencil      <float, 3, 3>()[5 ] == std::array<float, 3>{-1.0f,  0.0f,  1.0f});
    REQUIRE(fd::make_moore_stencil      <float, 3, 3>()[6 ] == std::array<float, 3>{-1.0f,  1.0f, -1.0f});
    REQUIRE(fd::make_moore_stencil      <float, 3, 3>()[7 ] == std::array<float, 3>{-1.0f,  1.0f,  0.0f});
    REQUIRE(fd::make_moore_stencil      <float, 3, 3>()[8 ] == std::array<float, 3>{-1.0f,  1.0f,  1.0f});
    REQUIRE(fd::make_moore_stencil      <float, 3, 3>()[9 ] == std::array<float, 3>{ 0.0f, -1.0f, -1.0f});
    REQUIRE(fd::make_moore_stencil      <float, 3, 3>()[10] == std::array<float, 3>{ 0.0f, -1.0f,  0.0f});
    REQUIRE(fd::make_moore_stencil      <float, 3, 3>()[11] == std::array<float, 3>{ 0.0f, -1.0f,  1.0f});
    REQUIRE(fd::make_moore_stencil      <float, 3, 3>()[12] == std::array<float, 3>{ 0.0f,  0.0f, -1.0f});
    REQUIRE(fd::make_moore_stencil      <float, 3, 3>()[13] == std::array<float, 3>{ 0.0f,  0.0f,  0.0f});
    REQUIRE(fd::make_moore_stencil      <float, 3, 3>()[14] == std::array<float, 3>{ 0.0f,  0.0f,  1.0f});
    REQUIRE(fd::make_moore_stencil      <float, 3, 3>()[15] == std::array<float, 3>{ 0.0f,  1.0f, -1.0f});
    REQUIRE(fd::make_moore_stencil      <float, 3, 3>()[16] == std::array<float, 3>{ 0.0f,  1.0f,  0.0f});
    REQUIRE(fd::make_moore_stencil      <float, 3, 3>()[17] == std::array<float, 3>{ 0.0f,  1.0f,  1.0f});
    REQUIRE(fd::make_moore_stencil      <float, 3, 3>()[18] == std::array<float, 3>{ 1.0f, -1.0f, -1.0f});
    REQUIRE(fd::make_moore_stencil      <float, 3, 3>()[19] == std::array<float, 3>{ 1.0f, -1.0f,  0.0f});
    REQUIRE(fd::make_moore_stencil      <float, 3, 3>()[20] == std::array<float, 3>{ 1.0f, -1.0f,  1.0f});
    REQUIRE(fd::make_moore_stencil      <float, 3, 3>()[21] == std::array<float, 3>{ 1.0f,  0.0f, -1.0f});
    REQUIRE(fd::make_moore_stencil      <float, 3, 3>()[22] == std::array<float, 3>{ 1.0f,  0.0f,  0.0f});
    REQUIRE(fd::make_moore_stencil      <float, 3, 3>()[23] == std::array<float, 3>{ 1.0f,  0.0f,  1.0f});
    REQUIRE(fd::make_moore_stencil      <float, 3, 3>()[24] == std::array<float, 3>{ 1.0f,  1.0f, -1.0f});
    REQUIRE(fd::make_moore_stencil      <float, 3, 3>()[25] == std::array<float, 3>{ 1.0f,  1.0f,  0.0f});
    REQUIRE(fd::make_moore_stencil      <float, 3, 3>()[26] == std::array<float, 3>{ 1.0f,  1.0f,  1.0f});
  }
}
#endif