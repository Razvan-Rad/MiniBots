cmake_minimum_required(VERSION 3.10)
include(GNUInstallDirs)

#Project specific
project(Toolbox VERSION 0.1 DESCRIPTION " :) ")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(LIBRARY_OUTPUT_PATH  ${CMAKE_BINARY_DIR}/lib)

if(UNIX)
    message("Building for UNIX based OS - \"" ${CMAKE_HOST_SYSTEM_NAME} "\"")
else()
    message("System may not be supported")
endif()

# Library specific
add_library(debugger SHARED 
    src/debugger.cpp)
add_library(observer SHARED 
    src/observer.cpp)
set_target_properties(debugger PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(debugger PROPERTIES PUBLIC_HEADER lib/debugger.hpp)


set_target_properties(observer PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(observer PROPERTIES PUBLIC_HEADER lib/observer.hpp)

target_include_directories(debugger PRIVATE .)
target_include_directories(observer PRIVATE .)

install(TARGETS debugger
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# GTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# individual tests
add_executable(
    tests
    test/debuggerTest.cpp
)
target_link_libraries(
    tests
    gtest_main
)
include(GoogleTest)
gtest_discover_tests(tests)


# if(${CMAKE_SYSTEM_NAME} MATCHES Darwin)
# {
#     add_definitions(-_SYSNAME="MacOS")
# }
# elseif(${CMAKE_SYSTEM_NAME} MATCHES Windows)
# {
#     add_definitions(-_SYSNAME="Windows")
# }
# endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
add_executable(toolbox main.cpp)
target_link_libraries(toolbox debugger)