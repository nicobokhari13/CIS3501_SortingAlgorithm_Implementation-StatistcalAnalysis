add_executable(sort_algs_app sort_algs_main.cpp)
target_link_libraries(sort_algs_app
            PRIVATE Sorting_Lists
            PUBLIC  Globals
)