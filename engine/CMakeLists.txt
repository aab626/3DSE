cmake_minimum_required(VERSION 3.15)
project(SpaceEngine)

set(Python_INCLUDE_DIRS "C:/Users/a626/AppData/Local/Programs/Python/Python312/Include")
set(Python_LIBRARIES "C:/Users/a626/projects/space_game/.venv/Lib/site-packages")

# 1. Python Configuration
set(Python_EXECUTABLE "C:/Users/a626/projects/space_game/.venv/Scripts/python.exe")
find_package(Python REQUIRED COMPONENTS Interpreter Development)
include_directories(${Python_INCLUDE_DIRS})
link_directories(${Python_LIBRARY_DIRS})

# 2. PyBind11 Setup
list(APPEND CMAKE_PREFIX_PATH "C:/Users/a626/projects/space_game/.venv/Lib/site-packages/pybind11/share/cmake/pybind11")
find_package(pybind11 REQUIRED)
include_directories(${pybind11_INCLUDE_DIRS})

# 3. OpenGL Configuration
find_package(OpenGL REQUIRED)

# 4. Engine Target
add_library(engine SHARED
    src/engine.cpp
    src/GameObject.cpp
    src/Module.cpp
    src/modules/RenderModule.cpp
)

# 5. Target Includes (Modern CMake style)
target_include_directories(engine PRIVATE
    ${CMAKE_SOURCE_DIR}/engine/include
    ${CMAKE_SOURCE_DIR}/engine/include/modules
    ${Python_INCLUDE_DIRS}
    ${pybind11_INCLUDE_DIRS}
    ${OPENGL_INCLUDE_DIR}
)

# 6. Target Linking (Updated OpenGL linking)
target_link_libraries(engine PRIVATE 
    pybind11::module
    ${Python_LIBRARIES}
    ${OPENGL_LIBRARIES}  # This will link opengl32.lib automatically
)

# 7. Output Configuration
set_target_properties(engine PROPERTIES
    SUFFIX ".pyd"
    OUTPUT_NAME "engine"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../game"
    LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/../game"
    LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/../game"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../game"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/../game"
    RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/../game"
    CXX_STANDARD 17
)