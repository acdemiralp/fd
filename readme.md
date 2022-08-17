### FD
Generic finite differences in C++20.

### Abstractions
- [Stencils](include/fd/core/stencil.hpp) are standard arrays defining a one dimensional arrangement of samples.
- [Finite difference coefficients](include/fd/core/coefficients.hpp) are computed from a stencil and a derivative order.
- [Finite difference functions](include/fd/core/function.hpp) are generated from stencils and their associated coefficients.

### Usage
```cpp
#include <cmath>

#include "fd/all.hpp"

int main(int argc, char** argv)
{
  const auto function = [ ] (const float x)
  {
    return std::sin(x);
  };

  // Second order forward, backward, central differences of sine at x=0.0f with h=0.001f.
  auto fd = fd::forward_difference <2>(function, 0.0f, 0.001f);
  auto bd = fd::backward_difference<2>(function, 0.0f, 0.001f);
  auto cd = fd::central_difference <2>(function, 0.0f, 0.001f);

  return 0;
}
```
See the tests for more.

### Notes
- Define `FD_USE_EIGEN` prior to including the headers to enable computing finite difference coefficients of arbitrary orders and stencils.

### Future Work
- Better tests, including CUDA.