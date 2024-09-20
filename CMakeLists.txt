cmake_minimum_required(VERSION 3.20)

project(data-struct VERSION 2.0.0 LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 20)


include(FetchContent)
	
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)


set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


enable_testing()

#target_link_libraries(test_package GTest::gtest_main)

include(GoogleTest)

gtest_discover_tests(test_package)


