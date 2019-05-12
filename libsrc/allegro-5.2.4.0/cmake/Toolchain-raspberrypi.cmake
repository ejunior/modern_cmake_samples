SET(ALLEGRO_RASPBERRYPI 1)
SET(CMAKE_SYSTEM_NAME Linux)

IF("${TOOLCHAIN_ROOT}" STREQUAL "")
   SET(TOOLCHAIN_ROOT "/usr/bin")
ENDIF("${TOOLCHAIN_ROOT}" STREQUAL "")

IF("${TOOLCHAIN_PREFIX}" STREQUAL "")
   SET(TOOLCHAIN_PREFIX "")
ENDIF("${TOOLCHAIN_PREFIX}" STREQUAL "")

IF("${TOOLCHAIN_SUFFIX}" STREQUAL "")
   SET(TOOLCHAIN_SUFFIX "")
ENDIF("${TOOLCHAIN_SUFFIX}" STREQUAL "")

SET(CMAKE_C_FLAGS "-march=armv6 -mfpu=vfp -mfloat-abi=hard -Os")
SET(CMAKE_CXX_FLAGS "-march=armv6 -mfpu=vfp -mfloat-abi=hard -Os")

if(NOT DISTCC)
    set(CMAKE_C_COMPILER ${TOOLCHAIN_ROOT}/${TOOLCHAIN_PREFIX}gcc${TOOLCHAIN_SUFFIX})
    set(CMAKE_CXX_COMPILER ${TOOLCHAIN_ROOT}/${TOOLCHAIN_PREFIX}g++${TOOLCHAIN_SUFFIX})
endif()
set(CMAKE_LINKER ${TOOLCHAIN_ROOT}/${TOOLCHAIN_PREFIX}ld${TOOLCHAIN_SUFFIX})
set(CMAKE_NM ${TOOLCHAIN_ROOT}/${TOOLCHAIN_PREFIX}nm${TOOLCHAIN_SUFFIX})
set(CMAKE_OBJCOPY ${TOOLCHAIN_ROOT}/${TOOLCHAIN_PREFIX}objcopy${TOOLCHAIN_SUFFIX})
set(CMAKE_OBJDUMP ${TOOLCHAIN_ROOT}/${TOOLCHAIN_PREFIX}objdump${TOOLCHAIN_SUFFIX})
set(CMAKE_STRIP ${TOOLCHAIN_ROOT}/${TOOLCHAIN_PREFIX}strip${TOOLCHAIN_SUFFIX})
set(CMAKE_RANLIB ${TOOLCHAIN_ROOT}/${TOOLCHAIN_PREFIX}ranlib${TOOLCHAIN_SUFFIX})

SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

SET(ALLEGRO_CFG_OPENGLES 1)
SET(ALLEGRO_CFG_OPENGLES2 1)
SET(ALLEGRO_CFG_OPENGL_PROGRAMMABLE_PIPELINE 1)

SET(ALLEGRO_EXCLUDE_GLX 1)

# XXX incorporate into FindOpenGLES/2
set(OPENGL_LIBRARIES "/opt/vc/lib/libGLESv2.so;/opt/vc/lib/libEGL.so;/opt/vc/lib/libbcm_host.so")
set(OPENGL_gl_LIBRARY "/opt/vc/lib/libGLESv2.so;/opt/vc/lib/libEGL.so;/opt/vc/lib/libbcm_host.so")
set(OPENGL_glu_LIBRARY "")

include_directories(
   "/opt/vc/include"
   "/opt/vc/include/interface/vcos/pthreads"
   "/opt/vc/include/interface/vmcs_host/linux"
)
