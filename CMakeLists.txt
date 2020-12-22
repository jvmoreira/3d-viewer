cmake_minimum_required(VERSION 3.16)
project(3DViewer C)

set(CMAKE_C_STANDARD 11)

add_executable(3DViewer
  src/main.c
  src/object/vertex.c
  src/object/vertex.h
)
