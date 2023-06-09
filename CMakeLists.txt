cmake_minimum_required(VERSION 3.0.0)
project(zad7 VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories("src")
file(GLOB_RECURSE zad7_src "src/*.hpp" "src/*.cpp")


find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)

add_executable(zad7 ${zad7_src})
#set_target_properties(zad7 PROPERTIES COMPILE_FLAGS "-m32" LINK_FLAGS "-m32")

target_link_libraries(zad7 sfml-graphics)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
