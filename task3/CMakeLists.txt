cmake_minimum_required(VERSION 3.0)
project(SimpleLibrary)

include_directories(include)

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

#set(CMAKE_SYSROOT /home/lehahel/task3/sysroot-glibc-linaro-2.25-2019.12-armv8l-linux-gnueabihf)
#set(CMAKE_INSTALL_PREFIX /home/lehahel/task3/sysroot-glibc-linaro-2.25-2019.12-armv8l-linux-gnueabihf)

#set(CMAKE_C_COMPILER /home/lehahel/task3/gcc-linaro-7.5.0-2019.12-i686_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-gcc)
#set(CMAKE_CXX_COMPILER /home/lehahel/task3/gcc-linaro-7.5.0-2019.12-i686_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-g++)

set(CMAKE_C_COMPILER ${TOOLCHAIN}/arm-linux-gnueabihf-gcc)
set(CMAKE_CXX_COMPILER ${TOOLCHAIN}/arm-linux-gnueabihf-g++)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${SimpleLibrary_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${SimpleLibrary_SOURCE_DIR}/lib)
add_subdirectory(src)
add_executable(Main main.cpp)
add_executable(MainLib main_lib.cpp)

install(TARGETS Main MainLib DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)

target_link_libraries(MainLib buffer)
