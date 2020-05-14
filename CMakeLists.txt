#CMakeLists.txt projektu głównego
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)

add_compile_options(-Wall -Wextra -Werror)

project(Projekt)

add_subdirectory(Biblioteka)

add_subdirectory(Program)

#enable_testing()
