#pragma once

#include <array>
#include <cstddef>

#ifdef FD_USE_EIGEN
#include <Eigen/Dense>
#endif

#include <fd/utility/constexpr_for.hpp>
#include <fd/utility/factorial.hpp>

namespace fd
{
#ifdef FD_USE_EIGEN
// Computes the finite difference coefficients for arbitrary derivative orders and stencils.
// Reference: https://web.media.mit.edu/~crtaylor/calculator.html
template <std::size_t order, typename type, std::size_t size>
constexpr std::array<type, size> make_coefficients(const std::array<type, size>& stencil)
{
  static_assert(order < size, "Order must be less than stencil size.");

  using matrix_type = Eigen::Matrix<type, size, size>;
  using vector_type = Eigen::Matrix<type, size, 1>;

  matrix_type matrix;
  vector_type vector;
  constexpr_for<0, size, 1>([&] (auto i)
  {
    matrix.row(i.value) = vector_type::Map(stencil.data()).array().pow(i.value);

    if constexpr (i.value == order)
      vector[i.value] = static_cast<type>(factorial_v<std::size_t, order>);
    else
      vector[i.value] = static_cast<type>(0);
  });

  std::array<type, size> result {};
  vector_type::Map(result.data()) = matrix.inverse() * vector;
  return result;
}
#endif
}