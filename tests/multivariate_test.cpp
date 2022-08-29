#include "doctest/doctest.h"

#ifdef FD_USE_EIGEN
#include <Eigen/Core>
#endif

#include <fd/all.hpp>

#ifdef FD_USE_EIGEN
TEST_CASE("multivariate")
{
  auto von_neumann_dim1_len1 = fd::make_von_neumann_stencil<std::int64_t, 1, 1>();
  auto von_neumann_dim2_len1 = fd::make_von_neumann_stencil<std::int64_t, 2, 1>();
  auto von_neumann_dim3_len1 = fd::make_von_neumann_stencil<std::int64_t, 3, 1>();
  auto von_neumann_dim1_len2 = fd::make_von_neumann_stencil<std::int64_t, 1, 2>();
  auto von_neumann_dim2_len2 = fd::make_von_neumann_stencil<std::int64_t, 2, 2>();
  auto von_neumann_dim3_len2 = fd::make_von_neumann_stencil<std::int64_t, 3, 2>();
  auto von_neumann_dim1_len3 = fd::make_von_neumann_stencil<std::int64_t, 1, 3>();
  auto von_neumann_dim2_len3 = fd::make_von_neumann_stencil<std::int64_t, 2, 3>();
  auto von_neumann_dim3_len3 = fd::make_von_neumann_stencil<std::int64_t, 3, 3>();

  auto moore_dim1_len1       = fd::make_moore_stencil      <std::int64_t, 1, 1>();
  auto moore_dim2_len1       = fd::make_moore_stencil      <std::int64_t, 2, 1>();
  auto moore_dim3_len1       = fd::make_moore_stencil      <std::int64_t, 3, 1>();
  auto moore_dim1_len2       = fd::make_moore_stencil      <std::int64_t, 1, 2>();
  auto moore_dim2_len2       = fd::make_moore_stencil      <std::int64_t, 2, 2>();
  auto moore_dim3_len2       = fd::make_moore_stencil      <std::int64_t, 3, 2>();
  auto moore_dim1_len3       = fd::make_moore_stencil      <std::int64_t, 1, 3>();
  auto moore_dim2_len3       = fd::make_moore_stencil      <std::int64_t, 2, 3>();
  auto moore_dim3_len3       = fd::make_moore_stencil      <std::int64_t, 3, 3>();
}
#endif