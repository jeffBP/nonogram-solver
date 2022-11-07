add_library(src)

target_sources(src
    PUBLIC
        nonogram_utils.hpp
        nonogram.hpp
        nonogram.cpp)

add_subdirectory(test)