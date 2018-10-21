cmake_minimum_required(VERSION 3.12)
project(AES128 C)

set(CMAKE_C_COMPILER)
set(CMAKE_C_STANDARD 11)

add_executable(AES128 src/utils.c src/includes/utils.h src/includes/byte.h src/includes/constants.h src/main.c
        src/addRoundKey.c src/subBytes.c src/mixColumns.c src/aes.c src/includes/aes.h src/shiftRows.c
        src/expandKey.c src/includes/addRoundKey.h src/includes/expandKey.h src/includes/shiftRows.h
        src/includes/subBytes.h src/includes/mixColumns.h)
