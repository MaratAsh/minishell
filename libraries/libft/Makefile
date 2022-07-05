# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/06 12:53:24 by alcierra          #+#    #+#              #
#    Updated: 2022/03/04 17:51:00 by alcierra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    =   libft.a
HEADER  =   libft.h

FLDR_S  =   srcs/
FLDR_O  =   objs/

SRCS    =   ft_isalpha.c         ft_isdigit.c         ft_isalnum.c       \
            ft_isascii.c         ft_isprint.c         ft_strlen.c        \
            ft_memset.c          ft_bzero.c           ft_memcpy.c        \
            ft_memmove.c         ft_strlcpy.c         ft_strlcat.c       \
            ft_toupper.c         ft_tolower.c         ft_strchr.c        \
            ft_strrchr.c         ft_strncmp.c         ft_memchr.c        \
            ft_memcmp.c          ft_strnstr.c         ft_atoi.c          \
            ft_calloc.c          ft_strdup.c                             \
            ft_substr.c          ft_strjoin.c         ft_strtrim.c       \
            ft_split.c           ft_itoa.c            ft_strmapi.c       \
            ft_striteri.c        ft_putchar_fd.c      ft_putstr_fd.c     \
            ft_putendl_fd.c      ft_putnbr_fd.c       ft_split_inline.c  \
            string_init.c        string_put_fd.c

B_SRCS  =   ft_lstnew_bonus.c       ft_lstadd_front_bonus.c      ft_lstsize_bonus.c      \
            ft_lstlast_bonus.c      ft_lstadd_back_bonus.c       ft_lstdelone_bonus.c    \
            ft_lstclear_bonus.c     ft_lstiter_bonus.c           ft_lstmap_bonus.c       \
            \
            ft_dlstnew.c            ft_dlstadd_front.c          ft_dlstsize.c           \
            ft_dlstsize_full.c      ft_dlstlast.c               ft_dlstfirst.c          \
            ft_dlstadd_back.c       ft_dlstadd_after.c          ft_dlstdelone.c         \
            ft_dlstclear.c          ft_dlstiter.c               ft_dlstmap.c

OBJS    =   ${SRCS:.c=.o}
B_OBJS  =   ${B_SRCS:.c=.o}

SRCS_WD   =   $(addprefix ${FLDR_S},${SRCS})
SRCS_B_WD =   $(addprefix ${FLDR_S},${B_SRCS})
OBJS_WD   =   $(addprefix ${FLDR_O},${OBJS})
OBJS_B_WD =   $(addprefix ${FLDR_O},${B_OBJS})

FLAGS     =   -Wall -Wextra -Werror

all: $(FLDR_O) $(NAME)

$(FLDR_O):
		echo $(SRCS_WD)
		mkdir $(FLDR_O)

$(NAME): ${OBJS_WD} ${HEADER}
		ar rcs $(NAME) $?

clean:
		rm -rf ${OBJS_WD} ${OBJS_B_WD}

fclean: clean
		rm -rf ${NAME}

${FLDR_O}%.o : ${FLDR_S}%.c ${HEADER}
		$(CC) ${FLAGS} -c $< -o $@

re: fclean all

bonus:
		@make OBJS_WD="$(OBJS_B_WD)" all

.PHONY: all clean fclean re	bonus
