#include "doctest/doctest.h"

#include <cstdint>

#include <fd/all.hpp>

TEST_CASE("binomial_coefficient")
{
  REQUIRE(fd::binomial_coefficient_t<std::int32_t, 0, 2>::value == 0 );
  REQUIRE(fd::binomial_coefficient_t<std::int32_t, 1, 2>::value == 0 );
  REQUIRE(fd::binomial_coefficient_t<std::int32_t, 2, 2>::value == 1 );
  REQUIRE(fd::binomial_coefficient_t<std::int32_t, 3, 2>::value == 3 );
  REQUIRE(fd::binomial_coefficient_t<std::int32_t, 4, 2>::value == 6 );
  REQUIRE(fd::binomial_coefficient_t<std::int32_t, 5, 2>::value == 10);
  
  REQUIRE(fd::binomial_coefficient_v<std::int32_t, 0, 2>        == 0 );
  REQUIRE(fd::binomial_coefficient_v<std::int32_t, 1, 2>        == 0 );
  REQUIRE(fd::binomial_coefficient_v<std::int32_t, 2, 2>        == 1 );
  REQUIRE(fd::binomial_coefficient_v<std::int32_t, 3, 2>        == 3 );
  REQUIRE(fd::binomial_coefficient_v<std::int32_t, 4, 2>        == 6 );
  REQUIRE(fd::binomial_coefficient_v<std::int32_t, 5, 2>        == 10);
  
  REQUIRE(fd::binomial_coefficient  <std::int32_t>(0, 2)        == 0 );
  REQUIRE(fd::binomial_coefficient  <std::int32_t>(1, 2)        == 0 );
  REQUIRE(fd::binomial_coefficient  <std::int32_t>(2, 2)        == 1 );
  REQUIRE(fd::binomial_coefficient  <std::int32_t>(3, 2)        == 3 );
  REQUIRE(fd::binomial_coefficient  <std::int32_t>(4, 2)        == 6 );
  REQUIRE(fd::binomial_coefficient  <std::int32_t>(5, 2)        == 10);
}