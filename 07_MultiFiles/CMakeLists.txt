include_directories(
    include 
)
add_library(cat src/cat.cpp)
target_link_libraries(cat)

add_library(dog src/dog.cpp)
target_link_libraries(dog)

add_executable(main src/main.cpp)
target_link_libraries(
    main 
    cat
    dog
)


