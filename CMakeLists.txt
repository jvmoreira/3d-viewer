cmake_minimum_required(VERSION 3.16)
project(3d-viewer C)
project(3d-viewer-tests C)

set(CMAKE_C_STANDARD 11)

include_directories(src tests)

set(source_files
  src/stdlib-helper.h
  src/object/vertex.c
  src/object/vertex.h
)

add_executable(3d-viewer
  src/main.c
  ${source_files}
)

add_executable(3d-viewer-tests
  tests/test.c
  tests/test-case.c
  tests/test-case.h
  ${source_files}
  tests/object/vertex-test.c
  tests/object/vertex-test.h
)
