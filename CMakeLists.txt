cmake_minimum_required (VERSION 3.15)

cmake_policy(SET CMP0091 NEW)

project(ProjetVal)

set (CMAKE_CXX_STANDARD 20)

if(MSVC)
    set(SFML_DIR "SFML/lib/cmake/SFML")
    set(SFML_STATIC_LIBRARIES TRUE)
    add_compile_options(
    $<$<CONFIG:>:/MT> #---------|
    $<$<CONFIG:Debug>:/MTd> #---|--  Statically link the runtime libraries
    $<$<CONFIG:Release>:/MT> #--|
    )
endif()

find_package(SFML COMPONENTS window system graphics REQUIRED)
link_libraries(sfml-graphics sfml-window)
configure_file(SFML/font/arial.ttf ${CMAKE_CURRENT_BINARY_DIR}/ProjetVal/arial.ttf COPYONLY)

add_subdirectory(ProjetVal)