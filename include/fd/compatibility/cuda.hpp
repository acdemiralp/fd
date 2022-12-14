#pragma once

#ifdef __CUDACC__
#include <nvfunctional>
namespace fd
{
template <typename type>
using function = nvstd::function<type>;
}
#else
#include <functional>
namespace fd
{
template <typename type>
using function = std::function<type>;
}
#define __constant__
#define __device__
#define __host__
#endif