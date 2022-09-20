cmake_minimum_required(VERSION 3.21)
project(minishell C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror -O2")

file(GLOB LIBFT_SRCS "libraries/libft/srcs/*.c")
add_library(ft STATIC ${LIBFT_SRCS})



file(GLOB MINISHELL_PARSER "srcs/parser/*.c")
file(GLOB MINISHELL_EXECUTOR "srcs/executor/*.c" "srcs/executor/built-in/*.c")
file(GLOB MINISHELL_UTILS "srcs/utils/*.c")
add_executable(minishell
		${MINISHELL_PARSER}
		${MINISHELL_EXECUTOR}
		${MINISHELL_UTILS}
		srcs/main.c
		)

target_include_directories(ft PRIVATE libraries/libft)
target_include_directories(minishell PRIVATE includes)

target_link_libraries(minishell ft)
target_link_libraries(minishell readline)
