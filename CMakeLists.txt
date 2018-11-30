cmake_minimum_required(VERSION 3.0)

project(double_linked)

add_library(double_linked double_linked.h)
add_executable(test test.c double_linked.h)
