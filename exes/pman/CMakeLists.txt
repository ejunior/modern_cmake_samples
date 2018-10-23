project(palmerinha VERSION 0.0.1 LANGUAGES CXX)

#create binaries 
add_executable(${PROJECT_NAME} src/main.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE Dll1::Dll1)

#target_include_directories(${PROJECT_NAME} PUBLIC Dll1)
find_library(${PROJECT_NAME} Dll1::Dll1)

#linker
target_link_libraries(${PROJECT_NAME} Dll1::Dll1 Boost::boost)

#config install
install( 	TARGETS ${PROJECT_NAME}
			RUNTIME DESTINATION bin
			LIBRARY DESTINATION lib
			ARCHIVE DESTINATION lib/static) # statics libs vão aqui

if(MSVC)
set_target_properties(${PROJECT_NAME} PROPERTIES
		ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
		LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
		RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
		)
ENDIF()