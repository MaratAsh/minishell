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
	int		ret;

	ret = init_app(&app, argc, argv, env);
	if (ret)
		exit_alert("app initialization error", ERROR_APP_INIT);
	while (1)
	{
		ft_putendl_fd("mini-shell $ ", 1);
		user_input = readline(NULL);
		if (!user_input || *user_input == 0)
			continue ;
		tokens = parser(user_input, &app);
		if (!tokens)
			write(2, "command parse error\n", 20);
		executor(tokens, &app);
		ft_memset(user_input, 0, ft_strlen(user_input));
		free(user_input);
		free_token(tokens);
	}
	return (0);
}
