#include "minishell.h"

int	init_app(t_app *app, int argc, char **argv, char **env)
{
	(void) argc; (void) argv;
	app->env = init_env(env);
	if (!app->env)
		exit_alert("cannot allocate memory\n", ERROR_ENV_INIT);
	return (0);
}
