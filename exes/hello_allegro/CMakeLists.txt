project(hello_allegro)

message("ALLEGRO VERSION ${ALLEGRO_VERSION}")
#message("ALLEGRO VERSION ${allegro5_DIR}")

#create binaries 
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} ALLEGRO)
target_compile_options(-lallegro_main)

#linker
#target_link_libraries(${PROJECT_NAME} )

#config install
#install( 	TARGETS ${PROJECT_NAME}
#			RUNTIME DESTINATION bin
#			LIBRARY DESTINATION lib
#			ARCHIVE DESTINATION lib/static) # statics libs vão aqui
