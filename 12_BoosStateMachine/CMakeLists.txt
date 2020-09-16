cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(12_BoostStateMachine)

find_package(Boost REQUIRED)

include_directories(${BOOST_INCLUDE_DIRS})
link_directories(${BOOST_LIBRARY_DIRS})
add_definitions(${BOOST_DEFINITIONS})

add_executable(state_machine src/state_machine.cpp)
target_link_libraries(
    state_machine
    ${BOOST_LIBRARIES}
)
