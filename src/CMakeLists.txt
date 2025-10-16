add_library(Globals globals.cpp)
add_library(Sorting_Lists sortingLists.cpp)
target_include_directories(Globals PUBLIC "${CMAKE_LIBRARY_PATH}/sort-algs/globals.h")
target_include_directories(Sorting_Lists PRIVATE "${CMAKE_LIBRARY_PATH}/sort-algs/sortingLists.h")
