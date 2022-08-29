#pragma once

#include <algorithm>
#include <array>
#include <cstddef>

namespace fd
{
template <typename type, std::size_t dimensions, type value>
constexpr std::array<type, dimensions> make_filled_array()
{
  std::array<type, dimensions> result;
  std::fill(result.begin(), result.end(), value);
  return result;
}
}