#include "../includes/minishell.h"


//function to fake the execution //TODO - only for testing, delete file
int	ft_execute(t_list *cmds, t_shell *shell)
{
	print_expanded_cmd_list(cmds);
	shell->last_status += 1;
	return (shell->last_status);
}
