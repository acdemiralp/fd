#include "doctest/doctest.h"

#include <fd/all.hpp>

TEST_CASE("permute_for")
{
  constexpr std::array<std::size_t, 2> begin     {0, 0};
  constexpr std::array<std::size_t, 2> end       {2, 2};
  constexpr std::array<std::size_t, 2> increment {1, 1};

  const std::array<std::array<std::size_t, 2>, 4> control {{{0, 0}, {0, 1}, {1, 0}, {1, 1}}};

  auto control_index = 0;
  fd::permute_for<std::size_t, 2, begin, end, increment>([&] (const std::array<std::size_t, 2>& index)
  {
    REQUIRE(index == control[control_index++]);
  });

  control_index = 0;
  fd::permute_for<std::array<std::size_t, 2>>([&] (const std::array<std::size_t, 2>& index)
  {
    REQUIRE(index == control[control_index++]);
  }, begin, end, increment);
}