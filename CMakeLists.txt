cmake_minimum_required(VERSION 3.21)
project(minishell C)

set(CMAKE_C_STANDARD 99)

add_executable(minishell includes/minishell.h
        srcs/main.c
        srcs/minishell_prepare.c
        srcs/minishell_start.c
        )
