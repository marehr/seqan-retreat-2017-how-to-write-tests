cmake_minimum_required (VERSION 3.0)
project (test_align CXX)

add_executable(align_config_test align_config_test.cpp)
target_link_libraries(align_config_test ${SEQAN3_LIBRARIES})
add_test(NAME test_align_config_test COMMAND align_config_test)

add_executable(align_enum_test align_enum_test.cpp)
target_link_libraries(align_enum_test ${SEQAN3_LIBRARIES})
add_test(NAME test_align_enum_test COMMAND align_enum_test)
