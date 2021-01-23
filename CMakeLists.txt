cmake_minimum_required(VERSION 3.14)
project(PYCTP)

find_package(Python COMPONENTS Interpreter Development)
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/pybind11/include)
add_subdirectory(${PROJECT_SOURCE_DIR}/pybind11)
aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC)

pybind11_add_module(pyctp ${SRC})
target_link_libraries(pyctp PUBLIC pybind11::module /home/bohr/pyctp/lib/libthostmduserapi_se.so /home/bohr/pyctp/lib/libthosttraderapi_se.so)

