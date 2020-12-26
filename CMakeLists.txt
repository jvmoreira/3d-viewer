cmake_minimum_required(VERSION 3.16)
project(3d_viewer)
project(3d_viewer_tests)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
  src/object/vertex.cpp
  src/object/vertex.h
)

set(TESTS_FILES
  tests/run.cpp
  tests/test-case.h
  tests/object/vertex-test.cpp
  tests/object/vertex-test.h
)

add_executable(3d_viewer
  src/main.cpp
  ${SOURCE_FILES}
)

add_executable(3d_viewer_tests
  ${TESTS_FILES}
  ${SOURCE_FILES}
)

target_include_directories(3d_viewer_tests PUBLIC src tests)
