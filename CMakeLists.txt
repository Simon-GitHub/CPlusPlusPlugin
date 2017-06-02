set(CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS TRUE)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

IF(WIN32)
    CMAKE_MINIMUM_REQUIRED(VERSION 2.8.2 FATAL_ERROR)
ELSE(WIN32)
    IF(APPLE)
        CMAKE_MINIMUM_REQUIRED(VERSION 2.8.2 FATAL_ERROR)
    ELSE(APPLE)
        CMAKE_MINIMUM_REQUIRED(VERSION 2.8.2 FATAL_ERROR)
    ENDIF(APPLE)
ENDIF(WIN32)
if(COMMAND cmake_policy)
    # Works around warnings libraries linked against that don't
    # have absolute paths (e.g. -lpthreads)
    cmake_policy(SET CMP0003 NEW)

    # Works around warnings about escaped quotes in ADD_DEFINITIONS
    # statements.
    cmake_policy(SET CMP0005 NEW)

    cmake_policy(SET CMP0020 NEW)
    cmake_policy(SET CMP0043 NEW)

    # cmake-2.6.1 introduces policy cmp0008 decide how to treat full path libraries that do not appear to be valid library file names
    # quote from cvslog "Such libraries worked by accident in the VS IDE and Xcode generators in CMake 2.4 and below."
    if(${CMAKE_MAJOR_VERSION} EQUAL 2 AND ${CMAKE_MINOR_VERSION} GREATER 4 AND ${CMAKE_PATCH_VERSION} GREATER 0)
        cmake_policy(SET CMP0008 OLD)
    endif()
endif()

#FIND_PACKAGE(QT4)

#project
PROJECT(CPlusPlusPlugin)

#sub directory
SET(PluginCore_INCLUDE ${PROJECT_SOURCE_DIR}/PluginCore/include)
SET(PluginCore_LIB ${CMAKE_CURRENT_BINARY_DIR}/bin)

#set out path
SET(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR}/bin)
SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR}/bin)


OPTION(BUILD_PROJECT_PluginCore "Enable to build project PluginCore" OFF)
IF(BUILD_PROJECT_PluginCore)
	ADD_SUBDIRECTORY(PluginCore)
ENDIF(BUILD_PROJECT_PluginCore)

OPTION(BUILD_PROJECT_PluginShape "Enable to build project PluginShape" OFF)
IF(BUILD_PROJECT_PluginShape)
	ADD_SUBDIRECTORY(PluginShape)
ENDIF(BUILD_PROJECT_PluginShape)

OPTION(BUILD_PROJECT_PluginTest "Enable to build project PluginTest" OFF)
IF(BUILD_PROJECT_PluginTest)
	ADD_SUBDIRECTORY(PluginTest)
ENDIF(BUILD_PROJECT_PluginTest)

