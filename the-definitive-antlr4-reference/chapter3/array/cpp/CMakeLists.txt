cmake_minimum_required(VERSION 3.12)

project(antlr4_study CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

##############################################################################################################

function(collect_source_files root_dir)
    file(GLOB_RECURSE LOCAL_SRC_FILES CONFIGURE_DEPENDS ${root_dir}/*.cpp)
    file(GLOB_RECURSE LOCAL_HEADER_FILES CONFIGURE_DEPENDS ${root_dir}/*.h)
    set(SRC_FILES ${LOCAL_SRC_FILES} PARENT_SCOPE)
    set(HEADER_FILES ${LOCAL_HEADER_FILES} PARENT_SCOPE)
endfunction()

collect_source_files(${CMAKE_SOURCE_DIR}/src)


# Check if source files are found
if(NOT SRC_FILES)
    message(FATAL_ERROR "No source files found in ${CMAKE_SOURCE_DIR}/src")
endif()

##############################################################################################################

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
find_package(antlr4-runtime REQUIRED)

add_library(applicationa_core STATIC ${SRC_FILES} ${HEADER_FILES})
target_include_directories(applicationa_core PUBLIC antlr4_static)
target_link_libraries(applicationa_core PUBLIC antlr4_static)

add_executable(${PROJECT_NAME} src/main.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC applicationa_core antlr4_static)
target_link_libraries(${PROJECT_NAME} PUBLIC applicationa_core)

##############################################################################################################

if (CMAKE_BUILD_TYPE MATCHES Debug)

	target_compile_options(${PROJECT_NAME}  PRIVATE 
		-Wall
		-Wextra
		-g 
		-O0
    )
endif()

##############################################################################################################
