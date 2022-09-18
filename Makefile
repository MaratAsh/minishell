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

INCLUDE	=	./libraries/libft/libft.a
I_MAKE	=	make -C $(dir $(INCLUDE))

FLDR_S  =   srcs/
FLDR_O  =   objs/
FLDR_H  =   includes/

SRCS    =   minishell_prepare.c  minishell_start.c signal_handler.c sh.c

OBJS    =   ${SRCS:.c=.o}

SRCS_WD =   $(addprefix ${FLDR_S},${SRCS})
OBJS_WD =   $(addprefix ${FLDR_O},${OBJS})
HEAD_WD =   $(addprefix ${FLDR_H},${HEADER})

FLAGS   =   -Wall -Wextra -Werror

all: $(FLDR_O) $(NAME)

$(FLDR_O):
		mkdir $(FLDR_O)

lib:
		${I_MAKE} bonus
		${I_MAKE}

$(NAME): ${FLDR_O}main.o ${OBJS_WD} ${HEAD_WD} lib
		${CC} ${FLAGS} -lreadline $(OBJS_WD) ${FLDR_O}main.o -I. $(INCLUDE) -o $(NAME)

clean:
		${I_MAKE} clean
		rm -rf ${FLDR_O}main.o ${OBJS_WD} ${OBJS_B_WD}

fclean:
		${I_MAKE} fclean
		rm -rf ${FLDR_O}main.o ${OBJS_WD} ${OBJS_B_WD} ${NAME} ${NAME_B}

${FLDR_O}%.o : ${FLDR_S}%.c ${HEAD_WD}
		${CC} ${FLAGS} -I$(FLDR_H) -c $< -o $@

re: fclean all

.PHONY: all clean fclean re