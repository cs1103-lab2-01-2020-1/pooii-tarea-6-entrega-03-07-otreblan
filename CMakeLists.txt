cmake_minimum_required(VERSION 3.10)

project(tarea6)

file(GLOB SOURCES "src/*", "src/clases/*")

add_executable(tarea6 ${SOURCES})
