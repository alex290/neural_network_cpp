cmake_minimum_required(VERSION 3.20.0)
project(Neuro VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

IF (WIN32)
  set(wxWidgets_ROOT_DIR "c:/wxwidgets/3.2.1")
  set(wxWidgets_LIB_DIR "c:/wxwidgets/3.2.1/lib/gcc_x64_dll")
ENDIF()

# Подключем блиблиотеку CPPFLOW и Tensorflow
include_directories(${CMAKE_SOURCE_DIR}/include)
link_directories(${CMAKE_SOURCE_DIR}/lib)



find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})

file(GLOB project
    src/*
)

add_executable(${PROJECT_NAME} ${project})

if(wxWidgets_FOUND)
    target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
    target_include_directories(${PROJECT_NAME} PRIVATE ${wxWidgets_INCLUDE_DIRS})
    message(STATUS "Found wxWidgets ${wxWidgets_VERSION_STRING}")
else()
    message(STATUS "wxWidgets Not Found")
endif()

# Подключем блиблиотеку CPPFLOW и Tensorflow
target_link_libraries(${PROJECT_NAME} tensorflow)

if(WIN32)
    configure_file(${CMAKE_SOURCE_DIR}/lib/tensorflow.dll ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/tensorflow.dll COPYONLY)
ENDIF()