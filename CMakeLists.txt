cmake_minimum_required(VERSION 3.15...4.0)
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

project(
        SortAlgExample
        VERSION 1.0
        LANGUAGES CXX
)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
add_subdirectory(src)
add_subdirectory(apps)

