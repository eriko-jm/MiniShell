#include "../includes/minishell.h"

char	*find_path(t_shell *shell)
{
	t_list	*node;
	t_env	*env_node;

	node = shell->env;
	while (node)
	{
		env_node = (t_env *)node->content;
		if (ft_strncmp(env_node->key, "PATH", 4) == 0)
			return (env_node->value);
		node = node->next;
	}
	return (NULL);
}

char	*get_path(t_cmd *cmd, t_shell *shell)
{
	char	*path;
	char	*temp_path;
	char	**temp;
	int		i;

	if (cmd->argv[0][0] == '/' || (cmd->argv[0][0] == '.' && cmd->argv[0][1] == '/'))
    	return (ft_strdup(cmd->argv[0]));
	temp = ft_split(find_path(shell), ':');
	if (!temp)
		return (NULL);
	i = 0;
	while (temp[i])
	{
		temp_path = ft_strjoin(temp[i], "/");
		path = ft_strjoin(temp_path, cmd->argv[0]);
		free(temp_path);
		if (path && access(path, X_OK) == 0)
		{
			free_arr(temp);
			return (path);
		}
		else
			free(path);
		i++;
	}
	free_arr(temp);
	return (NULL);
}
//function to fake the execution //TODO - only for testing, delete file
int	ft_execute(t_list *cmds, t_shell *shell)
{
	pid_t	pid;
	int		status;
	t_cmd	*temp;

	temp = cmds->content;
	temp->path = get_path(temp, shell);
	if (is_builtin(temp->argv[0]))
		return (execute_builtin(temp, shell));
	pid = fork();
	if (pid == 0)
	{
		if (!temp->path)
		{
			printf("command '%s' not found\n", temp->argv[0]);
			_exit(127);
		}
		execve(temp->path, temp->argv, shell->envp);
		perror("execve");
		_exit(127);
	}
	waitpid(pid, &status, 0);
	return (shell->last_status = WEXITSTATUS(status));
}
