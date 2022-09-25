# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 1970/01/01 00:00:00 by alcierra          #+#    #+#              #
#    Updated: 1970/01/01 00:00:00 by alcierra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    =   minishell
HEADER  =   includes/minishell.h \
            includes/minishell_executor.h \
            includes/minishell_parser.h

INCLUDE	=	./libraries/libft/libft.a
I_MAKE	=	make -C $(dir $(INCLUDE))

FLDR_S      = srcs/
FLDR_S_EXEC = srcs/executor/
FLDR_S_PARS = srcs/parser/
FLDR_S_BTIN = srcs/executor/built-in/
FLDR_S_UTIL = srcs/utils/
FLDR_O      = objs/
FLDR_O_EXEC = objs/executor/
FLDR_O_PARS = objs/parser/
FLDR_O_BTIN = objs/executor/built-in/
FLDR_O_UTIL = objs/utils/

SRCS      =   main.c
SRCS_EXEC =   executor.c     exec.c         pipe.c
SRCS_PARS =   constructors.c parser.c       utils.c
SRCS_BTIN =   env.c          exit.c
SRCS_UTIL =   env_edit.c     env_get.c      env_insert.c   exit_alert.c \
              free_token.c   init_app.c     init_env.c

OBJS      =   ${SRCS:.c=.o}
OBJS_EXEC =   ${SRCS_EXEC:.c=.o}
OBJS_PARS =   ${SRCS_PARS:.c=.o}
OBJS_BTIN =   ${SRCS_BTIN:.c=.o}
OBJS_UTIL =   ${SRCS_UTIL:.c=.o}

SRCS_WD =   $(addprefix ${FLDR_S},${SRCS}) \
            $(addprefix ${FLDR_S_EXEC},${SRCS_EXEC}) \
            $(addprefix ${FLDR_S_PARS},${SRCS_PARS}) \
            $(addprefix ${FLDR_S_BTIN},${SRCS_BTIN}) \
            $(addprefix ${FLDR_S_UTIL},${SRCS_UTIL}) \

OBJS_WD =   $(addprefix ${FLDR_O},${OBJS}) \
            $(addprefix ${FLDR_O_EXEC},${OBJS_EXEC}) \
            $(addprefix ${FLDR_O_PARS},${OBJS_PARS}) \
            $(addprefix ${FLDR_O_BTIN},${OBJS_BTIN}) \
            $(addprefix ${FLDR_O_UTIL},${OBJS_UTIL}) \

CC      =   gcc
FLAGS   =   -Wall -Wextra -Werror -I./includes

all: $(FLDR_O) $(FLDR_O_EXEC) $(FLDR_O_PARS) $(FLDR_O_BTIN) $(FLDR_O_UTIL) $(NAME)

lib:
	${I_MAKE} bonus
	${I_MAKE}

$(FLDR_O):
	mkdir -p $(FLDR_O)

$(FLDR_O_EXEC):
	mkdir -p $(FLDR_O_EXEC)

$(FLDR_O_PARS):
	mkdir -p $(FLDR_O_PARS)

$(FLDR_O_BTIN):
	mkdir -p $(FLDR_O_BTIN)

$(FLDR_O_UTIL):
	mkdir -p $(FLDR_O_UTIL)

$(NAME): lib ${OBJS_WD} ${HEADER}
	${CC} ${FLAGS} $(OBJS_WD)  -I. $(INCLUDE) -lreadline -o $(NAME)

clean:
	${I_MAKE} clean
	rm -rf ${OBJS_WD} ${OBJS_B_WD}

fclean:
	${I_MAKE} fclean
	rm -rf $(FLDR_O) $(FLDR_O_EXEC) $(FLDR_O_PARS) $(FLDR_O_BTIN) $(FLDR_O_UTIL)

${FLDR_O}%.o : ${FLDR_S}%.c ${HEADER}
	${CC} ${FLAGS} -c $< -o $@

${FLDR_O_EXEC}%.o : ${FLDR_S_EXEC}%.c ${HEADER}
	${CC} ${FLAGS} -c $< -o $@

${FLDR_O_UTIL}%.o : ${FLDR_S_UTIL}%.c ${HEADER}
	${CC} ${FLAGS} -c $< -o $@

${SRCS_BTIN}%.o : ${SRCS_BTIN}%.c ${HEADER}
	${CC} ${FLAGS} -c $< -o $@

${FLDR_O_PARS}%.o : ${FLDR_S_PARS}%.c ${HEADER}
	${CC} ${FLAGS} -c $< -o $@

re:
	rm -rf ${OBJS_WD} ${OBJS_B_WD} ${NAME} ${NAME_B}
	make all

.PHONY: all clean fclean re
