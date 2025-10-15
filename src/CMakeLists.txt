add_library(MyLibraryExample lib.cpp)

target_include_directories(MyLibraryExample PUBLIC "${CMAKE_LIBRARY_PATH}/sort-algs")
