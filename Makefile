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
HEADER  =   minishell.h

FLDR_S  =   srcs/
FLDR_O  =   objs/

SRCS    =   minishell_prepare.c  minishell_start.c

OBJS    =   ${SRCS:.c=.o}

SRCS_WD =   $(addprefix ${FLDR_S},${SRCS})
OBJS_WD =   $(addprefix ${FLDR_O},${OBJS})

FLAGS   =   -Wall -Wextra -Werror

all: $(FLDR_O) $(NAME)

$(FLDR_O):
		mkdir $(FLDR_O)

$(NAME): ${FLDR_O}main.o ${OBJS_WD} ${HEADER}
		${CC} ${FLAGS} $(OBJS_WD) ${FLDR_O}main.o -o $(NAME)

clean:
		rm -rf ${FLDR_O}main.o ${OBJS_WD} ${OBJS_B_WD}

fclean:
		rm -rf ${FLDR_O}main.o ${OBJS_WD} ${OBJS_B_WD} ${NAME} ${NAME_B}

${FLDR_O}%.o : ${FLDR_S}%.c ${HEADER}
		${CC} ${FLAGS} -c $< -o $@

${FLDR_O}%.o : %.c ${HEADER}
		${CC} ${FLAGS} -c $< -o $@

re: fclean all

.PHONY: all clean fclean re