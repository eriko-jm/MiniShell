#include "../includes/minishell.h"

int	builtin_cd(char **argv)
{
    if (!argv[1])
    {
        chdir(getenv("HOME"));
        return (0);
    }
    if (chdir(argv[1]) < 0)
        perror("cd");
    return (0);
}

int	builtin_env(t_shell *shell)
{
	int		i;

	i = 0;
	while (shell->envp[i])
	{
		printf("%s\n", shell->envp[i]);
		i++;
	}
	return (0);
}
int	builtin_echo(char **argv)
{
	int		flag;
	int		i;

	if (argv[1] && ft_strcmp(argv[1], "-n") == 0)
	{
		i = 2;
		flag = 1;
	}
	else
	{
		i = 1;
		flag = 0;
	}
	while (argv[i])
	{
		printf("%s", argv[i]);
		if (argv[i + 1])
			printf(" ");
		i++;
	}
	if (flag == 0)
		printf("\n");
	return(0);
}

int	builtin_pwd(void)
{
	char buf[CWD_BUFFER_SIZE];

	if (getcwd(buf, sizeof(buf)))
		printf("%s\n", buf);
	return (0);
}

int	builtin_exit(char **argv, t_shell *shell)
{
	if (!argv[1])
	{
		printf("exit\n");
		exit(shell->last_status);
	}
	else
	{
		printf("exit\n");
		exit(ft_atoi(argv[1]));
	}
	return (0);
}

int	builtin_export(char **argv, t_shell *shell)
{
	int	i;
	t_env	*env;
	t_list	*node;
	t_env   *new_env;
	t_list  *new_node;

	node = shell->env;
	if (!argv[1])
	{
		while(node)
		{
			env = (t_env *)node->content;
			if (env->value && env->value[0] != '\0')
				printf("declare -x %s=\"%s\"\n", env->key, env->value);
			else
				printf("declare -x %s\n", env->key);
			node = node->next;
		}
	}
	else
	{
		i = 1;
		while(argv[i])
		{
			shell->envp = add_last_arr(shell->envp, argv[i]);
			new_env = malloc(sizeof(t_env));
			new_env->key = get_key(argv[i]);
			new_env->value = get_value(argv[i]);
			new_node = ft_lstnew(new_env);
			ft_lstadd_back(&shell->env, new_node);
			i++;
		}
	}
	return (0);
}

char	**redo_envp(t_shell *shell, char *argv)
{
	int	i;
	int	j;
	char **new;

	new = malloc(sizeof(char *) * count_arr(shell->envp));
	if(!new)
		return (NULL);
	i = 0;
	j = 0;
	while (shell->envp[i])
	{
		if (ft_strncmp(shell->envp[i], argv, ft_strlen(argv)) != 0)
		{
			new[j] = ft_strdup(shell->envp[i]);
			j++;
		}
		i++;
	}
	free_arr(shell->envp);
	return (new);
}

int	builtin_unset(char **argv, t_shell *shell)
{
	int	i;
	t_env	*env;
	t_list	*node;
	t_list	*temp;

	if (!argv[1] || !argv[1][0])
	return (0);
	else
	{
		i = 1;
		while (argv[i])
		{
			node = shell->env;
			if(ft_strcmp(((t_env *)node->content)->key, argv[i]) == 0)
			{
				shell->envp = redo_envp(shell, argv[i]);
				shell->env = node->next;
				free(node);
				node = shell->env;
				i++;
				continue ;
			}
			temp = node;
			while (node)
			{
				env = (t_env *)node->content;
				if (ft_strcmp(env->key, argv[i]) != 0)
				{
					temp = node;
					node = node->next;
				}
				else if (ft_strcmp(env->key, argv[i]) == 0)
				{
					temp->next = node->next;
					shell->envp = redo_envp(shell, argv[i]);
					free(node);
					break ;
				}
			}
			i++;
		}
	}
	return (0);
}

int	is_builtin(char *cmd)
{
	if (!cmd)
		return (0);
	if (!ft_strcmp(cmd, "cd") || !ft_strcmp(cmd, "pwd") ||
			!ft_strcmp(cmd, "echo") || !ft_strcmp(cmd, "exit") ||
			!ft_strcmp(cmd, "export") || !ft_strcmp(cmd, "unset") ||
			!ft_strcmp(cmd, "env"))
			return(1);
	else
		return(0);
}

int		execute_builtin(t_cmd *cmd, t_shell *shell)
{
	if (!ft_strcmp(cmd->argv[0], "echo"))
		return (builtin_echo(cmd->argv));
	if (!ft_strcmp(cmd->argv[0], "pwd"))
		return (builtin_pwd());
	if (!ft_strcmp(cmd->argv[0], "cd"))
		return (builtin_cd(cmd->argv));
	if (!ft_strcmp(cmd->argv[0], "env"))
		return (builtin_env(shell));
	if (!ft_strcmp(cmd->argv[0], "exit"))
		return (builtin_exit(cmd->argv, shell));
	if (!ft_strcmp(cmd->argv[0], "export"))
		return (builtin_export(cmd->argv, shell));
	if (!ft_strcmp(cmd->argv[0], "unset"))
		return (builtin_unset(cmd->argv, shell));
	return (0);
}
