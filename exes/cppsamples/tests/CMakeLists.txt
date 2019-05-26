project(teste_sample)


include(CTest)
enable_testing()

find_package(GTest REQUIRED)

add_executable( ${PROJECT_NAME} test.cpp 
                                ../src/samples.h
                                ../src/samples.cpp)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)

target_link_libraries(${PROJECT_NAME} GTest::GTest GTest::Main)

add_test(AllTestsInFoo ${PROJECT_NAME})



# ADD_TEST( NAME um_teste WORKING_DIRECTORY ${CMAKE_BUILD_DIRECTORY} COMMAND ${PROJECT_NAME})