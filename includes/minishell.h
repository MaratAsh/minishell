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

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# include <readline/readline.h>

struct	s_env_raw
{
	char	*path;
	char	**main;
};

struct	s_env
{
	char	**path;
};

typedef struct s_shell
{


	t_list	*command_list;
	char	*user_input;

	t_dlist	*env;


//	t_string welcome_message;
//	char	*destination;
//	char	*expression;
//	int 	argc;
//	char	**argv;
//	int 	process_count;
//	pid_t	*processes_id;
//	struct s_env_raw	env_raw;
//	struct s_env		env;
}				t_shell;

typedef struct s_lexema
{
	int		type;
	char	*value;
}	t_lexema;

enum lex_type
{
	WORD = 1,
	DOUBLE_Q = 2,
	SINGLE_Q = 3,
	PIPE = 4,
	BACK_SLASH = 6,
	REDIR_ = 5
};



t_shell *shell_data_init(int argc, char *argv[], char *env[]);
t_dlist *init_env(char **old_env);
t_list	*get_commands(char *user_input, t_dlist	*env);
t_dlist *lexer(char *user_input, t_dlist	*env);
t_list	*parser(t_dlist *lexer_tokens, t_dlist *env);



int	minishell_start(t_shell *shell);

#endif
