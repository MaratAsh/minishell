//
// Created by Altagracia Cierra on 9/18/22.
//

#include "minishell_parser.h"
#include "minishell.h"

int	execute_exec(t_tkn_exec *token, t_app *app)
{
	(void) app;
	if (ft_strncmp(token->argv[0], "exit", 4) == 0)
		exit(0);
	printf("exec token: first argument: %s\n", token->argv[0]);
	return (0);
}
