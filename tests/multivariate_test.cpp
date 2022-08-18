#include "doctest/doctest.h"

#ifdef FD_USE_EIGEN
#include <Eigen/Core>
#endif

#include <fd/all.hpp>

#ifdef FD_USE_EIGEN
TEST_CASE("multivariate")
{
  using vector2 = Eigen::Vector2f;
  using matrix2 = Eigen::Matrix2f;

  // Vector valued function of vector parameter.
  const auto f  = [ ] (const vector2& x)
  {
    return vector2(x[1], x[0]);
  };
  const auto x  = vector2(0.0f, 0.0f);
  const auto h  = vector2(1.0f, 1.0f);

  const auto fd = fd::forward_difference (f, x, h);
  const auto bd = fd::backward_difference(f, x, h);
  const auto cd = fd::central_difference (f, x, h);
}
#endif