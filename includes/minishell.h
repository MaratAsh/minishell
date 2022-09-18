/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 00:00:00 by alcierra          #+#    #+#             */
/*   Updated: 2022/06/14 00:00:00 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

# include "libft.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# include <readline/readline.h>

typedef struct s_token
{
	int		type;
}	t_token;

typedef struct s_app
{
	t_list	*command_list;
	char	*user_input;

	t_dlist	*env;
}				t_app;

# define ERROR_APP_INIT 1
# define ERROR_ENV_INIT 2
# define ERROR_COMMAND_PARSE 3

# define EXEC  1
# define REDIR 2
# define PIPE  3
# define LIST  4
# define BACK  5

# define TOKEN_CMD 1
# define TOKEN_REDIR 2
# define TOKEN_PIPE 3
# define TOKEN_LIST 4
# define TOKEN_BACKGROUND 5
# define TOKEN_SINGLE_Q 6
# define TOKEN_DOUBLE_Q 7


// parser
t_token		*parser(char *input, t_app *app);

// executor
int			executor(t_token *token, t_app *app);

// utils
t_dlist		*init_env(char **old_env);
int			init_app(t_app *app, int argc, char **argv, char **env);
void		exit_alert(char *message, int code);

#endif
