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


# define MAXARGS 100

typedef struct s_token
{
	int		type;
}	t_token;

typedef struct s_token_exec {
	int		type;
	char	*argv[MAXARGS];
	char	*eargv[MAXARGS];
}		t_tkn_exec;

typedef struct s_token_redirect
{
	int			type;
	t_token		*token;
	char		*file;
	char		*efile;
	int			mode;
	int			fd;
}	t_tkn_redir;

typedef struct s_token_pipe {
	int		type;
	t_token	*left;
	t_token	*right;
}			t_tkn_pipe;

typedef struct s_token_list {
	int		type;
	t_token	*left;
	t_token	*right;
}			t_tkn_list;

typedef struct s_token_back {
	int		type;
	t_token	*token;
}			t_tkn_back;


typedef struct s_app
{
	t_list	*command_list;
	char	*user_input;
	int		exit_status;
	t_token	*current;
	t_dlist	*env;
}				t_app;

# define ERROR_APP_INIT 1
# define ERROR_ENV_INIT 2
# define ERROR_COMMAND_PARSE 3
# define ERROR_FORK 4
# define ERROR_SYNTAX 5
# define ERROR_PARSE_BLOCK 6
# define ERROR_SYNTAX_MISSING_RPAR 7
# define ERROR_REDIR_FILE_MISSING 8
# define ERROR_TOO_MANY_ARGS 9


# define TOKEN_EXEC 1
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
int			free_token(t_token *tkn);

#endif
