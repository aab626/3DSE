cmake_minimum_required(VERSION 3.15)
project(SpaceEngine
    LANGUAGES CXX
)

message(STATUS "CMAKE_SOURCE_DIR        : ${CMAKE_SOURCE_DIR}")
message(STATUS "CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS "CMAKE_BUILD_TYPE:         ${CMAKE_BUILD_TYPE}")
message(STATUS "pybind11_INCLUDE_DIRS:    ${pybind11_INCLUDE_DIRS}")

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

include(FetchContent)
FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt
    GIT_TAG        e69e5f977d458f2650bb346dadf2ad30c5320281 # 10.2.1
)
FetchContent_MakeAvailable(fmt)

# 4. Engine Target
# Find all .cpp files
file (GLOB ENGINE_ALL_SOURCES
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_SOURCE_DIR}/src/**/*.cpp"
)

set(ENGINE_LIB_SOURCES ${ENGINE_ALL_SOURCES})
list(REMOVE_ITEM ENGINE_LIB_SOURCES "${CMAKE_SOURCE_DIR}/src/main.cpp")

set(ENGINE_EXE_SOURCES ${ENGINE_ALL_SOURCES})
list(REMOVE_ITEM ENGINE_EXE_SOURCES "${CMAKE_SOURCE_DIR}/src/python_binds.cpp")


message(STATUS "ENGINE_LIB_SOURCES: ${ENGINE_LIB_SOURCES}")
message(STATUS "ENGINE_EXE_SOURCES: ${ENGINE_EXE_SOURCES}")


# Configure library output
add_library(engine SHARED ${ENGINE_LIB_SOURCES})

target_include_directories(engine PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${Python_INCLUDE_DIRS}
    ${pybind11_INCLUDE_DIRS}
    ${OPENGL_INCLUDE_DIR}
)

target_link_libraries(engine PRIVATE
    fmt::fmt
    pybind11::module
    ${Python_LIBRARIES}
    ${OPENGL_LIBRARIES}
)

set_target_properties(engine PROPERTIES 
    OUTPUT_NAME "engine_lib"
    CXX_STANDARD 17
    SUFFIX ".pyd"
)

# Configure executable
add_executable(engine_exe ${ENGINE_EXE_SOURCES})

target_include_directories(engine_exe PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(engine_exe PRIVATE 
fmt::fmt
)

set_target_properties(engine_exe PROPERTIES 
    OUTPUT_NAME "engine"
    CXX_STANDARD 17
    SUFFIX ".exe"
)
