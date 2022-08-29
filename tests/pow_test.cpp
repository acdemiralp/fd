#include "doctest/doctest.h"

#include <fd/all.hpp>

TEST_CASE("pow")
{
  REQUIRE(fd::pow_t<std::int32_t, 0, 4>::value == 0  );
  REQUIRE(fd::pow_t<std::int32_t, 1, 4>::value == 1  );
  REQUIRE(fd::pow_t<std::int32_t, 2, 4>::value == 16 );
  REQUIRE(fd::pow_t<std::int32_t, 3, 4>::value == 81 );
  REQUIRE(fd::pow_t<std::int32_t, 4, 4>::value == 256);

  REQUIRE(fd::pow_v<std::int32_t, 0, 4>        == 0  );
  REQUIRE(fd::pow_v<std::int32_t, 1, 4>        == 1  );
  REQUIRE(fd::pow_v<std::int32_t, 2, 4>        == 16 );
  REQUIRE(fd::pow_v<std::int32_t, 3, 4>        == 81 );
  REQUIRE(fd::pow_v<std::int32_t, 4, 4>        == 256);
}