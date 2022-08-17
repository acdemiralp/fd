#pragma once

#include <array>
#include <cmath>
#include <cstddef>

#include <fd/compatibility/cuda.hpp>
#include <fd/core/coefficients.hpp>
#include <fd/utility/constexpr_for.hpp>

namespace fd
{
// Creates a finite difference function from a stencil and its coefficients.
template <std::size_t order, typename type, std::size_t size>
constexpr auto make_function(const std::array<type, size>& stencil, const std::array<type, size>& coefficients)
{
  return [stencil, coefficients] (const function<type(const type&)>& f, const type& x, const type& h = static_cast<type>(1e-3))
  {
    type sum {};
    constexpr_for<0, size, 1>([&] (const auto i)
    {
      sum += std::get<i.value>(coefficients) * f(x + std::get<i.value>(stencil) * h);
    });
    return sum / static_cast<type>(std::pow(h, order));
  };
}

#ifdef FD_USE_EIGEN
// Creates a finite difference function from a stencil.
template <std::size_t order, typename type, std::size_t size>
constexpr auto make_function(const std::array<type, size>& stencil)
{
  return make_function<order>(stencil, make_coefficients<order>(stencil));
}
#endif
}