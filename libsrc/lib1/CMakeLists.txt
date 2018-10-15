project(lib1 LANGUAGES CXX)



add_library(${PROJECT_NAME} STATIC lib1.cpp)
add_library("${PROJECT_NAME}::${PROJECT_NAME}" ALIAS ${PROJECT_NAME})

install( 	TARGETS ${PROJECT_NAME}
			RUNTIME DESTINATION bin
			LIBRARY DESTINATION lib
			ARCHIVE DESTINATION lib/static) # statics libs vão aqui
