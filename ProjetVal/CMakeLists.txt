add_executable(ProjetVal main main.cpp "Station.cpp" "Route.cpp")
target_link_libraries(ProjetVal ${CMAKE_SOURCE_DIR}/library/sfml-audio.lib)
target_link_libraries(ProjetVal ${CMAKE_SOURCE_DIR}/library/sfml-graphics.lib)
target_link_libraries(ProjetVal ${CMAKE_SOURCE_DIR}/library/sfml-network.lib)
target_link_libraries(ProjetVal ${CMAKE_SOURCE_DIR}/library/sfml-system.lib)
target_link_libraries(ProjetVal ${CMAKE_SOURCE_DIR}/library/sfml-window.lib)

include_directories(${CMAKE_SOURCE_DIR}/include)

set_property(TARGET ProjetVal PROPERTY CXX_STANDARD 17)
set_property(TARGET ProjetVal PROPERTY CXX_STANDARD_REQUIRED ON)