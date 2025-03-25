cmake_minimum_required(VERSION 3.16)

project(c LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(c
    dMatrix.h
    dVector.h
    include.hpp
    Gravity.hpp
    main.cpp
    Matrix_test.h
    Creater_sphere.hpp
    shader.vert
    shader.frag

)

include(GNUInstallDirs)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)

# Добавляем исполняемый файл

target_link_libraries(c PRIVATE sfml-graphics sfml-window sfml-system)
target_link_libraries(c PRIVATE OpenGL::GL GLUT::GLUT GLEW::GLEW glfw)

install(TARGETS c
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
