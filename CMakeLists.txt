cmake_minimum_required(VERSION 3.24)
project(cadastro_de_pessoas C)

set(CMAKE_C_STANDARD 99)

add_executable(cadastro_de_pessoas main.c cadastro_filmes.h cadastro_filme.c)
