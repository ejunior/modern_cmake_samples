cmake_minimum_required( VERSION 3.12)

project(test_exercise VERSION 1.0 LANGUAGES CXX)

set(RETURN_VALUE 0)

enable_testing()

add_executable(${PROJECT_NAME} main.cpp)


add_test(test1 ${PROJECT_NAME} ${RETURN_VALUE})
