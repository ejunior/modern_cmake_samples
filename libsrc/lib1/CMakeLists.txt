project(Lib1 VERSION 0.1 LANGUAGES CXX)

add_library(${PROJECT_NAME} STATIC src/lib1.cpp)
add_library("${PROJECT_NAME}::${PROJECT_NAME}" ALIAS ${PROJECT_NAME})

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)

target_include_directories(${PROJECT_NAME}
    PUBLIC 
        $<INSTALL_INTERFACE:include>    
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

install( 	TARGETS ${PROJECT_NAME} EXPORT "${PROJECT_NAME}Targets"
			RUNTIME DESTINATION bin
			LIBRARY DESTINATION lib
			ARCHIVE DESTINATION lib/static # statics libs vão aqui
)

install(	EXPORT "${PROJECT_NAME}Targets"
			FILE "${PROJECT_NAME}Targets.cmake"
			NAMESPACE "${PROJECT_NAME}::"
			DESTINATION "lib/cmake/${PROJECT_NAME}"
)