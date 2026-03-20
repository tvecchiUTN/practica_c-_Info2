cmake_minimum_required(VERSION 3.16)

project(Ejercicio03 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Ejercicio03 main.cpp
    punto.h punto.cpp)

include(GNUInstallDirs)
install(TARGETS Ejercicio03
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
