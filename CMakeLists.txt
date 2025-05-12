cmake_minimum_required(VERSION 3.28.3)
project("exercise4")
set(SOURCE_FILES "src/main.cpp" "src/exceptions.cpp" "src/stack.cpp")
add_executable(${PROJECT_NAME} ${SOURCE_FILES})