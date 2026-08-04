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

int		is_builtin(char *cmd)
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
	return (0);
}
