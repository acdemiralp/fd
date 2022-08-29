#pragma once

#include <array>
#include <cstddef>

#include <fd/utility/array.hpp>
#include <fd/utility/constexpr_for.hpp>
#include <fd/utility/indexing.hpp>
#include <fd/utility/permute_for.hpp>
#include <fd/utility/pow.hpp>

namespace fd
{
template <typename type, std::size_t dimensions, std::size_t length = 1>
constexpr std::array<std::array<type, dimensions>, 2 * dimensions * length + 1>            make_von_neumann_stencil() // Cross stencil in 2D.
{
  std::array<std::array<type, dimensions>, 2 * dimensions * length + 1> result {};
  constexpr_for<0, dimensions, 1>([&result] (const auto dimension)
  {
    constexpr static std::size_t offset(2 * dimension.value * length + 1);
    constexpr_for<0, 2 * length, 1>([&result, &dimension] (const auto sample)
    {
      constexpr static std::size_t index(offset + sample.value);
      if constexpr (sample.value < length)
        std::get<dimension.value>(std::get<index>(result)) = static_cast<type>(sample.value) - length;
      else
        std::get<dimension.value>(std::get<index>(result)) = sample.value % length + 1;
    });
  });
  return result;
}
template <typename type, std::size_t dimensions, std::size_t length = 1>
constexpr std::array<std::array<type, dimensions>, pow_v<std::size_t, length, dimensions>> make_moore_stencil      () // Square stencil in 2D.
{
  std::array<std::array<type, dimensions>, pow_v<std::size_t, length, dimensions>> result {};

  constexpr std::array<type, dimensions> begin     = make_filled_array<type, dimensions, 0     >();
  constexpr std::array<type, dimensions> end       = make_filled_array<type, dimensions, length>();
  constexpr std::array<type, dimensions> increment = make_filled_array<type, dimensions, 1     >();
  permute_for<type, dimensions, begin, end, increment>([&result] (const std::array<type, dimensions>& index)
  {
    auto& value = result[ravel_multi_index(index, end)];
    constexpr_for<0, dimensions, 1>([&value, &index] (const auto i)
    {
      std::get<i.value>(value) = std::get<i.value>(index) - length / 2;
      if constexpr (length % 2 == 0)
        std::get<i.value>(value) += static_cast<type>(0.5);
    });
  });

  return result;
}
// TODO: More stencils. Rotated von Neumann, R-radial, R-axial, ...



// TODO Multivariate coefficients.
// TODO Multivariate functions.
// TODO Multivariate finite differences.
}