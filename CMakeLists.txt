cmake_minimum_required(VERSION 3.28.3)
project("exercise1")
set(SOURCE_FILES "src/coin.cpp" "src/coin10.cpp" "src/coin20.cpp" "src/coin50.cpp" "src/main.cpp")
add_executable(${PROJECT_NAME} ${SOURCE_FILES})