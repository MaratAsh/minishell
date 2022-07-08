#include "minishell.h"

t_shell * shell_data_init(int argc, char *argv[], char *env[])
{
	t_shell	*shell_data;

	shell_data = (t_shell *) malloc(sizeof(t_shell));
	if (!shell_data)
		return (NULL);

	shell_data->env = init_env(env);
	if (!shell_data->env)
		return (NULL);


//	shell_data->expression = NULL;
//	shell_data->argc = argc;
//	shell_data->argv = argv;
//	shell_data->env_raw.main = env;
//	shell_data->process_count = 0;
//	shell_data->processes_id = NULL;
//	string_init(&(shell->welcome_message), "mini-shell $ ");
	return (shell_data);
}
