#pragma once

#include <array>
#include <cstddef>

#include <fd/utility/constexpr_for.hpp>

namespace fd
{
// Note: Avoiding std::iota for GPU compatibility.
template <typename type, std::size_t size = 2>
constexpr std::array<type, size> make_forward_stencil ()
{
  std::array<type, size> result {};
  constexpr_for<0, size, 1>([&result] (const auto i)
  {
    std::get<i.value>(result) = static_cast<type>(i.value);
  });
  return result;
}
template <typename type, std::size_t size = 2>
constexpr std::array<type, size> make_backward_stencil()
{
  std::array<type, size> result {};
  const auto             offset = static_cast<type>(1) - static_cast<type>(size);
  constexpr_for<0, size, 1>([&result, offset] (const auto i)
  {
    std::get<i.value>(result) = static_cast<type>(i.value) + offset;
  });
  return result;
}
template <typename type, std::size_t size = 3>
constexpr std::array<type, size> make_central_stencil ()
{
  std::array<type, size> result {};
  const auto             offset = -static_cast<type>(size / 2);
  constexpr_for<0, size, 1>([&result, offset] (const auto i)
  {
    std::get<i.value>(result) = static_cast<type>(i.value) + offset;
    if constexpr (size % 2 == 0)
      std::get<i.value>(result) += static_cast<type>(0.5);
  });
  return result;
}
}