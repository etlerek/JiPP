cmake_minimum_required( VERSION 3.19.0 )

project( Lab4 )

include_directories( ./include/Lab4  ./src )

add_executable(main ./src/main.cpp  ./src/matrix.cpp )
