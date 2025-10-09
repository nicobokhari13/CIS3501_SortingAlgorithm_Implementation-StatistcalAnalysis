set(HEADER_LIST "${PROJECT_SOURCE_DIR}/include/sort-algs/lib.hpp")

add_library(MyLibraryExample lib.cpp ${HEADER_LIST})

target_include_directories(MyLibraryExample PUBLIC ../include)

source_group(
        TREE "${PROJECT_SOURCE_DIR}/include/"
        PREFIX "Header Files"
        FILES ${HEADER_LIST}
)