project(cppsample)

add_executable(${PROJECT_NAME} teste.cpp)

#target_include_directories(${PROJECT_NAME} Boost::boost)

target_link_libraries(${PROJECT_NAME} Boost::boost)