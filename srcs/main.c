/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 00:00:00 by alcierra          #+#    #+#             */
/*   Updated: 2022/06/28 00:00:00 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char *argv[], char *env[])
{
	t_app	app;
	char	*user_input;
	t_token	*tokens;
	int 	ret;

	ret = init_app(&app, argc, argv, env);
	if (ret)
		exit_alert("app initialization error", ERROR_APP_INIT);
	while (1)
	{
		ft_putendl_fd("mini-shell $ ", 1);
		user_input = readline(NULL);
		tokens = parser(user_input, &app);
		if (!tokens)
			exit_alert("command parse error", ERROR_COMMAND_PARSE);
		executor(tokens, &app);
	}
	return (0);
}
