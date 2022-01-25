cmake_minimum_required(VERSION 3.1)

project(test-eigen-cdd LANGUAGES CXX VERSION 1.0.0)
include(CTest)

find_package(eigen-cdd REQUIRED)

add_executable(main main.cpp)
target_link_libraries(main PUBLIC eigen-cdd::eigen-cdd)
add_test(NAME TestIt COMMAND main)

install(CODE "message(\"Fake installation\")")
