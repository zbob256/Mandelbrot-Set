cmake_minimum_required(VERSION 3.10)

project(Mandelbrot-Set)

find_package(SFML 3 REQUIRED COMPONENTS Window System Graphics)

add_executable(Mandelbrot-Set
    src/main.cpp
    src/mandelbrot.cpp
)

target_include_directories(Mandelbrot-Set PRIVATE include)

target_link_libraries(Mandelbrot-Set
    sfml-graphics
    sfml-window
    sfml-system
)