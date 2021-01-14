cmake_minimum_required(VERSION 3.14)
project(lab3 VERSION 1.0)
aux_source_directory(${PROJECT_SOURCE_DIR}/ src)
add_executable(main ${src})
