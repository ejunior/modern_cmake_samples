# pman_cmake

This project is a sandbox to learn how to structure a C++ project using Modern CMake (3.5+)


- DEPENDENCIES:
   - CMake 3.5
   - BOOST
   - Allegro 5.2
   
- intended compatibility:
   - GCC(linux) or 
    - MinGW (Windows/Linux) 
    - MSVC
    - clang (OSX)

- PROJECT OBJECTIVES:
   - Requirements:
      - build and install its dependecies correctly on Linux, Windows and OSX.
        -does not worked as members of the project. We should install accordingly
         to each dependency
      - minimal dependency management
      - export libraries (and use it as internal dependencies)
      - modules with different built configurations 
      - deal with multiple compiller params for each module

   - Dependencies:
      - Boost (external - to learn how to use find_package)
      - Allegro (integrate with a library built without cmake package support)

   - DESCRIPTION
    - mysqrt
        - get the version of the app from the integration and put it in the code
    - 
   
