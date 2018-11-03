cmake_minimum_required(VERSION 3.0)

project(pman VERSION 0.0.3 LANGUAGES CXX)

## OU substitui por isso aqui (ajuda no jenkins)
#set(VERSION_MAJOR "0") 
#set(VERSION_MINOR "0")
#set(VERSION_PATCH "2")
#set(VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")

# Must use GNUInstallDirs to install libraries into correct
# locations on all platforms.
#include(GNUInstallDirs)

#set(ALLEGRO_VERSION "5.2.4.0")
#set(allegro5_DIR ${PROJECT_SOURCE_DIR}/libsrc/allegro-${ALLEGRO_VERSION})
enable_testing()

find_package(BOOST REQUIRED COMPONENTS system filesystem chrono)

# set environmet
include_directories(${PROJECT_SOURCE_DIR}/include)
add_definitions(-DTEST_DEF) # add definitions

#target_compile_features(${PROJECT_NAME} PRIVATE CXX_STANDARD 11)

## external inlcudes libs
#link_directories(${PROJECT_SOURCE_DIR}/external/lib)  
message("Binary tree Path:  ${PROJECT_BINARY_DIR}")
message("Source tree Path:  ${PROJECT_SOURCE_DIR}")

# add subfolders
add_subdirectory(exes)
add_subdirectory(dlls)
add_subdirectory(libsrc)