project(dll1 LANGUAGES CXX)

# header and sources

# create the dll
add_library(${PROJECT_NAME} SHARED dll1.cpp)
add_library("${PROJECT_NAME}::${PROJECT_NAME}" ALIAS ${PROJECT_NAME})

# linker
target_link_libraries(${PROJECT_NAME} lib1::lib1)

install( 	TARGETS ${PROJECT_NAME}
			RUNTIME DESTINATION bin
			LIBRARY DESTINATION lib #entram aqui as dinamicas
			ARCHIVE DESTINATION lib/static) # statics libs vão aqui

