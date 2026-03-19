cmake_minimum_required(VERSION 3.19)
project(Ejercicio01 LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core)

qt_standard_project_setup()

qt_add_executable(Ejercicio01
    main.cpp
)

target_link_libraries(Ejercicio01
    PRIVATE
        Qt::Core
)

install(TARGETS Ejercicio01
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
