project(Dll1 VERSION 0.1 LANGUAGES CXX)

# header and sources

# create the dll
add_library(${PROJECT_NAME} SHARED src/dll1.cpp)


target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    PRIVATE src)

target_compile_options(${PROJECT_NAME} PRIVATE -lm)

add_library("${PROJECT_NAME}::${PROJECT_NAME}" ALIAS ${PROJECT_NAME})

# linker
target_link_libraries(${PROJECT_NAME} Lib1::Lib1)

install( 	TARGETS ${PROJECT_NAME} EXPORT "${PROJECT_NAME}_TARGETS" 
			RUNTIME DESTINATION bin
			LIBRARY DESTINATION lib #entram aqui as dinamicas
			ARCHIVE DESTINATION lib/static # statics libs vão aqui
			INCLUDES DESTINATION include)

install(	EXPORT "${PROJECT_NAME}_TARGETS"
			FILE "${PROJECT_NAME}Targets.cmake" 
			NAMESPACE Dll1::
			DESTINATION "lib/cmake/${PROJECT_NAME}")

