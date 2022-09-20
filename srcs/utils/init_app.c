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

static void	init_app_params_execute(t_app *app, char *message)
{
	string_put_fd(&app->welcome_message, 1);
	ft_putendl_fd(message, 1);
	minishell(app, message);
}

static void	init_app_params_wmc(t_app *app, char *color)
{
	if (ft_strncmp(color, "green", 6) == 0)
		string_init(&app->welcome_message, "\033[0;32mmini-shell\033[0m $ ");
	else if (ft_strncmp(color, "red", 4) == 0)
		string_init(&app->welcome_message, "\033[0;31mmini-shell\033[0m $ ");
}

static int	init_app_params_env(t_app *app, char *key, char *value)
{
	char	*nvalue;
	char	*nkey;

	nvalue = malloc(ft_strlen(value) + 1);
	if (!nvalue)
		return (1);
	ft_strlcpy(nvalue, value, ft_strlen(value));
	if (env_edit(app->env, key, nvalue))
	{
		nkey = ft_strdup(key);
		if (!nkey)
		{
			free(nvalue);
			return (2);
		}
		env_insert(&app->env, nkey, nvalue);
	}
	return (0);
}

static int	init_app_params_process(t_app *app, int argc, char **argv)
{
	int		i;
	char	*cptr;

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
				init_app_params_execute(app, cptr + 1);
			else if (ft_strncmp(argv[i], "welcome_message", 16) == 0)
				string_init(&app->welcome_message, cptr + 1);
			else if (ft_strncmp(argv[i], "welcome_message_color", 22) == 0)
				init_app_params_wmc(app, cptr + 1);
			else if (ft_strncmp(argv[i], "env.", 4) == 0
				&& ft_strlen(argv[i]) > 5)
				init_app_params_env(app, argv[i] + 4, cptr + 1);
		}
		i++;
	}
	return (0);
}

int	init_app(t_app *app, int argc, char **argv, char **env)
{
	string_init(&app->welcome_message, "mini-shell $ ");
	app->env = init_env(env);
	if (!app->env)
		exit_alert("cannot allocate memory\n", ERROR_ENV_INIT);
	init_app_params_process(app, argc, argv);
	return (0);
}
