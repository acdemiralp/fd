#pragma once

#include <cstddef>

#include <fd/core/function.hpp>
#include <fd/core/stencil.hpp>
#include <fd/utility/binomial_coefficient.hpp>
#include <fd/utility/constexpr_for.hpp>

namespace fd
{
#ifdef FD_USE_EIGEN
template <std::size_t order, typename function, typename value>
constexpr value forward_difference (const function& f, const value& x, const value h = value(1e-3))
{
  static const auto finite_difference_function = make_function<order>(make_forward_stencil<value, order + 1>());
  return finite_difference_function(f, x, h);
}
template <std::size_t order, typename function, typename value>
constexpr value backward_difference(const function& f, const value& x, const value h = value(1e-3))
{
  static const auto finite_difference_function = make_function<order>(make_backward_stencil<value, order + 1>());
  return finite_difference_function(f, x, h);
}
template <std::size_t order, typename function, typename value>
constexpr value central_difference (const function& f, const value& x, const value h = value(1e-3))
{
  static const auto finite_difference_function = make_function<order>(make_central_stencil<value, order + 1>());
  return finite_difference_function(f, x, h);
}
#else
template <std::size_t order, typename function, typename value>
constexpr value forward_difference (const function& f, const value& x, const value h = value(1e-3))
{
  value sum {};
  constexpr_for<0, order, 1>([&] (const auto i)
  {
    sum += 
      static_cast<value>((order - i.value) % 2 == 0 ? 1 : -1) * 
      static_cast<value>(binomial_coefficient_v<std::size_t, order, i.value>) * 
      f(x + static_cast<value>(i.value) * h);
  });
  return sum;
}
template <std::size_t order, typename function, typename value>
constexpr value backward_difference(const function& f, const value& x, const value h = value(1e-3))
{
  value sum {};
  constexpr_for<0, order, 1>([&] (const auto i)
  {
    sum += 
      static_cast<value>(i.value % 2 == 0 ? 1 : -1) * 
      static_cast<value>(binomial_coefficient_v<std::size_t, order, i.value>) *
      f(x - static_cast<value>(i.value) * h);
  });
  return sum;
}
template <std::size_t order, typename function, typename value>
constexpr value central_difference (const function& f, const value& x, const value h = value(1e-3))
{
  value sum {};
  constexpr_for<0, order, 1>([&] (const auto i)
  {
    sum += 
      static_cast<value>(i.value % 2 == 0 ? 1 : -1) * 
      static_cast<value>(binomial_coefficient_v<std::size_t, order, i.value>) *
      f(x + (static_cast<value>(order) / static_cast<value>(2) - static_cast<value>(i.value)) * h);
  });
  return sum;
}
#endif

// Specializations for first order.
template <typename function, typename value>
constexpr value forward_difference (const function& f, const value& x, const value h = value(1e-3))
{
  return (f(x + h) - f(x)) / h;
}
template <typename function, typename value>
constexpr value backward_difference(const function& f, const value& x, const value h = value(1e-3))
{
  return (f(x) - f(x - h)) / h;
}
template <typename function, typename value>
constexpr value central_difference (const function& f, const value& x, const value h = value(1e-3))
{
  return (f(x + static_cast<value>(0.5) * h) - f(x - static_cast<value>(0.5) * h)) / h;
}
}