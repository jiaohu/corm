cmake_minimum_required(VERSION 3.19.6)

project(corm_boost)

add_executable(corm_boost tests.cpp ../type.h)

set(Boost_USE_STATIC_LIBS OFF)
# see https://cmake.org/cmake/help/latest/module/FindBoost.html
find_package(Boost REQUIRED COMPONENTS unit_test_framework)

include_directories(${Boost_INCLUDE_DIR})
# Note: a target should be already defined using 'add_executable' or 'add_library'


target_link_libraries(corm_boost ${Boost_LIBRARIES})
