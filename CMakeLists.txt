cmake_minimum_required(VERSION 3.15...4.0)
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})
set(CMAKE_LIBRARY_PATH "${PROJECT_SOURCE_DIR}/include/sort-algs/" ${CMAKE_LIBRARY_PATH})
project(
        SortAlgExample
        VERSION 1.0
        LANGUAGES CXX
)

add_subdirectory(src)
add_subdirectory(apps)

