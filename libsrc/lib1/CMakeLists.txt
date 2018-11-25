project(Lib1 VERSION 0.1 LANGUAGES CXX)


find_package(Threads REQUIRED)


add_library(${PROJECT_NAME} STATIC src/lib1.cpp)
add_library("${PROJECT_NAME}::${PROJECT_NAME}" ALIAS ${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} Threads::Threads)

target_include_directories(${PROJECT_NAME}
    PUBLIC 
        $<INSTALL_INTERFACE:include>    
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)


#install( 	TARGETS ${PROJECT_NAME} EXPORT "${PROJECT_NAME}Targets"
#			RUNTIME DESTINATION bin
#			LIBRARY DESTINATION lib
#			ARCHIVE DESTINATION lib/static # statics libs vão aqui
#)
#
#install(	EXPORT "${PROJECT_NAME}Targets"
#			FILE "${PROJECT_NAME}Targets.cmake"
#			NAMESPACE "${PROJECT_NAME}::"
#			DESTINATION "lib/cmake/${PROJECT_NAME}"
#)


#include_directories(${googletest_SOURCE_DIR}/googletest/include ${googletest_SORUCE_DIR})

ENABLE_TESTING()

add_gtest(lib1_test tests/lib1_test.cpp Lib1:Lib1)

#add_executable(lib1_test tests/lib1_test.cpp)
#target_include_directories(lib1_test PUBLIC include)
#target_link_libraries(lib1_test gtest gtest_main Lib1::Lib1)

#add_test(${PROJECT_NAME} lib1_test)
