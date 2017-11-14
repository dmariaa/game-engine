cmake_minimum_required(VERSION 3.8)
project(motorJuegos)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        src/GameEngineClasses/Model.cpp
        src/GameEngineClasses/Model.hpp
        src/GameEngineClasses/BasePrimitive.cpp
        src/GameEngineClasses/BasePrimitive.hpp
        src/GameEngineClasses/BoundingBox.cpp
        src/GameEngineClasses/BoundingBox.hpp
        src/GameEngineClasses/Camera.cpp
        src/GameEngineClasses/Camera.hpp
        src/GameEngineClasses/CameraFPS.cpp
        src/GameEngineClasses/CameraFPS.hpp
        src/GameEngineClasses/Color.cpp
        src/GameEngineClasses/Color.hpp
        src/GameEngineClasses/CompoundPrimitive.cpp
        src/GameEngineClasses/CompoundPrimitive.hpp
        src/GameEngineClasses/Cube.cpp
        src/GameEngineClasses/Cube.hpp
        src/GameEngineClasses/Game.cpp
        src/GameEngineClasses/Game.hpp
        src/GameEngineClasses/InputDefinitions.h
        src/GameEngineClasses/InputHandler.cpp
        src/GameEngineClasses/InputHandler.hpp
        src/GameEngineClasses/Plane.cpp
        src/GameEngineClasses/Plane.hpp
        src/GameEngineClasses/Scene.cpp
        src/GameEngineClasses/Scene.hpp
        src/GameEngineClasses/Sphere.cpp
        src/GameEngineClasses/Sphere.hpp
        src/GameEngineClasses/Texture.cpp
        src/GameEngineClasses/Texture.hpp
        src/GameEngineClasses/Triangle.cpp
        src/GameEngineClasses/Triangle.hpp
        src/GameEngineClasses/Vertex3D.cpp
        src/GameEngineClasses/Vertex3D.hpp
        src/main.cpp)

add_compile_options(-Wno-deprecated-declarations)

set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/build/")

set(LIBRARY_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/build/")

include_directories(
        /usr/local/include
)

find_library(opengl_lib OpenGL)
find_library(glut_lib GLUT)

set(frameworks
        ${opengl_lib}
        ${glut_lib})

add_executable(motorJuegos ${SOURCE_FILES})
target_link_libraries(motorJuegos ${frameworks})