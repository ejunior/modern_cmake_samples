project(regex_sample VERSION 1.0)


add_executable(${PROJECT_NAME} main.cpp)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)

configure_file(sample_input.txt sample_input.txt COPYONLY)
configure_file(sample_input2.txt sample_input2.txt COPYONLY)
configure_file(sample_input3.txt sample_input3.txt COPYONLY)