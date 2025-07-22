cmake_minimum_required(VERSION 3.15)
project(SpaceEngine)

message(STATUS "CMAKE_SOURCE_DIR        : ${CMAKE_SOURCE_DIR}")
message(STATUS "CMAKE_CURRENT_SOURCE_DIR:${CMAKE_CURRENT_SOURCE_DIR}")

set(Python_INCLUDE_DIRS "C:/Users/a626/AppData/Local/Programs/Python/Python312/Include")
set(Python_LIBRARIES "C:/Users/a626/projects/space_game/.venv/Lib/site-packages")

# 1. Python Configuration
set(Python_EXECUTABLE "C:/Users/a626/projects/space_game/.venv/Scripts/python.exe")
find_package(Python REQUIRED COMPONENTS Interpreter Development)

# 2. PyBind11 Setup
list(APPEND CMAKE_PREFIX_PATH "C:/Users/a626/projects/space_game/.venv/Lib/site-packages/pybind11/share/cmake/pybind11")
find_package(pybind11 REQUIRED)

# 3. OpenGL Configuration
find_package(OpenGL REQUIRED)

# 4. Engine Target
# Find all .cpp files
file (GLOB ENGINE_SOURCES
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_SOURCE_DIR}/src/**/*.cpp"
)

message(STATUS "ENGINE_SOURCES: ${ENGINE_SOURCES}")

add_library(engine SHARED ${ENGINE_SOURCES})

# 5. Target Includes
target_include_directories(engine PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${Python_INCLUDE_DIRS}
    ${pybind11_INCLUDE_DIRS}
    ${OPENGL_INCLUDE_DIR}
)

# 6. Target Linking
target_link_libraries(engine PRIVATE 
    pybind11::module
    ${Python_LIBRARIES}
    ${OPENGL_LIBRARIES}
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