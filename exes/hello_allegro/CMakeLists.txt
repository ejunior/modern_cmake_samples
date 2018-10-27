cmake_minimum_required(VERSION 3.12)

project(hello_allegro)

find_package(PkgConfig)
pkg_check_modules(Allegro REQUIRED allegro-5)

#create binaries
add_executable(${PROJECT_NAME} main.cpp)

MESSAGE(\n
		CFLAGS: \n
		Allegro_CFLAGS 	\t		${Allegro_CFLAGS} \n
		Allegro_CFLAGS_OTHER \t	${Allegro_CFLAGS_OTHER} \n
		Allegro_LDFLAGS \t 		${Allegro_LDFLAGS} \n
		Allegro_LDFLAGS_OTHER\t ${Allegro_LDFLAGS_OTHER} \n

		Allegro_INCLUDE_DIRS \t ${Allegro_INCLUDE_DIRS} \n
		Allegro_LIBRARIES\t 	${Allegro_LIBRARIES}\n
		Allegro_LIBRARY_DIRS\t 	${Allegro_LIBRARY_DIRS}\n
		)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall)
target_include_directories(${PROJECT_NAME} PUBLIC ${Allegro_INCLUDE_DIRS})

file(GLOB_RECURSE aleglibs ${Allegro_LIBRARY_DIRS}/* )
message(${aleglibs})

#linker
#target_link_options(${PROJECT_NAME} PUBLIC)
#target_link_libraries(${PROJECT_NAME} ${Allegro_LIBRARY_DIRS})
target_link_libraries(${PROJECT_NAME} ${aleglibs})

##config install
#install( 	TARGETS ${PROJECT_NAME}
#			RUNTIME DESTINATION bin
#			LIBRARY DESTINATION lib
#			ARCHIVE DESTINATION lib/static) # statics libs vão aqui
