cmake_minimum_required(VERSION 3.22)
project(SDB)
add_executable(SDB test.c src/SimpleDb.c)
target_include_directories(SDB PUBLIC include include/)
