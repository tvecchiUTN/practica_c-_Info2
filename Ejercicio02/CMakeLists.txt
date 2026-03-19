cmake_minimum_required(VERSION 3.19)
project(Ejercicio02 LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core)

qt_standard_project_setup()

qt_add_executable(Ejercicio02
    main.cpp
    punto.h punto.cpp
)

target_link_libraries(Ejercicio02
    PRIVATE
        Qt::Core
)

install(TARGETS Ejercicio02
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
