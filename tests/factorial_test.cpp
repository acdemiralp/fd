#include "doctest/doctest.h"

#include <cstdint>

#include <fd/all.hpp>

TEST_CASE("factorial")
{
  REQUIRE(fd::factorial_t<std::int32_t, 0>::value == 1  );
  REQUIRE(fd::factorial_t<std::int32_t, 1>::value == 1  );
  REQUIRE(fd::factorial_t<std::int32_t, 2>::value == 2  );
  REQUIRE(fd::factorial_t<std::int32_t, 3>::value == 6  );
  REQUIRE(fd::factorial_t<std::int32_t, 4>::value == 24 );
  REQUIRE(fd::factorial_t<std::int32_t, 5>::value == 120);

  REQUIRE(fd::factorial_v<std::int32_t, 0>        == 1  );
  REQUIRE(fd::factorial_v<std::int32_t, 1>        == 1  );
  REQUIRE(fd::factorial_v<std::int32_t, 2>        == 2  );
  REQUIRE(fd::factorial_v<std::int32_t, 3>        == 6  );
  REQUIRE(fd::factorial_v<std::int32_t, 4>        == 24 );
  REQUIRE(fd::factorial_v<std::int32_t, 5>        == 120);

  REQUIRE(fd::factorial  <std::int32_t>(0)        == 1  );
  REQUIRE(fd::factorial  <std::int32_t>(1)        == 1  );
  REQUIRE(fd::factorial  <std::int32_t>(2)        == 2  );
  REQUIRE(fd::factorial  <std::int32_t>(3)        == 6  );
  REQUIRE(fd::factorial  <std::int32_t>(4)        == 24 );
  REQUIRE(fd::factorial  <std::int32_t>(5)        == 120);
}