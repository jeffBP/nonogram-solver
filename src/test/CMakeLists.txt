enable_testing()
add_executable(
    nonogram_test
    nonogram_test.cpp
)

find_package(GTest CONFIG REQUIRED)
target_link_libraries(
    nonogram_test
    GTest::gtest
    GTest::gtest_main
    src
)

include(GoogleTest)
gtest_discover_tests(nonogram_test)