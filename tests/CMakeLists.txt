find_package(Boost REQUIRED COMPONENTS unit_test_framework)

add_executable(TestPolyhedron TestPolyhedron.cpp)
target_link_libraries(TestPolyhedron PRIVATE ${PROJECT_NAME} Boost::unit_test_framework Boost::disable_autolinking)
add_test(NAME TestPolyhedron COMMAND TestPolyhedron)
