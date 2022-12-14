cmake_minimum_required(VERSION 3.5)
project(ROOT2CSV VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(external/wRATter)

list(APPEND CMAKE_PREFIX_PATH $ENV{ROOTSYS})
#---Locate the ROOT package and defines a number of variables (e.g. ROOT_INCLUDE_DIRS)
find_package(ROOT 6.24 CONFIG REQUIRED)
if(NOT ROOT_FOUND)
    message(STATUS "ROOT package not found.")
    return()
endif()

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.50 REQUIRED COMPONENTS filesystem)
message(STATUS "Boost version: ${Boost_VERSION}")

#----------------------------------------------------------------------------
# Locate sources and headers for this project
# ## NOT NEEDED FOR DICT
include_directories(
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/external/wRATter/include
        ${ROOT_INCLUDE_DIRS}
        ${Boost_INCLUDE_DIRS}
        $ENV{RATROOT}/include
)

#----------------------------------------------------------------------------
# Locate RATROOT Libs
#
LINK_DIRECTORIES($ENV{RATROOT}/lib)
LINK_DIRECTORIES($ENV{GEANT4SYS}/lib)

###
add_executable(ROOT2CSV ROOT2CSV.cc)
target_link_libraries(ROOT2CSV PUBLIC wRATter ${ROOT_LIBRARIES})
