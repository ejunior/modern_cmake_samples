project(regex_sample VERSION 1.0)



add_executable(${PROJECT_NAME} _regex_sample.cpp)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)

configure_file(sample_input.txt sample_input.txt COPYONLY)