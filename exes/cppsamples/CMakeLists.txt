project(cppsample)

add_executable(${PROJECT_NAME} src/main.cpp src/samples.h src/samples.cpp)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)

#target_link_libraries(${PROJECT_NAME} src/samples.cpp)

add_subdirectory(tests)

#target_include_directories(${PROJECT_NAME} Boost::boost)

target_link_libraries(${PROJECT_NAME} Boost::boost)

