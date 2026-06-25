cmake_minimum_required(VERSION 3.16)

project(Kalkulator_final_Kons LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Kalkulator_final_Kons main.cpp
    operacja.h operacja.cpp
    kalkulator.h kalkulator.cpp
    menukonsolowe.h menukonsolowe.cpp
    historia.h historia.cpp)

include(GNUInstallDirs)
install(TARGETS Kalkulator_final_Kons
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
