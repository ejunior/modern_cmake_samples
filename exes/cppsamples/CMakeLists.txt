project(cppsample)

add_executable(${PROJECT_NAME} Teste.cpp)

#target_include_directories(${PROJECT_NAME} Boost::boost)

target_link_libraries(${PROJECT_NAME} Boost::boost)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)