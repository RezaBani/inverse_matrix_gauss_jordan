cmake_minimum_required(VERSION 3.5)

project(inverse_matrix_gauss_jordan LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(inverse_matrix_gauss_jordan main.cpp)

include(GNUInstallDirs)
install(TARGETS inverse_matrix_gauss_jordan
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
