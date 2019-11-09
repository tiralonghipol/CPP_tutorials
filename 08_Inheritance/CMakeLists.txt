include_directories(
    include 
)
add_library(parent src/parent.cpp)
target_link_libraries(parent)

add_executable(main_08 src/main_08.cpp)
target_link_libraries(
    main_08 
    parent
)


