/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_app.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 00:00:00 by alcierra          #+#    #+#             */
/*   Updated: 2022/09/18 00:00:00 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	minishell(t_app *app, char *input);

int	init_app(t_app *app, int argc, char **argv, char **env)
{
	int		i;
	char	*cptr;

	app->welcome_message = "mini-shell $ ";
	app->env = init_env(env);
	if (!app->env)
		exit_alert("cannot allocate memory\n", ERROR_ENV_INIT);
	i = 1;
	while (i < argc)
	{
		cptr = ft_strnstr(argv[i], "=", ft_strlen(argv[i]));
		if (cptr)
		{
			*cptr = 0;
			if (ft_strncmp(argv[i], "path", 5) == 0)
				env_edit(app->env, "PATH", ft_strdup(cptr + 1));
			else if (ft_strncmp(argv[i], "execute", 5) == 0)
				minishell(app, cptr + 1);
			else if (ft_strncmp(argv[i], "welcome_message", 16) == 0)
				app->welcome_message = cptr + 1;
			else if (ft_strncmp(argv[i], "welcome_message_color", 22) == 0)
			{
				if (ft_strncmp(cptr + 1, "green", 6) == 0)
					app->welcome_message = "\033[0;32mmini-shell\033[0m $ ";
				else if (ft_strncmp(cptr + 1, "red", 4) == 0)
					app->welcome_message = "\033[0;31mmini-shell\033[0m $ ";
			}
		}
		i++;
	}
	return (0);
}
