cmake_minimum_required (VERSION 3.0)
project (test_basic CXX)

add_executable(integral_types_test integral_types_test.cpp)
add_dependencies(integral_types_test gtest)
target_link_libraries(integral_types_test ${SEQAN3_LIBRARIES})
add_test(NAME test_integral_types_test COMMAND integral_types_test)
