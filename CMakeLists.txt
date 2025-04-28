cmake_minimum_required(VERSION 3.28.3)
project("exercise1")
set(SOURCE_FILES "src/appetizer.cpp" "src/dessert.cpp" "src/drink.cpp" "src/main_course.cpp" "src/main.cpp" "src/menu_item.cpp" "src/order.cpp")
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
