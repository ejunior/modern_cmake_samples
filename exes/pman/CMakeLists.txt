project(palmerinha VERSION 0.0.1 LANGUAGES CXX)

#create binaries 
add_executable(${PROJECT_NAME} main.cpp)

#linker
target_link_libraries(${PROJECT_NAME} dll1::dll1 Boost::boost)

#config install
install( 	TARGETS ${PROJECT_NAME}
			RUNTIME DESTINATION bin
			LIBRARY DESTINATION lib
			ARCHIVE DESTINATION lib/static) # statics libs vão aqui
