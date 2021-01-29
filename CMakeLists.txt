cmake_minimum_required(VERSION 3.6.2)
project(automat)

set(CMAKE_CXX_STANDARD 14)

find_package(Threads)

set(SOURCE_FILES
        1_napoj.cpp
        2_TypNapoja.cpp
        3_automat.cpp
        4_vyroba.cpp
        5_mincovka.cpp

        testyUloha_1.cpp
        testyUloha_2.cpp
        testyUloha_3.cpp
        testyUloha_4.cpp
        testyUloha_5.cpp

        GoogleTest/gtest-death-test.cc
        GoogleTest/gtest-filepath.cc
        GoogleTest/gtest-port.cc
        GoogleTest/gtest-printers.cc
        GoogleTest/gtest-test-part.cc
        GoogleTest/gtest-typed-test.cc
        GoogleTest/gtest.cc
        GoogleTest/gtest_main.cc)

include_directories(GoogleTest)
add_executable(cvicenie6 ${SOURCE_FILES})
target_link_libraries(cvicenie6 ${CMAKE_THREAD_LIBS_INIT})