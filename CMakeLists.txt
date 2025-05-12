cmake_minimum_required(VERSION 3.28.3)
project("project1")
set(SOURCE_FILES "src/exceptions.cpp" "src/main.cpp")
add_executable(${PROJECT_NAME} ${SOURCE_FILES})