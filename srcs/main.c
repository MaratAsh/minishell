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

int	minishell(t_app *app, char *input)
{
	t_token	*tokens;

	if (!input || *input == 0)
		return (1);
	tokens = parser(input, app);
	if (!tokens)
		write(2, "command parse error\n", 20);
	executor(tokens, app);
	free_token(tokens);
	return (0);
}

int	main(int argc, char *argv[], char *env[])
{
	t_app	app;
	char	*user_input;
	int		ret;

	ret = init_app(&app, argc, argv, env);
	if (ret)
		exit_alert("app initialization error", ERROR_APP_INIT);
	while (1)
	{
		ft_putendl_fd(app.welcome_message, 1);
		user_input = readline(NULL);
		ret = minishell(&app, user_input);
		if (ret == 1)
			continue ;
		ft_memset(user_input, 0, ft_strlen(user_input));
		free(user_input);
	}
	return (0);
}
