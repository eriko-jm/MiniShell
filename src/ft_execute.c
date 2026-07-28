#include "../includes/minishell.h"


//function to fake the execution //TODO - only for testing, delete file
int	ft_execute(t_list *cmds, t_shell *shell)
{
	print_cmd_list(cmds);
	return (shell->last_status + 1);
}
