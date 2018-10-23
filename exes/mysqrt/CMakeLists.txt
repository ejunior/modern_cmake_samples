project(mysqrt VERSION 1.2.3 LANGUAGES CXX)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/version.h.in"
  "${PROJECT_BINARY_DIR}/version.h"
  )

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories(${PROJECT_BINARY_DIR})


# add the executable
add_executable(${PROJECT_NAME} mysqrt.cxx)
target_link_libraries (${PROJECT_NAME} Boost::boost)

include( CTest )

enable_testing()

add_test( 9e3 ${PROJECT_NAME} 9 )