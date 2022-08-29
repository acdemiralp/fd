#include "doctest/doctest.h"

#ifdef FD_USE_EIGEN
#include <Eigen/Core>
#endif

#include <fd/all.hpp>

TEST_CASE("indexing")
{
  {
    std::array<std::size_t, 3> dimensions {2, 2, 2};
    REQUIRE(fd::unravel_index(0, dimensions) == std::array<std::size_t, 3>{0, 0, 0});
    REQUIRE(fd::unravel_index(1, dimensions) == std::array<std::size_t, 3>{0, 0, 1});
    REQUIRE(fd::unravel_index(2, dimensions) == std::array<std::size_t, 3>{0, 1, 0});
    REQUIRE(fd::unravel_index(3, dimensions) == std::array<std::size_t, 3>{0, 1, 1});
    REQUIRE(fd::unravel_index(4, dimensions) == std::array<std::size_t, 3>{1, 0, 0});
    REQUIRE(fd::unravel_index(5, dimensions) == std::array<std::size_t, 3>{1, 0, 1});
    REQUIRE(fd::unravel_index(6, dimensions) == std::array<std::size_t, 3>{1, 1, 0});
    REQUIRE(fd::unravel_index(7, dimensions) == std::array<std::size_t, 3>{1, 1, 1});

    REQUIRE(fd::ravel_multi_index(std::array<std::size_t, 3>{0, 0, 0}, dimensions) == 0);
    REQUIRE(fd::ravel_multi_index(std::array<std::size_t, 3>{0, 0, 1}, dimensions) == 1);
    REQUIRE(fd::ravel_multi_index(std::array<std::size_t, 3>{0, 1, 0}, dimensions) == 2);
    REQUIRE(fd::ravel_multi_index(std::array<std::size_t, 3>{0, 1, 1}, dimensions) == 3);
    REQUIRE(fd::ravel_multi_index(std::array<std::size_t, 3>{1, 0, 0}, dimensions) == 4);
    REQUIRE(fd::ravel_multi_index(std::array<std::size_t, 3>{1, 0, 1}, dimensions) == 5);
    REQUIRE(fd::ravel_multi_index(std::array<std::size_t, 3>{1, 1, 0}, dimensions) == 6);
    REQUIRE(fd::ravel_multi_index(std::array<std::size_t, 3>{1, 1, 1}, dimensions) == 7);
  }
  {
#ifdef FD_USE_EIGEN
    Eigen::Vector3i dimensions(2, 2, 2);
    REQUIRE(fd::unravel_index(0, dimensions) == Eigen::Vector3i(0, 0, 0));
    REQUIRE(fd::unravel_index(1, dimensions) == Eigen::Vector3i(0, 0, 1));
    REQUIRE(fd::unravel_index(2, dimensions) == Eigen::Vector3i(0, 1, 0));
    REQUIRE(fd::unravel_index(3, dimensions) == Eigen::Vector3i(0, 1, 1));
    REQUIRE(fd::unravel_index(4, dimensions) == Eigen::Vector3i(1, 0, 0));
    REQUIRE(fd::unravel_index(5, dimensions) == Eigen::Vector3i(1, 0, 1));
    REQUIRE(fd::unravel_index(6, dimensions) == Eigen::Vector3i(1, 1, 0));
    REQUIRE(fd::unravel_index(7, dimensions) == Eigen::Vector3i(1, 1, 1));

    REQUIRE(fd::ravel_multi_index(Eigen::Vector3i(0, 0, 0), dimensions) == 0);
    REQUIRE(fd::ravel_multi_index(Eigen::Vector3i(0, 0, 1), dimensions) == 1);
    REQUIRE(fd::ravel_multi_index(Eigen::Vector3i(0, 1, 0), dimensions) == 2);
    REQUIRE(fd::ravel_multi_index(Eigen::Vector3i(0, 1, 1), dimensions) == 3);
    REQUIRE(fd::ravel_multi_index(Eigen::Vector3i(1, 0, 0), dimensions) == 4);
    REQUIRE(fd::ravel_multi_index(Eigen::Vector3i(1, 0, 1), dimensions) == 5);
    REQUIRE(fd::ravel_multi_index(Eigen::Vector3i(1, 1, 0), dimensions) == 6);
    REQUIRE(fd::ravel_multi_index(Eigen::Vector3i(1, 1, 1), dimensions) == 7);
#endif
  }
}