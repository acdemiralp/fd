#pragma once

#include <cstddef>
#include <cstdint>

#include <fd/utility/constexpr_for.hpp>

namespace fd
{
template <typename type, std::size_t size>
constexpr std::array<type, size> unravel_index    (std::size_t                   index      , const std::array<type, size>& dimensions)
{
  std::array<type, size> subscripts;
  constexpr_for<static_cast<std::int64_t>(size) - 1, -1, -1>([&] (const auto i)
  {
    std::get<i.value>(subscripts) = index % std::get<i.value>(dimensions);
    index                         = index / std::get<i.value>(dimensions);
  });
  return subscripts;
}
template <typename type>
constexpr type                   unravel_index    (std::size_t                   index      , const type&                   dimensions)
{
  type subscripts;
  for (std::int64_t i = dimensions.size() - 1; i >= 0; --i)
  {
    subscripts[i] = index % dimensions[i];
    index         = index / dimensions[i];
  }
  return subscripts;
}

template <typename type, std::size_t size>
constexpr std::size_t            ravel_multi_index(const std::array<type, size>& multi_index, const std::array<type, size>& dimensions)
{
  std::size_t index(0);
  constexpr_for<0, size, 1>([&] (const auto i)
  {
    index = index * std::get<i.value>(dimensions) + std::get<i.value>(multi_index);
  });
  return index;
}
template <typename type>
constexpr std::size_t            ravel_multi_index(const type&                   multi_index, const type&                   dimensions)
{
  std::size_t index(0);
  for (std::size_t i = 0; i < dimensions.size(); ++i)
    index = index * dimensions[i] + multi_index[i];
  return index;
}
}