Overview
=========

Eigen Wrapper for Fukuda's [cdd] library

The license that applies to the whole package content is **CeCILL-C**. Please look at the license.txt file at the root of this repository.

Dependencies
============

- [CMake](https://cmake.org)
- [Eigen](https://eigen.tuxfamily.org/index.php?title=Main_Page)
- [cdd]

To build unit tests in this library you also need:
- [Boost.Test](https://www.boost.org/doc/libs/release/libs/test/)


Installation
============

## From source

After cloning this repository:

```shell
cmake -B build -S .
cmake --build . --config RelWithDebInfo
sudo cmake --build . --config RelWithDebInfo --target install
```

Usage
=====

To use this package with CMake:

```cmake
find_package(eigen-cdd REQUIRED)
target_link_libraries(MyTarget PUBLIC eigen-cdd::eigen-cdd)
```

Authors
=======

eigen-cdd has been developped by following authors:
+ Vincent Samy (LIRMM) - Original author of the wrapper
+ Pierre Gergondet - CMake and CI

Please contact Vincent Samy (vsamy@outlook.fr) - LIRMM for more information or questions.



[cdd]: https://www.inf.ethz.ch/personal/fukudak/cdd_home
