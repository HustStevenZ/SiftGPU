cmake_minimum_required(VERSION 3.5)
project(SiftGPU)

add_definitions("-DWINDOW_PREFER_GLUT")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC -Wall -Wno-deprecated -pthread ")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -Wall -Wno-deprecated -pthread ")

if (APPLE)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -march=core2 -mfpmath=sse ")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=core2 -mfpmath=sse ")
endif ()
find_package(DevIL REQUIRED)
include_directories(${IL_INCLUDE_DIR})
link_libraries(${IL_LIBRARIES})
#link_libraries(IL_LIBRARIES)
if(NOT IL_FOUND)
    message(ERROR "IL not found")
endif(NOT IL_FOUND)

#########################################################
# FIND GLUT
#########################################################
find_package(Glut REQUIRED)
include_directories(${GLUT_INCLUDE_DIRS})
link_directories(${GLUT_LIBRARY_DIRS})
add_definitions(${GLUT_DEFINITIONS})
link_libraries(${GLUT_LIBRARIES})
if(NOT GLUT_FOUND)
    message(ERROR " GLUT not found!")
endif(NOT GLUT_FOUND)

#########################################################
# FIND OPENGL
#########################################################
find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})
link_libraries(${OPENGL_LIBRARIES})
if(NOT OPENGL_FOUND)
    message(ERROR " OPENGL not found!")
endif(NOT OPENGL_FOUND)


#########################################################
# FIND OPENCL
#########################################################
find_package(OpenCL)
if (OpenCL_FOUND)
    include_directories(${OpenCL_INCLUDE_DIRS})
    link_directories(${OpenCL_LIBRARIES})
    add_definitions("-DCL_SIFTGPU_ENABLED")
        link_libraries(${OpenCL_LIBRARIES})
    set(OPENCL_PROGRAM_SOURCE
            src/SiftGPU/ProgramCL.cpp
            src/SiftGPU/ProgramCL.h
            src/SiftGPU/PyramidCL.cpp
            src/SiftGPU/PyramidCL.h
            src/SiftGPU/CLTexImage.cpp
            src/SiftGPU/CLTexImage.h)
endif ()


#########################################################
# FIND GLEW
#########################################################
find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})
link_libraries(${GLEW_LIBRARIES})
if(NOT GLEW_FOUND)
    message("GLEW IS NOT FOUND!")
endif()
find_package(CUDA)
if(CUDA_FOUND)
    include_directories(${CUDA_INCLUDE_DIRS})
#    link_directories(${})
    set(CUDA_PROGRAM_SOURCE
            src/SiftGPU/CuTexImage.cpp
            src/SiftGPU/CuTexImage.h
            src/SiftGPU/PyramidCU.cpp
            src/SiftGPU/PyramidCU.h
            src/SiftGPU/ProgramCU.h
            src/SiftGPU/SiftMatchCU.cpp
            src/SiftGPU/SiftMatchCU.h)
endif()
set(SOURCE_FILES
        include/GL/glew.h
        include/GL/glut.h
        include/GL/wglew.h
        include/IL/il.h
        src/SiftGPU/FrameBufferObject.cpp
        src/SiftGPU/FrameBufferObject.h
        src/SiftGPU/GlobalUtil.cpp
        src/SiftGPU/GlobalUtil.h
        src/SiftGPU/GLTexImage.cpp
        src/SiftGPU/GLTexImage.h
        src/SiftGPU/LiteWindow.h
        src/SiftGPU/ProgramCG.cpp
        src/SiftGPU/ProgramCG.h
        src/SiftGPU/ProgramGLSL.cpp
        src/SiftGPU/ProgramGLSL.h
        src/SiftGPU/ProgramGPU.cpp
        src/SiftGPU/ProgramGPU.h
        src/SiftGPU/PyramidGL.cpp
        src/SiftGPU/PyramidGL.h
        src/SiftGPU/ShaderMan.cpp
        src/SiftGPU/ShaderMan.h
        src/SiftGPU/SiftGPU.cpp
        src/SiftGPU/SiftGPU.h
        src/SiftGPU/SiftMatch.cpp
        src/SiftGPU/SiftMatch.h
        src/SiftGPU/SiftPyramid.cpp
        src/SiftGPU/SiftPyramid.h
        ${OPENCL_PROGRAM_SOURCE}
        ${CUDA_PROGRAM_SOURCE})


#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

add_library(SiftGPUStatic STATIC ${SOURCE_FILES} )
add_library(SiftGPU SHARED ${SOURCE_FILES} )

set(TESTWINGLUT_SOURCE
        src/TestWin/BasicTestWin.cpp
        src/TestWin/BasicTestWin.h
        src/TestWin/TestWinGlut.cpp
        src/TestWin/TestWinGlut.h
        )
add_executable(TestWinGlut ${TESTWINGLUT_SOURCE})

target_link_libraries(TestWinGlut SiftGPU)

#add_executable(SiftGPU ${SOURCE_FILES})