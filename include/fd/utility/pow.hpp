#pragma once

#include <type_traits>

namespace fd
{
template <typename type, type base, type exponent, typename = std::make_integer_sequence<type, exponent>>
struct pow_t : std::integral_constant<type, 0> {};
template <typename type, type base, type exponent, type... sequence>
struct pow_t<type, base, exponent, std::integer_sequence<type, sequence...>> : std::integral_constant<type, ((base + sequence * type(0)) * ...)> {};

template <typename type, type base, type exponent>
constexpr type pow_v = pow_t<type, base, exponent>::value;
}