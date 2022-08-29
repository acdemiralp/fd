#pragma once

#include <cstddef>

#include <fd/compatibility/cuda.hpp>
#include <fd/utility/constexpr_for.hpp>

namespace fd
{
// Compile-time version.
template <
  typename                     type      ,
  std::size_t                  dimensions,
  std::array<type, dimensions> begin     ,
  std::array<type, dimensions> end       ,
  std::array<type, dimensions> increment ,
  std::size_t                  depth     = 0>
constexpr void permute_for(const function<void(const std::array<type, dimensions>&)>& function, std::array<type, dimensions> indices = {})
{
  if constexpr (depth < dimensions)
  {
    constexpr_for<std::get<depth>(begin), std::get<depth>(end), std::get<depth>(increment)>([&] (const auto i)
    {
      std::get<depth>(indices) = i.value;
      permute_for<type, dimensions, begin, end, increment, depth + 1>(function, indices);
    });
  }
  else
    function(indices);
}

// Run-time version.
template <typename type>
constexpr void permute_for(
  const function<void(const type&)>& function , 
  const type&                        begin    ,
  const type&                        end      ,
  const type&                        increment,
  type                               indices  = {},
  std::size_t                        depth    = 0 )
{
  if (depth < begin.size())
  {
    for (auto i = begin[depth]; i < end[depth]; i += increment[depth])
    {
      indices[depth] = i;
      permute_for<type>(function, begin, end, increment, indices, depth + 1);
    }
  }
  else
    function(indices);
}
}