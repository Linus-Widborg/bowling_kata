cmake_minimum_required(VERSION 3.6)
project(training)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/BowlingResult.cpp src/BowlingResult.h src/Frame.cpp src/Frame.h)
add_executable(training main.cpp ${SOURCE_FILES})

################################
# GTest
################################
add_subdirectory(lib/googletest)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

################################
# Unit Tests
################################
add_executable(runUnitTests test/testBowlingScore.cpp ${SOURCE_FILES} src/Frame.cpp src/Frame.h)
target_link_libraries(runUnitTests gtest gtest_main)
add_test(runUnitTests runUnitTests)