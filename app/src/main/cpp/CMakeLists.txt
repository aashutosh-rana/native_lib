cmake_minimum_required(VERSION 3.22.1)

project("myapplication")

add_library(
        myapplication
        SHARED
        native-lib.cpp)

find_library(
        log-lib
        log
        android)

target_link_libraries(
        myapplication
        android
        ${native-lib}
        ${log-lib})
